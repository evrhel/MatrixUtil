#include "matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/* Crude method to catch leaks */
#if _DEBUG
#define M_MAX 1000
matrix *m_allocated[M_MAX];
int     m_count = 0;
#endif

static float sign(float input)
{
    if (input < 0)
        return -1;
    if (input > 0)
        return 1;
    return 0;
}
/* Private methods */
void matrix::allocate(int rows, int cols)
{
    int k;

    if (rows < 1 || cols < 1)
        throw "Matrix size must be positive\n";
    elements = (float*) malloc(sizeof(float) * rows * cols);
    row_ptr = (float**) malloc(sizeof(void*) * rows);
    col_ptr = (float**) malloc(sizeof(void*) * cols);
    if (elements == NULL || row_ptr == NULL || col_ptr == NULL)
        throw "Matrix allocation failed\n";
    memset(elements, 0, sizeof(float) * rows * cols);
    for (k = 0; k < rows; k++)
        row_ptr[k] = &(elements[k]);
    for (k = 0; k < cols; k++)
        col_ptr[k] = &(elements[k * rows]);
    nrows = rows;
    ncols = cols;
    total = rows * cols;
    rc = 1;
#if _DEBUG
    if (m_count < M_MAX)
    {
        m_allocated[m_count] = this;
        m_count++;
    }
#endif
}

void matrix::dealloc()
{
    if (rc != 0)
        throw "Ref count not zero during deallocation\n";
    if (elements != NULL)
        free(elements);
    if (row_ptr != NULL)
        free(row_ptr);
    if (col_ptr != NULL)
        free(col_ptr);
#if _DEBUG
    bool found = false;
    for (int k = 0; k < m_count; k++)
    {
        if (m_allocated[k] == this)
            found = true;
        if (found)
            m_allocated[k] = m_allocated[k + 1];
    }
    if (found)
        m_count--;
#endif
    delete this;
}

#if _DEBUG
void  matrix::mem_check(char *input_str)
{
    int k;
    fprintf(stdout, "\r\n");
    fprintf(stdout, input_str);
    fprintf(stdout, "\r\n");
    if (m_count == 0)
    {
        fprintf(stdout, "Memory clear\n");
        return;
    }

    fprintf(stdout, "%d matrices allocated\r\n", m_count);
    for (k = 0; k < m_count; k++)
        fprintf(stdout, "m_allocated[%d] = 0x%p\r\n", k, m_allocated[k]);
}
#endif

void matrix::null_matrix()
{
    ncols = 0;
    nrows = 0;
    row_ptr = NULL;
    col_ptr = NULL;
    elements = NULL;
}

/* Private methods used internally */



/* Golub and Van Loan gauss function */
matrix* matrix::gauss_drop(matrix *x)
{
    matrix *t = new matrix(x->nrows - 1, 1);
    int k;
    float val = x->get_element(0, 0);

    if (val == 0)
        throw("Error in gauss function\n");

    for (k = 0; k < t->nrows; k++)
        t->set_element(k, 0, x->get_element(k + 1, 0) / val);
    x->drop();
    return t;
}

/* Golub and Van Loan gauss.app function */
matrix* matrix::gauss_app_drop(matrix *C, matrix *t)
{
    matrix *Cout = matrix_copy(C);
    int k, j;

    for (k = 0; k < C->ncols; k++)
        for (j = 1; j < C->nrows; j++)
        {
            float t1 = C->get_element(j, k);
            float t2 = t->get_element(j - 1, 0);
            float t3 = C->get_element(0, k);
            float t4 = t1 - t2 * t3;
            Cout->set_element(j, k, C->get_element(j, k) - t->get_element(j - 1, 0) * C->get_element(0, k));
        }
    C->drop();
    t->drop();
    return Cout;
}

/* Worker operator for copying a row vector from one matrix to another */
void matrix::copy_row(matrix *src, matrix *des, int row_src, int row_des)
{
    matrix *row;

    if (src->ncols != des->ncols)
        throw("Error in copy row\n");

    row = matrix_get_row(src, row_src);
    des->set_row_drop(row_des, row);
}

/* Worker operator for copying a column vector from one matrix to another */
void matrix::copy_column(matrix *src, matrix *des, int col_src, int col_des)
{
    matrix *col;

    if (src->ncols != des->ncols)
        throw("Error in copy column\n");

    col = matrix_get_col(src, col_src);
    des->set_col_drop(col_des, col);
}

