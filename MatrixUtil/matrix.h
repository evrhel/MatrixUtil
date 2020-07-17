#pragma once

#ifndef MATRIX_H
#define MATRIX_H

/* LU :         returns psycologoically LU matrices (permutation information lost
   LUP :        returns LU matrices plus row permutation matrix.  PA = LU.
   LUp :        returns LU matrices plus row permutation vector.  A(p,:) = LU.
   LUPQ :       returns LU matrices plus row and column permutation matrices.  PAQ = LU.
   LUpq :       returns LU matrices plus row and column permutation vectors.  A(p,q) = LU.
   LUCompact :  returns LU matrix in compact form (LU case but compact)  */
enum LU_type { LUCompact, LU, LUP, LUp, LUPQ, LUpq };

#define EPSILON 0.0000000000001

class matrix
{
private:
    int ncols;
    int nrows;
    int total;
    float **row_ptr;
    float **col_ptr;
    float *elements;
    int rc;

    void allocate(int rows, int cols);
    void dealloc();
    void null_matrix();

    /* Internal work methods */
    static matrix* gauss_drop(matrix *x);
    static matrix* gauss_app_drop(matrix *C, matrix *t);
    static void copy_row(matrix *src, matrix *des, int row_src, int row_des);
    static void copy_column(matrix *src, matrix *des, int col_src, int col_des);
    static void copy_diagonal(matrix* src, matrix* des, int row, int col);
    static matrix* matrix_row_perm_matrix_to_vector(matrix* pmat);
    static matrix* matrix_col_perm_matrix_to_vector(matrix* pmat);

public:
    /* Methods that create new matrices */
    static matrix* matrix_from_array(float *input, int n_rows, int n_cols);
    static matrix* matrix_identity(int size);
    static matrix* matrix_invert(matrix *a);
    static matrix* matrix_forward_sub(matrix* l, matrix* b);
    static matrix* matrix_backward_sub(matrix* u, matrix* y, bool *ok);
    static matrix* matrix_copy(matrix *a);
    static matrix* matrix_get_row(matrix *a, int row);
    static matrix* matrix_get_col(matrix *a, int col);
    static matrix* matrix_get_sub_matrix(matrix *a, int r_start, int r_end, int c_start, int c_end);
    static matrix* matrix_get_upper_triag(matrix *a, int i);
    static matrix* matrix_get_lower_triag(matrix *a, int i);
    static matrix* matrix_set_diag(matrix* a);

    /* return multiple matrices (decomposition methods) */
    static matrix** matrix_lu(matrix *a, LU_type type); /* l and u */

                                                        
    /* Methods that update current object */
    void fill(float val);
    void put_sub_matrix(matrix *a, int r_start, int c_start);
    void swap_column(int i, int k);
    void swap_row(int i, int k);

    /* Decomposition methods */

    /* Determinate, Rank, Condition Number */

    /* Access methods */
    void    get_col(int col, float *output);
    void    get_row(int row, float *output);
    void    get_elements(float *output);
    float  get_element(int row, int col);
    int     get_num_rows();
    int     get_num_cols();
    float  get_max(int *i, int *j);

    /* Instantiate and intitialize methods */
    matrix();
    matrix(int rows, int cols);
    void set_row(int row, float *data);
    void set_col(int col, float *data);
    void set_row_drop(int row, matrix *data);
    void set_col_drop(int col, matrix *data);
    void set_row(int row, matrix *data);
    void set_col(int col, matrix *data);
    void set_element(int row, int col, float data);
    void get_size(int *num_row, int *num_col);

    /* Display */
    void display(const char *str);
    void display_subrange(int row_start, int row_end, int col_start, int col_end);
    void display_diagonal();

    /* Reference counting */
    void drop();
    void keep();

    /* Debug leak checker */
#if _DEBUG
    static void mem_check(char *input_str);
#endif
};

#endif