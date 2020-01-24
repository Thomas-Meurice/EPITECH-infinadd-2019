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

char *diy(int i, char *str, char *str1, char *str2)
{
    int j = my_strlen(str1);
    int s = 0;
    int nb = 0;

    for (; i >= 0; i--) {
        if (nb == 1) {
            str[i] = (((str1[i] - '0') + (str2[i] - '0') + nb) % 10) + '0';
            if ((((str1[i] - '0') + (str2[i] - '0') + nb) + '0') > '9')
                s++;
            nb = 0;
        } else
            str[i] = (((str1[i] - '0') + (str2[i] - '0')) % 10) + '0';
        if ((((str1[i] - '0') + (str2[i] - '0') + s) + '0') > '9') {
            nb++;
            s = 0;
        }
    }
    str[j] = '\0';
    if (nb == 1)
        str = my_realloc(str);
    return (str);
}
