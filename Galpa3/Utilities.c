
#include <Externs.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


short Random()
{
	

	// Generar y mostrar varios nmeros aleatorios
	return rand();
}

//Funcion creada para generar un Seed para obtener valor aleatorio por ejecucion
void CreateSeed(void)
{
	unsigned int seed = (unsigned int)time(NULL);
	srand(seed);
}

// Takes a short (range) and returns a random number from zero to range - 1.

short RandomInt(short range)
{

	register long int rawResult;

	rawResult = Random();
	if (rawResult < 0L)
		rawResult *= -1L;
	rawResult = (rawResult * (long)range) / 32768L;

	return ((short)rawResult);
}
