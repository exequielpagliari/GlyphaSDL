cmake_minimum_required(VERSION 4.0)
project(NewCode C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(NewCode
        Enemy.c
        Externs.h
        Graphics.c
        Interface.c
        Main.c
        Play.c
        Prefs.c
        SetUpTakeDown.c
        Sound.c
        Utilities.c
        CoreSDL/SDL_Utilities.cpp
        CoreSDL/SDL_Utilities.h
        CoreSDL/Sound.cpp
        CoreSDL/Sound.h)
