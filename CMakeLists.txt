cmake_minimum_required(VERSION 3.10)

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
INCLUDE_DIRECTORIES("includes")
INCLUDE_DIRECTORIES("Snd")
INCLUDE_DIRECTORIES("Img")
# Se añade el directorio a la ruta de búsqueda del compilador de turno
FILE(GLOB MiProyecto_SRC "src/*.c")
FILE(GLOB MiProyecto_SRC "includes/*.h")
# FILE GLOB selecciona todos los archivos que cumplan la característica y los almacena en MiProyecto_SRC
# GLOB no es recursivo. Si lo necesitas, usa GLOB_RECURSE

add_executable(SDL2Test WIN32 	main.c  
			      	src/draw.c
				includes/draw.h
			      	src/init.c
			      	includes/init.h
				src/input.c
				includes/input.h
				src/sound.c
				includes/sound.h
				includes/main.h
				includes/defs.h
				includes/structs.h
				includes/common.h
				)

target_link_libraries(SDL2Test ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})