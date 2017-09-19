cmake_minimum_required(VERSION 3.8)
project(Server)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Server.cpp MemoryList.h)
add_executable(Server ${SOURCE_FILES})

set(THREADS PREFER PTHREAD FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Server Threads::Threads)