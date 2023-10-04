cmake_minimum_required(VERSION 3.16)

project(cppu)

find_package(CppUTest REQUIRED)

add_library(libcpputest STATIC IMPORTED)
set_property(TARGET libcpputest PROPERTY IMPORTED_LOCATION /usr/lib/libCppUTest.a)
add_library(libcpputestext STATIC IMPORTED)
set_property(TARGET libcpputestext PROPERTY IMPORTED_LOCATION /usr/lib/libCppUTestExt.a)

set(TEST_APP_NAME cppu_tests)
set(TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/tests/testmain.cpp
)

# set(CMAKE_EXE_LINKER_FLAGS "-lCppUTest -lCppUTestExt")

add_executable(${TEST_APP_NAME} ${TEST_SOURCES})
target_link_libraries(${TEST_APP_NAME} libcpputest libcpputestext)
# target_link_libraries(${TEST_APP_NAME})
