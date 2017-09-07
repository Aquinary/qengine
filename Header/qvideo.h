#ifndef QVIDEO_H
#define QVIDEO_H

struct _qwindow
{
	char *Caption;
	int X, Y;
	int W, H;
	Uint32 RenderFlags;
	Uint32 WindowFlags;
	SDL_Window *Window;
	SDL_Renderer *Render;
	SDL_Surface *Surface;
} *QWindow;

void _WindowCreate( char*, int, int, int, int );
void _WindowDestroy( void );
void _WindowRender ( void );

#endif

