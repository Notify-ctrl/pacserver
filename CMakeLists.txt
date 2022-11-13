cmake_minimum_required(VERSION 3.16)
project(pacserver C)

include_directories (src)

set(CMAKE_C_STANDARD 99)

add_definitions (-DHAVE_LIBCURL)
add_definitions (-DHAVE_LIBSSL)
add_definitions (-DSYSHOOKDIR=\"${CMAKE_SOURCE_DIR}/libalpm/hooks/\")
add_definitions (-DLIB_VERSION="10.0.2")
add_definitions (-DPACKAGE_VERSION="5.0.2")

add_definitions (-DFSSTATSTYPE=struct\ statvfs)
add_definitions (-DHAVE_SYS_STATVFS_H)
add_definitions (-DHAVE_STRNLEN)
add_definitions (-DSCRIPTLET_SHELL="/bin/sh")
add_definitions (-DLDCONFIG="/sbin/ldconfig")

add_library(alpm SHARED)
add_subdirectory(lib)

add_executable(pacserver)
add_subdirectory(src)

