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

char *my_realloc2(char *str)
{
    int i = my_strlen(str);
    char *buffer = malloc(sizeof(char) * (i + 2));
    int j = 1;

    buffer[0] = '-';
    for (int a = 0; str[a] != '\0'; a++) {
        buffer[j] = str[a];
        j++;
    }
    buffer[j] = '\0';
    return (buffer);
}

char *equal2str(char *str1, char *str2)
{
    int i = my_strlen(str2);
    int j = 0;
    int f = i - my_strlen(str1);
    char *buffer = malloc(sizeof(char) * (i + 1));

    for (int a = 0; a < f; a++)
        buffer[a] = '0';
    for (int a = f; a < i; a++) {
        buffer[a] = str1[j];
        j++;
    }
    buffer[i] = '\0';
    return (buffer);
}

char *negfunc(char *str1, char *str2)
{
    int i = my_strlen(str1);
    int j = my_strlen(str1);
    char *str = malloc(sizeof(char) * (i + 1));
    int nb = 0;

    for (; i >= 0; i--) {
        if (nb == 1) {
            str[i] = (((str1[i] - '0') + (str2[i] - '0')) % 10) + '1';
            nb = 0;
        } else {
            str[i] = (((str1[i] - '0') + (str2[i] - '0')) % 10) + '0';
        }
        if (((str1[i] - '0') + (str2[i] - '0') + '0') > '9')
            nb++;
    }
    str[j] = '\0';
    return (str);
}

char *neg(char *str1, char *str2)
{
    char *printstr = NULL;

    str1[0] = '0';
    str2[0] = '0';
    if (my_strlen(str1) < my_strlen(str2))
        str1 = equal2str(str1, str2);
    if (my_strlen(str1) > my_strlen(str2))
        str2 = equal2str(str2, str1);
    printstr = negfunc(str1, str2);
    if (printstr[0] == '0')
        printstr[0] = '-';
    if (printstr[0] == '1')
        printstr = my_realloc2(printstr);
    return (printstr);
}