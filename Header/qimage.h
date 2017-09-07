#ifndef QIMAGE_H
#define QIMAGE_H

struct _qimage
{
	SDL_Texture *Texture [ QTEXTUREMAXCOUNT ];
} *QImage;

void _ImageLoad ( int, char* );
void _ImageDraw ( int, int, int, int, int, int );
#endif