/* Worker operator for changing row permutation matrix to permutation vector */
matrix* matrix::matrix_row_perm_matrix_to_vector(matrix* pmat)
{
    int k, j;
    matrix* pvec = new matrix(pmat->nrows, 1);

    for (k = 0; k < pmat->nrows; k++)
        for (j = 0; j < pmat->ncols; j++)
            if (pmat->get_element(k, j) == 1)
                pvec->set_element(k, 0, j);
    return pvec;
}

/* Worker operator for changing col permutation matrix to permutation vector */
matrix* matrix::matrix_col_perm_matrix_to_vector(matrix* pmat)
{
    int k, j;
    matrix* pvec = new matrix(pmat->ncols, 1);

    for (k = 0; k < pmat->ncols; k++)
        for (j = 0; j < pmat->nrows; j++)
            if (pmat->get_element(j, k) == 1)
                pvec->set_element(k, 0, j);
    return pvec;
}

/* Worker operator for getting diagonal entries */
void matrix::copy_diagonal(matrix* src, matrix* des, int row, int col)
{
    bool done = false;

    while (!done)
    {
        des->set_element(row, col, src->get_element(row, col));
        row++;
        col++;
        if (row == src->nrows || col == src->ncols)
            done = true;
    }
}



/* Static Methods */
matrix* matrix::matrix_from_array(float *input, int n_rows, int n_cols)
{
    matrix *m = new matrix(n_rows, n_cols);

    memcpy(m->elements, input, m->total * sizeof(float));
    return m;
}

matrix* matrix::matrix_set_diag(matrix* a)
{
    int j;
    int max_a_dim = a->ncols > a->nrows ? a->ncols : a->nrows;
    int min_a_dim = a->ncols > a->nrows ? a->nrows : a->ncols;
    if (min_a_dim != 1)
        throw "Input matrix must be a vector\n";
    matrix* m = new matrix(max_a_dim, max_a_dim);

    for (j = 0; j < max_a_dim; j++)
        m->set_element(j, j, a->elements[j]);
    return m;
}

matrix* matrix::matrix_identity(int size)
{
    matrix *d = new matrix(size, 1);
    d->fill(1.0);

    matrix *m = matrix_set_diag(d);
    d->drop();
    return m;
}

/* U * x = y   U is upper trianglular matrix.  y is a vector.
   We are finding x.  This is used in solving for the inverse */
matrix* matrix::matrix_backward_sub(matrix* u, matrix* y, bool *ok)
{
    int i, j;
    float alpha;
    float denom;
    
    *ok = true;
    
    if (u->ncols != u->ncols)
        throw "Inverse only valid for square matrix\n";

    matrix* x = new matrix(u->ncols, 1);

    for (i = u->ncols - 1; i >= 0; i--)
    {
        alpha = y->get_element(i, 0);

        for (j = i; j < u->ncols; j++)
        {
            alpha -= (x->get_element(j, 0) * u->get_element(i, j));
        }

        denom = u->get_element(i, i);
        if (denom == 0)
        {
            alpha = NAN;
            *ok = false;
        }
        else
        {
            alpha /= denom;
        }
        x->set_element(i, 0, alpha);
    }
    return x;
}

/* L * y = b   L is unit lower trianglular matrix.  b is a vector.
   We are finding y.  This is used in solving for the inverse */
matrix* matrix::matrix_forward_sub(matrix* l, matrix* b)
{
    if (l->ncols != l->ncols)
        throw "Inverse only valid for square matrix\n";

    int i, j;
    float alpha;

    matrix* y = new matrix(l->ncols, 1);

    for (i = 0; i < l->ncols; i++)
    {
        alpha = b->get_element(i, 0);

        for (j = 0; j < i; j++)
        {
            alpha -= (y->get_element(j, 0) * l->get_element(i, j));
        }
        y->set_element(i, 0, alpha);
    }
    return y;
}

