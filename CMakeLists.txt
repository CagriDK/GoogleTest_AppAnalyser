cmake_minimum_required(VERSION 3.0.0)
project(GoogleTest VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(test)

add_compile_options(-pg)
add_link_options(-pg)

add_executable(GoogleTest main.cpp)

if(UNIX)
    target_link_libraries(GoogleTest pthread)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
