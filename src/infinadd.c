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

char *my_realloc(char *str)
{
    int i = my_strlen(str);
    char *buffer = malloc(sizeof(char) * (i + 2));
    int j = 1;

    buffer[0] = '1';
    for (int a = 0; str[a] != '\0'; a++) {
        buffer[j] = str[a];
        j++;
    }
    buffer[j] = '\0';
    return (buffer);
}

char *equalstr(char *str1, char *str2)
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

char *addfunc(char *str1, char *str2)
{
    int i = my_strlen(str1);
    char *str = malloc(sizeof(char) * (i + 1));

    str = diy(i, str, str1 , str2);
    return (str);
}

char *infinadd(char **av)
{
    char *printstr = NULL;
    char *str1 = my_strdup(av[1]);
    char *str2 = my_strdup(av[2]);

    if (str1[0] != '-' && str2[0] != '-') {
        if (my_strlen(str1) < my_strlen(str2))
            str1 = equalstr(str1, str2);
        if (my_strlen(str1) > my_strlen(str2))
            str2 = equalstr(str2, str1);
        printstr = addfunc(str1, str2);
    }
    if (str1[0] == '-' && str2[0] == '-')
        printstr = neg(str1, str2);
    //    if ((str1[0] == '-' && str2[0] != '-') ||
    //        (str1[0] != '-' && str2[0] == '-'))
    //        printstr = neg2(str1, str2);
    return (printstr);
}

int main(int ac, char **av)
{
    char *printstr = NULL;

    if (ac != 3)
        return (84);
    if (error_management(av) == 1)
        return (84);
    printstr = infinadd(av);
    printstr = modifzero(printstr);
    if (my_strlen(printstr) == 0)
        my_putchar('0');
    else if (my_strlen(printstr) == 1 && printstr[0] == '-')
        write(1, "-0", 2);
    else
        my_putstr(printstr);
    write(1, "\n", 1);
    return (0);
}