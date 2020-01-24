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

int error_management(char **av)
{
    if (my_strlen(av[1]) == 1 && av[1][0] == '-')
        return (1);
    if (my_strlen(av[2]) == 1 && av[2][0] == '-')
        return (1);
    if ((av[1][0] < '0' || av[1][0] > '9') && av[1][0] != '-')
        return (1);
    if ((av[2][0] < '0' || av[2][0] > '9') && av[2][0] != '-')
        return (1);
    for (int i = 1; av[1][i] != '\0'; i++)
        if (av[1][i] < '0' || av[1][i] > '9')
            return (1);
    for (int i = 1; av[2][i] != '\0'; i++)
        if (av[2][i] < '0' || av[2][i] > '9')
            return (1);
    return (0);
}
