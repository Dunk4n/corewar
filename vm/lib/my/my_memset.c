/*
** EPITECH PROJECT, 2018
** my_memset
** File description:
** my_memset
*/

#include <stdlib.h>

void    my_memset(void  *ptr, char value, size_t size)
{
    char    *tmp = (char*)ptr;
    size_t  i = 0;

    while (i < size) {
        tmp[i] = value;
        i++;
    }
}
