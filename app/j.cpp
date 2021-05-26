#include "text.h"
#include "_text.h"

int j(text txt)
{
    /* Последняя строка */ 
    std::list<std::string>::iterator last_str = txt->lst->end();
    last_str--;

    /* Проверка на последнюю строку */
    if (txt->cursor->line == last_str) {
        printf("Невозможно. Текущая строка последняя\n");
        return -1;
    }

    std::list<std::string>::iterator current = txt->cursor->line;

    /* Указатель на следующую строку, которую будем добавлять*/ 
    std::list<std::string>::iterator next_line = txt->cursor->line;
    next_line++;

    /* Записываем в строку содержимое текущей и следующей строки*/  
    std::string new_line = (*current) + (*next_line);

    /* Курсор ставим на новую строку*/  
    txt->cursor->line = txt->lst->insert(current, new_line);
 
    txt->lst->erase(current);
    txt->lst->erase(next_line);

    return 0;
}
