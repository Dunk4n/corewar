/*
** EPITECH PROJECT, 2018
** my_caloc
** File description:
** my_calloc
*/

#include <stdlib.h>
#include "my.h"

void    *my_calloc(size_t size, char value)
{
    void    *ptr;

    if (!(ptr = malloc(size)))
        return (NULL);
    my_memset(ptr, value, size);
    return (ptr);
}