matrix* matrix::matrix_invert(matrix *a)
{
    if (a->ncols != a->ncols)
        throw "Inverse only valid for square matrix\n";

    matrix** lu;
    matrix *l, *u, *y_vec, *inv_vec, *p;
    matrix *inv = new matrix(a->nrows, a->ncols);
    matrix *e_vec = new matrix(a->nrows, 1);
    bool ok;

    int k;

    /* Step one.  Do the LU decomposition
       so L is lower triangular with 1's on
       the diagonal.  u is upper triangular.
       p is a permutation vector, which tells
       how the columns had to be reordered to
       get the decomposition */
    lu = matrix::matrix_lu(a, LU_type::LUp);
    l = lu[0];
    u = lu[1];
    p = lu[2];


    /* Now solve a forward and a backward substitution
       for each column.  Store the reult in the
       inverse matrix column indicated by the permuation
       matrix */
    for (k = 0; k < a->ncols; k++)
    {
        /* LU * inv(M) = I 
           L * yi = ei, do the forward substitution
           to get each yi */

        /* Create one column of indentity matrix */
        e_vec->fill(0);
        e_vec->set_element(k, 0, 1);

        /* Solve L * yi = ei for yi */
        y_vec = matrix::matrix_forward_sub(l, e_vec);

        /* Now find column of inv(M) = N via back sub 
           U * ni = yi */
        inv_vec = matrix::matrix_backward_sub(u, y_vec, &ok);
        
        /* permutation p needed to get LU decomp. */
        inv->set_col((int) p->get_element(k,0), inv_vec);
        y_vec->drop();
        inv_vec->drop();
    }

    e_vec->drop();
    l->drop();
    u->drop();
    p->drop();

    if (!ok)
    {
        inv->drop();
        return NULL;
    }
    return inv;
}

matrix* matrix::matrix_copy(matrix *a)
{
    matrix *m = new matrix(a->nrows, a->ncols);

    memcpy(m->elements, a->elements, a->ncols * a->nrows * sizeof(float));
    return m;
}

matrix* matrix::matrix_get_row(matrix *a, int row)
{
    matrix *m = new matrix(1, a->nrows);
    int k;
    float *rowp = a->row_ptr[row];

    for (k = 0; k < a->ncols; k++)
        m->elements[k] = rowp[k * a->nrows];
    return m;
}

matrix* matrix::matrix_get_col(matrix *a, int col)
{
    matrix *m = new matrix(a->nrows, 1);
    memcpy(m->elements, a->col_ptr[col], a->nrows * sizeof(float));
    return m;
}

matrix* matrix::matrix_get_sub_matrix(matrix *a, int r_start, int r_end, int c_start, int c_end)
{
    if (r_end < r_start || c_end < c_start)
        throw "End index can't be smaller than start index\n";
    if (r_end < 0 || c_end < 0 || r_start < 0 || c_start < 0)
        throw "Index can't be smaller than zero";
    if (r_end > a->nrows - 1 || c_end > a->ncols -1)
        throw "Index can't be larger than source matrix\n";

    int nrows = r_end - r_start + 1;
    int ncols = c_end - c_start + 1;
    int j, k;

    matrix *m = new matrix(nrows, ncols);
    for (k = 0; k < ncols; k++)
        for (j = 0; j < nrows; j++)
            m->set_element(j, k, a->get_element(j + r_start, k + c_start));
    return m;
}

/* Value of i will indicate number of diag entries to return. Must be from 1
   to ncols + nrows - 1 */
matrix* matrix::matrix_get_upper_triag(matrix *a, int i)
{
    if (i < 0 || i > a->nrows + a->ncols - 1)
        throw "Get upper triangle had improper indexing\n";

    matrix *m = new matrix(a->nrows, a->ncols);
    int k, count = 0;
    bool done = false;

    /* No entries */
    if (i == 0)
        return m;

    /* All the entries */
    if (i == a->nrows + a->ncols - 1)
    {
        m->drop();
        m = matrix_copy(a);
        return m;
    }

    /* First step through the column index backwards */
    for (k = a->ncols - 1; k > -1; k--)
    {
        copy_diagonal(a, m, 0, k);
        count++;
        if (count == i)
        {
            done = true;
            break;
        }
    }
    if (done)
        return m;

    /* Now start with the second row */
    for (k = 1; k < a->nrows - 1; k++)
    {
        copy_diagonal(a, m, k, 0);
        count++;
        if (count == i)
            break;
    }
    return m;
}

/* Value of i will indicate number of diag entries to return. Must be from 1
   to ncols + nrows - 1 */
