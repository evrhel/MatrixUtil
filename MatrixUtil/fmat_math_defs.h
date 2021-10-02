/*!
\file
This file contains macros used in fmat_math.h to cut
down on copy constructor calls for matrices during
expensive matrix operations.
*/

#pragma once

#ifndef FMAT_MATH_DEFS_H
#define FMAT_MATH_DEFS_H

#include "mat_types.h"

// 2x2 determinant
#define __determinant2x2(	\
	_11, _12,				\
	_21, _22				\
)							\
	(_11 * _22 - _12 * _21) \

// 2x2 transpose matrix
#define __transpose2x2(		\
	_11, _12,				\
	_21, _22				\
)							\
	mutil::Matrix2(			\
		_11, _21,			\
		_12, _22			\
)

// 2x2 cofactor matrix
#define __cofactor2x2(	\
	_11, _12,			\
	_21, _22			\
)						\
mutil::Matrix2(			\
	_22, -_21,			\
	-_12, _11			\
)

// 2x2 adjugate matrix
#define __adjugate2x2(	\
	_11, _12,			\
	_21, _22			\
)						\
	mutil::transpose(	\
	__cofactor2x2(		\
		_11, _12,		\
		_21, _22		\
	))


// 3x3 determinant
#define __determinant3x3(	\
	_11, _12, _13,			\
	_21, _22, _23,			\
	_31, _32, _33			\
)							\
(							\
	_11 * __determinant2x2(_22, _23, _32, _33) -	\
	_12 * __determinant2x2(_21, _23, _31, _33) +	\
	_13 * __determinant2x2(_21, _22, _31, _32)		\
)

// 3x3 transpose matrix
#define __transpose3x3(		\
	_11, _12, _13,			\
	_21, _22, _23,			\
	_31, _32, _33			\
)							\
mutil::Matrix3(				\
	_11, _21, _31,			\
	_12, _22, _32,			\
	_13, _23, _33			\
)

// 3x3 cofactor matrix
#define __cofactor3x3(		\
	_11, _12, _13,			\
	_21, _22, _23,			\
	_31, _32, _33			\
)							\
	mutil::Matrix3(			\
		/* Row 1 */			\
		__determinant2x2(	\
			_22, _23,		\
			_32, _33),		\
		-__determinant2x2(	\
			_21, _23,		\
			_31, _33		\
		),					\
		__determinant2x2(	\
			_21, _22,		\
			_31, _32		\
		),					\
							\
		/* Row 2 */			\
		-__determinant2x2(	\
			_12, _13,		\
			_32, _33		\
		),					\
		__determinant2x2(	\
			_11, _13,		\
			_31, _33		\
		),					\
		-__determinant2x2(	\
			_11, _12,		\
			_31, _32		\
		),					\
							\
		/* Row 3 */			\
		__determinant2x2(	\
			_12, _13,		\
			_22, _23		\
		),					\
		-__determinant2x2(	\
			_11, _13,		\
			_21, _23		\
		),					\
		__determinant2x2(	\
			_11, _12,		\
			_21, _22		\
		)					\
	)

// 3x3 adjugate matrix
#define __adjugate3x3(		\
	_11, _12, _13,			\
	_21, _22, _23,			\
	_31, _32, _33			\
)							\
	mutil::transpose(		\
	__cofactor3x3(			\
		_11, _12, _13,		\
		_21, _22, _23,		\
		_31, _32, _33		\
	))

// 4x4 determinant
#define __determinant4x4(		\
	_11, _12, _13, _14,			\
	_21, _22, _23, _24,			\
	_31, _32, _33, _34,			\
	_41, _42, _43, _44			\
)								\
	((_11 * __determinant3x3(	\
		_22, _23, _24,			\
		_32, _33, _34,			\
		_42, _43, _44			\
	)) -						\
	(_12 * __determinant3x3(	\
		_21, _23, _24,			\
		_31, _33, _34,			\
		_41, _43, _44			\
	)) +						\
	(_13 * __determinant3x3(	\
		_21, _22, _24,			\
		_31, _32, _34,			\
		_41, _42, _44			\
	)) -						\
	(_14 * __determinant3x3(	\
		_21, _22, _23,			\
		_31, _32, _33,			\
		_41, _42, _43			\
	)))

