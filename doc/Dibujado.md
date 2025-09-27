# Dibujado de QuickDraw

QuickDraw, tecnología de graficación 2D al inicio de los 90' utilizaba un sistema de punteros para manejar la memoria.

Tenía un sistema manejo de memoria basado en celdas determinadas para cada elemento gráfico. 

El uso de HLock para Bloquear la memoria a manipular, y HUnlock para Desbloquear la manipulación del buffer de carga de archivos gráficos.


```
void LoadGraphic (short resID)
{
	Rect		bounds;
	PicHandle	thePicture;
	
	thePicture = GetPicture(resID);				// Load graphic from resource fork.
	if (thePicture == 0L)						// Check to see if nil (did it load?)
		RedAlert("\pA Graphic Couldn't Be Loaded");
	
	HLock((Handle)thePicture);					// If we made it this far, lock handle.
	bounds = (*thePicture)->picFrame;			// Get a copy of the picture's bounds.
	HUnlock((Handle)thePicture);				// We can unlock the picture now.
	OffsetRect(&bounds, -bounds.left, -bounds.top);	// Offset bounds rect to (0, 0).
	DrawPicture(thePicture, &bounds);			// Draw picture to current port.
	
	ReleaseResource((Handle)thePicture);		// Dispose of picture from heap.
}
```

En el anterior método se expone como manipula el sistema de carga de archivos de imagen. 

El método `Rect` se refiere a una figura rectangular, mientras que `PicHandle` es el módulo encargado de manejar archivos PICT, propietarios de MacOs.

Se carga el recurso por la función `GetPicture(resID)` y luego se bloquea la memoria de la imagen, se extrae la información del Struct que refiere al `Rect`, para luego liberarla. 

La imagen es procesada para generar los límites que se utilizaran luego, y libera el recurso del `Heap` de la memoria.
