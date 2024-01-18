cmake_minimum_required(VERSION 3.0.0)
project(TestApp VERSION 0.1.0)

add_executable(TestApp TestApp.cpp)

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

target_link_libraries(TestApp PUBLIC 
${CMAKE_CURRENT_LIST_DIR}/lib/libgtest_main.a 
${CMAKE_CURRENT_LIST_DIR}/lib/libgtest.a 
${CMAKE_CURRENT_LIST_DIR}/lib/libgmock.a 
${CMAKE_CURRENT_LIST_DIR}/lib/libgmock_main.a
)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()
   
add_test(
    NAME TestApp
    COMMAND TestApp
)