/*
** EPITECH PROJECT, 2018
** my_getnbr_long
** File description:
** return the number in a string
*/

long    long    my_getnbr_long(char const *str)
{
    int         i = 0;
    long long   nb = 0;
    int         neg = 1;

    while (str[i] != '\0' && (str[i] <= 32 || str[i] == 43 || str[i] == 45)) {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
        nb = nb * 10 + (str[i++] - '0');
    return (nb * neg);
}
