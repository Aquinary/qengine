#ifndef QERROR_H
#define QERROR_H

#define Q_ERROR_SDL_INIT "Не удалось инициализировать SDL!"

void _ErrorSend( char* );
char *_ErrorRead( int );
#endif

