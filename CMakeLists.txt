cmake_minimum_required(VERSION 3.10)

project(MatrixUtil)

include(CTest)

add_subdirectory(MatrixUtil)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	add_subdirectory(MatrixUtilTests)
endif ()

enable_testing()
