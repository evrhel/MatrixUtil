#include "fmat_math.h"
#include "matrix.h"

#include <memory>

using namespace mutil;

Matrix2 mutil::inverse(Matrix2 const &mat2, bool *exists)
{
	matrix *mat = matrix::matrix_from_array((float *)&mat2, 2, 2);
	matrix *inv = matrix::matrix_invert(mat);
	delete mat;
	if (inv == NULL)
	{
		if (exists)
			*exists = false;
		delete inv;
		return mat2;
	}
	else
	{
		if (exists)
			*exists = true;
		Matrix2 result;
		inv->get_elements((float *)&result);
		delete inv;
		return result;
	}
}

Matrix3 mutil::inverse(Matrix3 const &mat3, bool *exists)
{
	matrix *mat = matrix::matrix_from_array((float *)&mat3, 3, 3);
	matrix *inv = matrix::matrix_invert(mat);
	delete mat;
	if (inv == NULL)
	{
		if (exists)
			*exists = false;
		delete inv;
		return mat3;
	}
	else
	{
		if (exists)
			*exists = true;
		Matrix3 result;
		inv->get_elements((float *)&result);
		delete inv;
		return result;
	}
}

Matrix4 mutil::inverse(Matrix4 const &mat4, bool *exists)
{
	matrix *mat = matrix::matrix_from_array((float *)&mat4, 4, 4);
	matrix *inv = matrix::matrix_invert(mat);
	delete mat;
	if (inv == NULL)
	{
		if (exists)
			*exists = false;
		delete inv;
		return mat4;
	}
	else
	{
		if (exists)
			*exists = true;
		Matrix4 result;
		inv->get_elements((float *)&result);
		delete inv;
		return result;
	}
}
