#pragma once
#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int		tickNext = 0;

// Aquí puedes incluir cualquier encabezado común necesario para tu proyecto


void LogNextTick(int howMany)
{
	tickNext = (int)SDL_GetTicks() + howMany;		// Get machine's TickCount() and add to it.
}

//--------------------------------------------------------------  WaitForNextTick

// This is the companion function to the above function (LogNextTick()).
// We do nothing but loop until TickCount() catches up with (or passes) ourÉ
// global variable tickNext.

void WaitForNextTick(void)
{
	do
	{
		//printf(("%d\n"), tickNext);
		//printf(("%d\n"),SDL_GetTicks);
	} while ((int)SDL_GetTicks() < tickNext);			// Loop until TickCount() catches up.
}

#endif // COMMON_H;