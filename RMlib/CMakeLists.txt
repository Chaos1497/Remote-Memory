cmake_minimum_required(VERSION 3.8)
project(RMlib)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES rmlib.cpp)
add_executable(RMlib ${SOURCE_FILES})

#include_directories(/home/esteban/Descargas/allegro-5.2.2.0/include)
#link_directories(/home/esteban/Descargas/allegro/5.2.2.0/lib)
#TARGET_LINK_LIBRARIES(RMlib  allegro_acodec
#        allegro_audio
#        allegro_color
#        allegro_dialog
#        allegro_image
#        allegro_main
#        allegro_memfile
#        allegro_physfs
#        allegro_primitives
#        allegro_ttf
#        allegro_font
#        allegro)


set(THREADS PREFER PTHREAD FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(RMlib Threads::Threads)
