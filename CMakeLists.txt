cmake_minimum_required(VERSION 3.10)
project(GlyphaSDL C)

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
add_executable(GlyphaSDL
        src/Enemy.c
        src/Externs.h
        src/Graphics.c
        src/Interface.c
        src/Main.c
        src/Play.c
        #src/Prefs.c
        src/SetUpTakeDown.c
        #src/Sound.c
        src/Utilities.c
        src/CoreSDL/SDL_Utilities.c
        include/CoreSDL/SDL_Utilities.h
        src/CoreSDL/SDL_Interface.c
        include/CoreSDL/SDL_Interface.h
        #src/CoreSDL/SDL_Sound.c
        #include/CoreSDL/SDL_Sound.h
        #src/CoreSDL/SDL_Utilities.c
        #src/CoreSDL/String.c
		Tests/TestRunner.c
		Tests/TestRunner.h
)

# ------------------------------------------------------------
# Runtime resources
# ------------------------------------------------------------

add_custom_command(TARGET GlyphaSDL POST_BUILD

    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/Img"
        "$<TARGET_FILE_DIR:GlyphaSDL>/Img"

    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/Snd"
        "$<TARGET_FILE_DIR:GlyphaSDL>/Snd"
)



target_link_libraries(GlyphaSDL ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDLMIXER_INCLUDE_DIR})
