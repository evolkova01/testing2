
#ifndef TEXT_H
#define TEXT_H

#include <string>

#define MAXLINE 255

/**
 * Абстрактный тип текстовых объектов
 */
typedef struct _list *text;

/**
 * Абстрактный тип курсора
 */
typedef struct _crsr *cursor;


/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text();

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, std::string contents);


/**
 * Обрабатывает текст, применяя заданную функцию к каждой строке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text txt,
    void (*process)(int index, std::string contents, int cursor_position, void *data),
    void *data
);


/**
 * Удаляет весь текст
 * 
 * @param txt текст
 * @returns none
 */
void remove_all(text txt);

int m(text txt, int line_num, int cursor_pos);

int j(text txt);

void mp(text txt, int arg);

#endif
