/**
 * showupper.cpp -- функция для вывода текста с капитализацией всех символов
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "text.h"
#include <list>

static void show_line(int index, std::string contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран с капитализацией всех символов
 */
void showodd(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

static void show_line(int index, std::string contents, int cursor, void *data)
{
    /* Декларируем неиспользуемые параметры */
    UNUSED(cursor);
    UNUSED(data);

    /*Выделяем память под копию текущей строки */
    char *contents_copy = (char *) malloc((MAXLINE + 1) * sizeof(char));

    /*Копируем текующую строку */
    strcpy(contents_copy, contents.c_str());

    /* Выводим копию строки на экран */
    if(index % 2 == 1) {
        /* Выводим строку на экран */
	printf("%s\n", contents_copy);
    }
}
