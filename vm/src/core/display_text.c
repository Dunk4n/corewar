/*
** EPITECH PROJECT, 2019
** src/core/display_text
** File description:
** xkcd.com/378
*/

#include <stdlib.h>
#include "corwar.h"

static  void    display_name(corewar_t *core, menu_t *menu)
{
    size_t      i = 0;
    sfVector2f  pos[4] = {{50, 20}, {800, 20}, {50, 80}, {800, 80}};
    sfColor     color[] = {sfRed, sfGreen, sfYellow, sfBlue};

    while (i < 4 && i < core->nb_prog) {
        if (core->prog[i].nb != core->prog[i].daron) {
            i++;
            continue ;
        }
        sfText_setColor(menu->text, color[i]);
        if (core->prog[i].live == -1)
            sfText_setColor(menu->text, (sfColor){100, 100, 100, 100});
        sfText_setPosition(menu->text, pos[i]);
        sfText_setString(menu->text, core->prog[i].name);
        sfRenderWindow_drawText(menu->window, menu->text, NULL);
        i++;
    }
}

int     display_ui(menu_t *menu, char *line, int nb, size_t i)
{
    char *str = my_itoa(nb);

    if (!str)
        return (0);
    sfText_setColor(menu->text, sfMagenta);
    sfText_setPosition(menu->text, (sfVector2f){1400, 290 + i * 40});
    sfText_setString(menu->text, line);
    sfRenderWindow_drawText(menu->window, menu->text, NULL);
    sfText_setPosition(menu->text, (sfVector2f){1600, 290 + i * 40});
    sfText_setString(menu->text, str);
    sfRenderWindow_drawText(menu->window, menu->text, NULL);
    free(str);
    return (1);
}

int     display_to_die(menu_t *menu, int to_die, int cycle_to_die)
{
    char *str = my_itoa(to_die);
    char *str2 = my_itoa(cycle_to_die);

    if (!str || !str2) {
        free(str);
        free(str2);
        return (0);
    }
    sfText_setColor(menu->text, sfMagenta);
    sfText_setPosition(menu->text, (sfVector2f){1400, 250});
    sfText_setString(menu->text, "Cycle to die :             /");
    sfRenderWindow_drawText(menu->window, menu->text, NULL);
    sfText_setPosition(menu->text, (sfVector2f){1600, 250});
    sfText_setString(menu->text, str);
    sfRenderWindow_drawText(menu->window, menu->text, NULL);
    sfText_setPosition(menu->text, (sfVector2f){1700, 250});
    sfText_setString(menu->text, str2);
    sfRenderWindow_drawText(menu->window, menu->text, NULL);
    free(str);
    free(str2);
    return (1);
}

int     display_text(corewar_t *core, menu_t *menu, size_t i, int to_die)
{
    char    *txt[] = {"Total cycle :", "NBR live :",
"NB process :"};
    int     nb[] = {i, core->nb_live, core->nb_prog};
    size_t  j = 0;

    if (!display_to_die(menu, to_die, core->cycle_to_die))
        return (0);
    sfText_setCharacterSize(menu->text, 40);
    display_name(core, menu);
    sfText_setCharacterSize(menu->text, 25);
    while (j < 3) {
        if (!display_ui(menu, txt[j], nb[j], j))
            return (0);
        j++;
    }
    return (1);
}
