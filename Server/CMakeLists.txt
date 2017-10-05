cmake_minimum_required(VERSION 3.8)
project(Server)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Server.cpp MemoryList.h)
add_executable(Server ${SOURCE_FILES})

set(THREADS PREFER PTHREAD FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Server Threads::Threads)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.3.2 REQUIRED system graphics window network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()