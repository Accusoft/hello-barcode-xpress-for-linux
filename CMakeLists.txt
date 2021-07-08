cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(readbarcodes)

file(DOWNLOAD https://download.accusoft.com/barcodexpress/latest/libbarcodexpress.so ${CMAKE_BINARY_DIR}/bin/libbarcodexpress.so.13)
file(DOWNLOAD https://download.accusoft.com/barcodexpress/latest/barcodexpress.h ${CMAKE_BINARY_DIR}/include/barcodexpress.h)

link_directories(${CMAKE_BINARY_DIR}/bin)
include_directories(${CMAKE_BINARY_DIR}/include)

add_executable(readbarcodes readbarcodes.cpp)
target_link_libraries(readbarcodes ${CMAKE_BINARY_DIR}/bin/libbarcodexpress.so.13 pthread ${CMAKE_DL_LIBS})
configure_file(${CMAKE_SOURCE_DIR}/test-barcodes.bmp ${CMAKE_CURRENT_BINARY_DIR}/test-barcodes.bmp COPYONLY)
