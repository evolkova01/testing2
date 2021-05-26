/**
 * editor.cpp -- строковый текстовый редактор
 * 
 * Copyright (c) 2021, Alexander Borodin <aborod@petrsu.ru> 
 *
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    char *arg2;
    int line;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");

        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }

            /*Сдвигаем курсор в нулевую позицию */
            if (m(txt, 0, 0) != 0) {
                fprintf(stderr, "Can't move to zero\n");
            }
            continue;
        }

        /*Обработка команды save */
        if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }

        /* Завершаем работу редактора */
        if (strcmp(cmd, "q") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        if (strcmp(cmd, "showodd") == 0) {
	  showodd(txt);
	  continue;
	 }

        /*Обработка команды m */
        if (strcmp(cmd, "m") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: m line_number cursor\n");
            } else {
                if ((arg2 = strtok(NULL, " \n")) == NULL) {
                    fprintf(stderr, "Usage: m line_number cursor\n");
                } else {
                    if (m(txt, atoi(arg), atoi(arg2)) != 0) {
                        fprintf(stderr, "Invalid arguments\n");
                    }
                }
            }
            continue;
        }

        if(strcmp(cmd, "mp") == 0) {
	    arg = strtok(NULL, "\n");
	    if (arg == NULL) {
		fprintf(stderr, "Usage: mp position\n");
	    } else {
		if (sscanf(arg, "%d", &line) > 0)
            mp(txt, line);
	    }
	    continue;
	}

        if (strcmp(cmd, "j") == 0) {
            j(txt);
            continue;
        }

        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
