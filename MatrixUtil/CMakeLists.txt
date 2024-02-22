cmake_minimum_required(VERSION 3.10)

project(MatrixUtil)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(MUTIL "include/mutil")

add_library(MatrixUtil INTERFACE
	${MUTIL}/mat/fmat_math_defs.h
	${MUTIL}/mat/fmat_transform.h
	${MUTIL}/mat/mat_impl.h
	${MUTIL}/mat/mat_types.h

	${MUTIL}/math/f_math.h
	${MUTIL}/math/fmat_math.h
	${MUTIL}/math/fvec_math.h
	${MUTIL}/math/i_math.h

	${MUTIL}/quat/quaternion.h

	${MUTIL}/vec/intvector2.h
	${MUTIL}/vec/intvector3.h
	${MUTIL}/vec/intvector4.h
	${MUTIL}/vec/vec_impl.h
	${MUTIL}/vec/vec_types.h
	${MUTIL}/vec/vec.h
	${MUTIL}/vec/vector2.h
	${MUTIL}/vec/vector3.h
	${MUTIL}/vec/vector4.h
)

target_include_directories(MatrixUtil INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)
