#ifndef QAPP_H
#define QAPP_H

#define QWINDOWFLAG 0x00
#define QRENDERFLAG 0x01
#define QSET 		0x02
#define QGET		0x03
#define QKEYPRESS	0x04
#define QKEYUP		0x05
#define QKEYHOLD	0x06
//#define QFULLSCREEN 0x07
#define QMAXIMIZE	0x08
#define QMINIMIZE	0x09
#define QHIDE		0x10
#define QWSIZE		0x11
#define QHSIZE		0x12
#define QXPOS		0x13
#define	QYPOS		0x14
#define QDEPTH		0x15
#define	QFPS		0x16
#define QNOSCALE	0x17
#define QVALUE2		0x18
#define QVALUE3		0x19
#define QVALUE4		0x20
#define QVALUE5		0x21
#define QVALUE6		0x22
#define QVALUE7		0x23
#define QVALUE8		0x24
#define QVALUE9		0x25
#define QVALUE10	0x26
#define QVALUE11	0x27
#define QVALUE12	0x28
#define QVALUE13	0x29
#define QVALUE14	0x30
#define QVALUE15	0x31
#define QVALUE16	0x32
#define QVALUE17	0x33
#define QVALUE18	0x34
#define QVALUE19	0x35
#define QVALUE20	0x36
#define QVALUE21	0x37
#define QVALUE22	0x38
#define QCENTERED	SDL_WINDOWPOS_CENTERED	
#define QFULLSCREEN SDL_WINDOW_FULLSCREEN
#define QNONE		SDL_WINDOW_SHOWN
#define QOPENGL		SDL_WINDOW_OPENGL
#define QHARDWARE	SDL_RENDERER_ACCELERATED
#define QSOFTWARE 	SDL_RENDERER_SOFTWARE
#define QTEXTUREMAXCOUNT 256
#define QSCENEMAXCOUNT	256


//Инициализация Q
void QInit ( void );
//Деинициализация Q
void QQuit ( void );
//Установка и получение флагов окна и рендера
Uint32 _AppFlags ( int, int, ... );
#endif