matrix* matrix::matrix_get_lower_triag(matrix *a, int i)
{
    if (i < 0 || i > a->nrows + a->ncols - 1)
        throw "Get lower triangle had improper indexing\n";

    matrix *m = new matrix(a->nrows, a->ncols);
    int k, count = 0;
    bool done = false;

    /* No entries */
    if (i == 0)
        return m;

    /* All the entries */
    if (i == a->nrows + a->ncols - 1)
    {
        m->drop();
        m = matrix_copy(a);
        return m;
    }

    /* First step through the row index backwards */
    for (k = a->nrows - 1; k > -1; k--)
    {
        copy_diagonal(a, m, k, 0);
        count++;
        if (count == i)
        {
            done = true;
            break;
        }
    }
    if (done)
        return m;

    /* Now start with the second column */
    for (k = 1; k < a->ncols - 1; k++)
    {
        copy_diagonal(a, m, 0, k);
        count++;
        if (count == i)
            break;
    }
    return m;
}

/* Decomposition methods, return multiple matrices */


/* Gaussian elimination with complete pivoting. PAQ = LU
   or partial pivoting PA = LU.  Also compact forms. See LU_type for details */
matrix** matrix::matrix_lu(matrix *a_in, LU_type type)
{
    int k;
    matrix *sub1, *sub2, *col, *t;
    int i, j;
    float maxval;
    matrix *a = matrix_copy(a_in);
    matrix *pvec = new matrix(a_in->ncols, 1);
    matrix *qvec = new matrix(a_in->nrows, 1);
    matrix *pmat = NULL, *qmat = NULL, *l, *u;
    matrix **out;
    int size;
    int nrows = a_in->nrows;
    int ncols = a_in->ncols;
    int diag_count = (nrows < ncols ? nrows : ncols);
    int count = (nrows - 1 < ncols ? nrows - 1 : ncols);
    int rank = 0;

    /* Set up for different output formats*/
    switch (type)
    {
        case LUCompact:
            size = 1;
            break;
        case LU:
            size = 2;
            break;
        case LUP:
        case LUp:
            pmat = matrix::matrix_identity(nrows);
            size = 3;
            break;
        case LUPQ:
        case LUpq:
        default:
            pmat = matrix::matrix_identity(nrows);
            qmat = matrix::matrix_identity(ncols);
            size = 4;
            break;
    }
    out = (matrix**)malloc(sizeof(matrix*) * size);

    try
    {
        for (k = 0; k < count; k++)
        {
            /* Find the indices of the largest absolute value in the submatrix */
            sub1 = matrix_get_sub_matrix(a, k, nrows - 1, k, ncols - 1);
          //  sub1->display("sub1");
            maxval = sub1->get_max(&i, &j);
            sub1->drop();

            /* We always do row swaps. We might not save the pivots.  Also, we
               may or may not do the column swaps, but always save the pivots
               when we do */
            i = i + k;
            a->swap_row(i, k);
            if (!(type == LUCompact || type == LU))
                pvec->set_element(k, 0, i);

            if (type == LUPQ || type == LUpq)
            {
                j = j + k;
                a->swap_column(j, k);
                qvec->set_element(k, 0, j);
            }

           // a->display("swapped");
            /* If diagonal not zero then do Guassian elimination.  Should be
               a tolerance */
            if (a->get_element(k, k) != 0)
            {
                rank++;
                col = matrix_get_sub_matrix(a, k, nrows - 1, k, k);
               // col->display("col");
                t = gauss_drop(col);
              //  t->display("t");
                a->put_sub_matrix(t, k + 1, k);
               // a->display("Post t");

                /* Check if we are in the last column (non-square case) */
                if (k + 1 < ncols)
                {
                    sub1 = matrix_get_sub_matrix(a, k, nrows - 1, k + 1, ncols - 1);
                   // sub1->display("sub1");
                    sub2 = gauss_app_drop(sub1, t);
                   // sub2->display("sub2");
                    a->put_sub_matrix(sub2, k, k + 1);
                   // a->display("post_sub");
                    sub2->drop();
                }
            }
        }
    }
    catch (char const* err)
    {
        fprintf(stderr, err);
        throw "LU algorithm core failed\n";
    }

    /* Output formats */
    try
    {
        if (type == LUCompact)
        {
            out[0] = a;
            pvec->drop();
            qvec->drop();
            return out;
        }

        l = matrix_get_lower_triag(a, nrows - 1);
        u = matrix_get_upper_triag(a, ncols);
        for (k = 0; k < diag_count; k++)
            l->set_element(k, k, 1);

        /* We may need to drop some rows or columns */
        if (nrows < ncols)
        {
            /* L is nrows x nrows; U is nrows x ncols */
            matrix *l_temp = new matrix(nrows, nrows);
            for (k = 0; k < nrows; k++)
                copy_column(l, l_temp, k, k);
            l->drop();
            l = l_temp;
        }
        else if (nrows > ncols)
        {
            /* L is nrows x ncols; U is ncols x ncols */
            matrix *u_temp = new matrix(ncols, ncols);
            for (k = 0; k < ncols; k++)
                copy_row(u, u_temp, k, k);
            u->drop();
            u = u_temp;
        }
        out[0] = l;
        out[1] = u;
        a->drop();

        if (type == LU)
        {
            pvec->drop();
            qvec->drop();
            return out;
        }

        /* The permutations.  Need to organize this differently */
        switch (type)
        {
        case LUP:
            for (k = 0; k < nrows; k++)
                if (k < nrows - 1)
                    pmat->swap_row(k, (int)pvec->get_element(k, 0));
            out[2] = pmat;
            pvec->drop();
            qvec->drop();
            break;
        case LUp:
            for (k = 0; k < nrows; k++)
                if (k < nrows - 1)
                    pmat->swap_row(k, (int)pvec->get_element(k, 0));
            pvec->drop();
            pvec = matrix_row_perm_matrix_to_vector(pmat);
            pmat->drop();
            out[2] = pvec;
            qvec->drop();
            break;
        case LUPQ:
            for (k = 0; k < nrows; k++)
                if (k < nrows - 1) {
                    pmat->swap_row(k, (int)pvec->get_element(k, 0));
                    qmat->swap_column(k, (int)qvec->get_element(k, 0));
                }
            out[2] = pmat;
            out[3] = qmat;
            pvec->drop();
            qvec->drop();
            break;
        case LUpq:
        default:
            for (k = 0; k < nrows; k++)
                if (k < nrows - 1) {
                    pmat->swap_row(k, (int)pvec->get_element(k, 0));
                    qmat->swap_column(k, (int)qvec->get_element(k, 0));
                }
            pvec->drop();
            pvec = matrix_row_perm_matrix_to_vector(pmat);
            pmat->drop();
            out[2] = pvec;
            qvec->drop();
            qvec = matrix_col_perm_matrix_to_vector(qmat);
            qmat->drop();
            out[3] = qvec;
            break;
        }

    }
    catch (char const* err)
    {
        fprintf(stderr, err);
        throw "LU algorithm formatter failed\n";
    }
    return out;
}


