#include "Header/Q.h"

int _EventKey( int Type, Uint8 KeyCode, ... )
{
	/* Функция проверки статуса нажатой клавиши */
	
	
	//Если имеются дополнительные параметры
	//TODO: Передача функции, как доп. параметра
	//TODO: Передача параметров функции передаваемой функции, как параметра
	//TODO: Массовая перегрузка
	//Определяем перезагрузочные типы
	va_list fparam;
	va_start ( fparam, KeyCode );
	void (*void_func )(void) = va_arg( fparam, void (*) (void));
	void (*int_func )(int) = va_arg( fparam, void (*) (int));
	void (*char_func )(char) = va_arg( fparam, void (*) (char*));
	va_end( fparam );
	//Определяем аргументы
	va_list farg;
	va_start ( farg, KeyCode );
	int param = va_arg ( farg, void (*) (int));
	va_end(farg);
	
	//Слушаем тип
	switch ( Type )
	{
		//Если тип - опускание клавиши
		case 0x04:
			//И если клавиша опущена
			if ( QEvent -> KeyCodeDown == KeyCode )
			{
				//То сигнализируем об этом
				return 1;	
			}
		break;
		//Если тип - опускание клавиши
		case 0x05:
			//И если клавиша отпущена
			if ( QEvent -> KeyCodeUp == KeyCode )
			{
				//То сигнализируем об этом	
				return 1;
			}
		break;
		//Если тип - удержание клавиши
		case 0x06:
			//TODO: Функциональные клавиши и клавиши набора текста почему то не совмещаются
			if ( QEvent -> KeyState [ SDL_GetScancodeFromKey( KeyCode) ])
			{
				//Сигнализируем о нажатии
				return 1;
			}
		break;
		default:
			//Иначе сигнализируем об отсутствии нажатии
			return 0;
		break;
		
	}
}
