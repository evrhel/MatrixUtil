cmake_minimum_required(VERSION 3.10)

project(MatrixUtil)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(MUTIL "include/mutil")

add_library(MatrixUtil INTERFACE
	${MUTIL}/f_math.h
	${MUTIL}/fmat_math.h
	${MUTIL}/fmat_math_defs.h
	${MUTIL}/fmat_transform.h
	${MUTIL}/fvec_math.h
	${MUTIL}/i_math.h
	${MUTIL}/intvector2.h
	${MUTIL}/intvector3.h
	${MUTIL}/intvector4.h
	${MUTIL}/ivec_impl.h
	${MUTIL}/ivec_math.h
	${MUTIL}/mat_types.h
	${MUTIL}/mutil.h
	${MUTIL}/quaternion.h
	${MUTIL}/settings.h
	${MUTIL}/types.h
	${MUTIL}/vec_impl.h
	${MUTIL}/vec_types.h
	${MUTIL}/vector2.h
	${MUTIL}/vector3.h
	${MUTIL}/vector4.h)

target_include_directories(MatrixUtil INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)