void matrix::fill(float val)
{
    int k;

    for (k = 0; k < total; k++)
        elements[k] = val;
}

void matrix::put_sub_matrix(matrix *a, int r_start, int c_start)
{
    int j, k;

    if (r_start < 0 || c_start < 0)
        throw("Starting index cannot be negative\n");
    if (r_start + a->nrows > nrows || c_start + a->ncols > ncols)
        throw("Submatrix too large to fit at this location\n");

    for (j = 0; j < a->ncols; j++)
        for (k = 0; k < a->nrows; k++)
            set_element(k + r_start, j + c_start, a->get_element(k, j));
}



void matrix::swap_column(int i, int k)
{
    if (i < 0 || i > this->ncols - 1 || k < 0 || k > this->ncols - 1)
        throw("Illegal index in column row\n");

    if (i == k)
        return;
    matrix *col_i = matrix_get_col(this, i);
    matrix *col_k = matrix_get_col(this, k);
    this->set_col(k, col_i);
    this->set_col(i, col_k);
    col_i->drop();
    col_k->drop();
}

void matrix::swap_row(int i, int k)
{
    if (i < 0 || i > this->nrows - 1 || k < 0 || k > this->nrows - 1)
        throw("Illegal index in swap row\n");

    if (i == k)
        return;
    matrix *row_i = matrix_get_row(this, i);
    matrix *row_k = matrix_get_row(this, k);
    this->set_row(k, row_i);
    this->set_row(i, row_k);
    row_i->drop();
    row_k->drop();
}


/* Access methods to float externally allocated memory */
void matrix::get_col(int col, float *output)
{
    memcpy(output, col_ptr[col], nrows * sizeof(float));
}

void matrix::get_row(int row, float *output)
{
    int k;
    float *rowp = row_ptr[row];

    for (k = 0; k < ncols; k++)
        output[k] = rowp[k * nrows];
}

