#ifndef Q_H
#define Q_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "SDL2/SDL.h"

#include "qapp.h"
#include "qerror.h"
#include "qvideo.h"
#include "qevent.h"
#include "qkeys.h"
#include "qimage.h"
#include "qscene.h"

struct _q
{
	 void ( *ErrorSend ) ( char* );
	 char *( *ErrorRead ) ( int );
	 
	 Uint32 ( *AppFlags ) ( int, int, ... );
	 
	 void ( *WindowCreate ) ( char *, int, int, int, int );
	 void ( *WindowDestroy ) ( void );
	 void ( *WindowRender ) ( void );
	 
	 void ( *EventUpdate ) ( void );
	 int ( *EventKey) ( int, Uint8, ... );
	 
 	 void ( *ImageLoad ) ( int, char* );
	 void ( *ImageDraw )	( int, int, int, int, int, int );
	  
	 void ( *SceneCreate ) ( int, int, int );
	 int ( *SceneActive) ( int );
} Q;

#endif

