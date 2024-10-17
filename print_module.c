#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    // Создаем переменные для времени
    time_t rawtime;
    struct tm* timeinfo;
    char time_buffer[9];  // HH:MM:SS

    //Получаем время и преобразуем в локальное
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Форматируем время в строку HH:MM:SS - записываем в time_buffer
    strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", timeinfo);

    // [LOG] output
    char* log_prefix = Log_prefix;
    while (*log_prefix) {
        print(*log_prefix++);
    }

    // TIME output
    print(' ');
    for (int i = 0; i < 8; i++) {
        print(time_buffer[i]);
    }

    // Message output
    print(' ');
    while (*message) {
        print(*message++);
    }
}