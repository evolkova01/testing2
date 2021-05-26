#include "text.h"
#include "_text.h"
#include <string.h>

void mp(text txt, int arg)
{
    /* Указатель на текущую строку */
    std::list<std::string>::iterator current = txt->cursor->line;
   
    /* Проверка на наличие такой позиции*/
    if (arg < 0) {
    printf("Try again");
	return;
    }
    
    if ((*current).length() < (long unsigned int) arg){
    printf("Try again");
	return;
	}
    /*Меняем позицию курсора в строке */
    txt->cursor->position = arg;
}