// 4x4 transpose matrix
#define __transpose4x4(			\
	_11, _12, _13, _14,			\
	_21, _22, _23, _24,			\
	_31, _32, _33, _34,			\
	_41, _42, _43, _44			\
)								\
	mutil::Matrix4(				\
		_11, _21, _31, _41,		\
		_12, _22, _32, _42,		\
		_13, _23, _33, _43,		\
		_14, _24, _34, _44		\
	)

// 4x4 cofactor matrix
#define __cofactor4x4(			\
	_11, _12, _13, _14,			\
	_21, _22, _23, _24,			\
	_31, _32, _33, _34,			\
	_41, _42, _43, _44			\
)								\
	mutil::Matrix4(				\
		/* Row 1 */				\
		__determinant3x3(		\
			_22, _23, _24,		\
			_32, _33, _34,		\
			_42, _43, _44		\
		),						\
		-__determinant3x3(		\
			_21, _23, _24,		\
			_31, _33, _34,		\
			_41, _43, _44		\
		),						\
		__determinant3x3(		\
			_21, _22, _24,		\
			_31, _32, _34,		\
			_41, _42, _44		\
		),						\
		-__determinant3x3(		\
			_21, _22, _23,		\
			_31, _32, _33,		\
			_41, _42, _43		\
		),						\
								\
		/* Row 2 */				\
		-__determinant3x3(		\
			_12, _13, _14,		\
			_32, _33, _34,		\
			_42, _43, _44		\
		),						\
		__determinant3x3(		\
			_11, _13, _14,		\
			_31, _33, _34,		\
			_41, _43, _44		\
		),						\
		-__determinant3x3(		\
			_11, _12, _14,		\
			_31, _32, _34,		\
			_41, _42, _44		\
		),						\
		__determinant3x3(		\
			_11, _12, _13,		\
			_31, _32, _33,		\
			_41, _42, _43		\
		),						\
								\
		/* Row 3 */				\
		__determinant3x3(		\
			_12, _13, _14,		\
			_22, _23, _24,		\
			_42, _43, _44		\
		),						\
		-__determinant3x3(		\
			_11, _13, _14,		\
			_21, _23, _24,		\
			_41, _43, _44		\
		),						\
		__determinant3x3(		\
			_11, _12, _14,		\
			_21, _22, _24,		\
			_41, _42, _44		\
		),						\
		-__determinant3x3(		\
			_11, _12, _13,		\
			_21, _22, _23,		\
			_41, _42, _43		\
		),						\
								\
		/* Row 4 */				\
		-__determinant3x3(		\
			_12, _13, _14,		\
			_22, _23, _24,		\
			_32, _33, _34		\
		),						\
		__determinant3x3(		\
			_11, _13, _14,		\
			_21, _23, _24,		\
			_31, _33, _34		\
		),						\
		-__determinant3x3(		\
			_11, _12, _14,		\
			_21, _22, _24,		\
			_31, _32, _34		\
		),						\
		__determinant3x3(		\
			_11, _12, _13,		\
			_21, _22, _23,		\
			_31, _32, _33		\
		)						\
	)

// 4x4 adjugate matrix
#define __adjugate4x4(			\
	_11, _12, _13, _14,			\
	_21, _22, _23, _24,			\
	_31, _32, _33, _34,			\
	_41, _42, _43, _44			\
)								\
	mutil::transpose(			\
	__cofactor4x4(				\
		_11, _12, _13, _14,		\
		_21, _22, _23, _24,		\
		_31, _32, _33, _34,		\
		_41, _42, _43, _44		\
	))

#endif