void matrix::get_elements(float *output)
{
    memcpy(output, elements, total * sizeof(float));
}

float matrix::get_element(int row, int col)
{
    return elements[row + col * nrows];
}

int matrix::get_num_rows()
{
    return nrows;
}

int matrix::get_num_cols()
{
    return ncols;
}

float matrix::get_max(int *i, int *j)
{
    int k;
    float val;

    val = -HUGE_VAL;
    *i = 0;
    *j = 0;
    for (k = 0; k < total; k++)
        if (elements[k] > val)
        {
            val = elements[k];
            *i = k % this->nrows;
            *j = (int) floor((float) k / (float) this->nrows);
        }
    return val;
}

/* Instantiate and intitialize methods */
matrix::matrix()
{
    null_matrix();
}

matrix::matrix(int rows, int cols)
{
    allocate(rows, cols);
}

void matrix::set_row(int row, float *data)
{
    int k;

    if (row < 0 || row >= nrows)
        throw "Index outside of matrix\n";
    for (k = 0; k < ncols; k++)
        elements[k * nrows + row] = data[k];
}

void matrix::set_row(int row, matrix *data)
{
    int k;

    if (row < 0 || row >= nrows)
        throw "Index outside of matrix\n";
    if (data->total < ncols)
        throw "Source data too small\n";
    for (k = 0; k < ncols; k++)
        elements[k * nrows + row] = data->elements[k];
}

void matrix::set_row_drop(int row, matrix *data)
{
    set_row(row, data);
    data->drop();
}

void matrix::set_col(int col, float *data)
{
    int k;

    if (col < 0 || col >= ncols)
        throw "Index outside of matrix\n";
    for (k = 0; k < nrows; k++)
        elements[col * nrows + k] = data[k];
}

void matrix::set_col(int col, matrix *data)
{
    int k;

    if (col < 0 || col >= ncols)
        throw "Index outside of matrix\n";
    if (data->total < nrows)
        throw "Source data too small\n";
    for (k = 0; k < nrows; k++)
        elements[col * nrows + k] = data->elements[k];
}

void matrix::set_col_drop(int col, matrix *data)
{
    set_col(col, data);
    data->drop();
}

void matrix::set_element(int row, int col, float data)
{
    if (row < 0 || row >= nrows || col < 0 || col >= ncols)
        throw "Index outside of matrix\n";
    elements[col * nrows + row] = data;
}

void matrix::get_size(int *num_row, int *num_col)
{
    *num_row = nrows;
    *num_col = ncols;
}


/* Display */
void matrix::display(const char *str)
{
    int k, j;

    fprintf(stdout, "\r\n------------");
    if (str != NULL)
        fprintf(stdout, "\r\n %s = \r\n", str);

    for (k = 0; k < nrows; k++)
    {
        fprintf(stdout, "\r\n");
        for (j = 0; j < ncols; j++)
            fprintf(stdout, "%lf ", get_element(k, j));
        fprintf(stdout, "\r\n");
    }
}

void matrix::display_subrange(int r_start, int r_end, int c_start, int c_end)
{
    if (r_end < r_start || c_end < c_start)
        throw "End index can't be smaller than start index\n";
    if (r_end < 0 || c_end < 0 || r_start < 0 || c_start < 0)
        throw "Index can't be smaller than zero\n";
    if (r_end > nrows - 1 || c_end > ncols - 1)
        throw "Index can't be larger than source matrix\n";

    int num_rows = r_end - r_start + 1;
    int num_cols = c_end - c_start + 1;
    int k, j;

    fprintf(stdout, "\r\n------------");
    for (k = 0; k < num_rows; k++)
    {
        fprintf(stdout, "\r\n");
        for (j = 0; j < num_cols; j++)
            fprintf(stdout, "%lf ", get_element(k + r_start, j + c_start));
        fprintf(stdout, "\r\n");
    }
}

void matrix::display_diagonal()
{
    if (ncols != nrows)
        throw "Can only display diagonal of square matrices\n";

    int k;

    fprintf(stdout, "\r\n------------");

    fprintf(stdout, "\r\n");
    for (k = 0; k < nrows; k++)
            fprintf(stdout, "%lf ", get_element(k, k));
    fprintf(stdout, "\r\n");
}

/* Ref counting */
void matrix::drop()
{
    rc--;
    if (rc == 0)
        dealloc();
}

void matrix::keep()
{
    rc++;
}



