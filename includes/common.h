//#pragma once
#ifndef COMMON_H
#define COMMON_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void LogNextTick (int);
void WaitForNextTick (void);


extern int tickNext;


//-------------------------------------------------------------- WaitForNextTick

// This is the companion function to the above function (LogNextTick()).
// We do nothing but loop until TickCount() catches up with (or passes) ourÉ
// global variable tickNext.



#endif // COMMON_H;
