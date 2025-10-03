cmake_minimum_required(VERSION 4.0)
project(NewCode C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${SDL2_MIXER_INCLUDE_DIRS})
INCLUDE_DIRECTORIES("Img")
add_executable(NewCode
        #Enemy.c
        Externs.h
        Graphics.c
        #Interface.c
        Main.c
        Play.c
        #Prefs.c
        SetUpTakeDown.c
        #Sound.c
        #Utilities.c
        CoreSDL/SDL_Utilities.c
        CoreSDL/SDL_Utilities.h
        CoreSDL/SDL_Interface.c
        CoreSDL/SDL_Interface.h
        #CoreSDL/SDL_Sound.c
        #CoreSDL/SDL_Sound.h
        #CoreSDL/SDL_Utilities.c
        #CoreSDL/String.c
)

target_link_libraries(NewCode ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDLMIXER_INCLUDE_DIR})
