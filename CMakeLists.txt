cmake_minimum_required(VERSION 3.16)
project(pacserver C)

include_directories (lib)
include_directories (src)

set(CMAKE_C_STANDARD 99)

# definitions for libalpm
add_definitions (-DHAVE_LIBCURL)
add_definitions (-DHAVE_LIBSSL)
add_definitions (-DLIB_VERSION="13.0.2")
add_definitions (-DPACKAGE_VERSION="6.0.2")

add_definitions (-DFSSTATSTYPE=struct\ statvfs)
add_definitions (-DHAVE_SYS_STATVFS_H)
add_definitions (-DHAVE_STRNLEN)
add_definitions (-DSCRIPTLET_SHELL="/bin/sh")
add_definitions (-DLDCONFIG="/sbin/ldconfig")

# definitions for pacman
add_definitions(-DSYSHOOKDIR="pacman/hooks")
add_definitions(-DCONFFILE="pacman.conf")
add_definitions(-DDBPATH="pacman/db")
add_definitions(-DGPGDIR="pacman/gnupg")
add_definitions(-DLOGFILE="pacman/pacman.log")
add_definitions(-DCACHEDIR="pacman/pkg")
add_definitions(-DHOOKDIR="pacman/hooks")
add_definitions(-DROOTDIR=".")
add_definitions(-DENABLE_NLS)
add_definitions(-DLOCALEDIR="pacman/locale")
add_definitions (-DPACKAGE="pacman")
add_definitions(-DHAVE_GETMNTENT)
add_definitions(-DHAVE_MNTENT_H)

include("i18n.cmake")

add_library(alpm SHARED)
add_subdirectory(lib)

add_executable(pacserver)
add_subdirectory(src)

