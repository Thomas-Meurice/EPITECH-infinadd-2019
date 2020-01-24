/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

#include "my.h"
#include <unistd.h>

int my_put_nbr(int nb)
{
    float f;
    char c;

    if (nb < 0) {
        nb *= -1;
        write(1, "-", 1);
    }
    for (f = nb; f >= 1; f /= 10);
    f *= 10;
    for (c = 0; f <= nb; f *= 10) {
        c = (int)f % 10 + '0';
        write(1, &c, 1);
    }
    return (0);
}