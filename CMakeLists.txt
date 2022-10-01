cmake_minimum_required(VERSION 3.12.4)

set(PATCH_VERSION "2" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VESRION})

set(CMAKE_CXX_STANDARD 17)

set(SRC_PATH "src/")
set(CMAKE_EXE_LINKER_FLAGS " -static")
include_directories("src/")

add_library(
        ip_filter_obj
        ${SRC_PATH}/address.cpp
        ${SRC_PATH}/filter.cpp)

add_executable(ip_filter ${SRC_PATH}/main.cpp)
target_link_libraries(ip_filter ip_filter_obj -static-libgcc -static-libstdc++)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)