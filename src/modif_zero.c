/*
** EPITECH PROJECT, 2019
** # rush2.c
** File description:
** {description}
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *modifzero(char *str)
{
    int l = 0;
    char *buffer = NULL;
    int i = 0;
    int count = 1;

    if (str[0] == '-') {
        i++;
        count++;
    }
    for (; str[i] == '0' && str[i] != '\0'; i++);
    buffer = malloc(sizeof(char) * ((my_strlen(str) - i) + count));
    if (str[0] == '-') {
        buffer[0] = '-';
        l++;
    }
    for (; str[i] != '\0'; i++) {
        buffer[l] = str[i];
        l++;
    }
    buffer[l] = '\0';
    return (buffer);
}
