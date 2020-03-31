/*
** EPITECH PROJECT, 2019
** src/core/display_all_corewar
** File description:
** segmentation fault (core dumped)
*/

#include <stdlib.h>
#include "corwar.h"

static  void    display_case(menu_t *menu)
{
    sfColor color;
    size_t  i = 0;
    size_t  j;

    while (i < MEM_SIZE / 96) {
        j = 0;
        while (j < 96) {
            color = menu->color[(i * 96 + j) % MEM_SIZE];
            if (color.a == 255)
                sfSprite_setRotation(menu->s_case, 45);
            else
                sfSprite_setRotation(menu->s_case, 0);
            sfSprite_setColor(menu->s_case, color);
            sfSprite_setPosition(menu->s_case, (sfVector2f){menu->start.x +
menu->size.x * j, menu->start.y + menu->size.y * i});
            sfRenderWindow_drawSprite(menu->window, menu->s_case, NULL);
            j++;
        }
        i++;
    }
}

static  int     if_prog(corewar_t *core, size_t nb)
{
    size_t i = 0;

    while (i < core->nb_prog) {
        if (core->prog[i].pc == (int)nb)
            return (1);
        i++;
    }
    return (0);
}

static  void    change_color(corewar_t *core, menu_t *menu)
{
    size_t  i = 0;
    int     tmp = 1;
    int     type;

    while (i < MEM_SIZE) {
        if (if_prog(core, i)) {
            menu->color[i].a = 255;
            i++;
            continue;
        }
        else if (core->map[i] >= 1 && core->map[i] < 26)
            type = 210;
        else
            type = 140;
        if (((float)type - (float)menu->color[i].a) < 0)
            tmp = -1;
        if (menu->color[i].a != type)
            menu->color[i].a += (((float)type - (float)menu->color[i].a) / 50.0
> 1) ? ((float)type - (float)menu->color[i].a) / 50.0 : tmp;
        i++;
    }
}

int     display_all_corewar(corewar_t *core, menu_t *menu, size_t i, int to_die)
{
    if (to_die != -42 && i % 500 != 0)
        return (1);
    sfRenderWindow_drawSprite(menu->window, menu->s_fond, NULL);
    change_color(core, menu);
    display_case(menu);
    if (!display_text(core, menu, i, (to_die < 0) ? 0 : to_die))
        return (0);
    sfRenderWindow_display(menu->window);
    if (to_die != -42)
        sfRenderWindow_clear(menu->window, sfBlack);
    while (sfRenderWindow_pollEvent(menu->window, &(menu->event))) {
        (menu->event.type == sfEvtClosed) ?
sfRenderWindow_close(menu->window) : 0;
        if (menu->event.type == sfEvtKeyPressed &&
menu->event.key.code == sfKeyEscape)
            sfRenderWindow_close(menu->window);
        if (menu->event.type == sfEvtKeyPressed &&
menu->event.key.code == sfKeySpace)
            menu->stop = 0;
    }
    return (1);
}

int     display_all_corewar_tour(corewar_t *core, menu_t *menu, size_t i,
int to_die)
{
    sfRenderWindow_drawSprite(menu->window, menu->s_fond, NULL);
    change_color(core, menu);
    display_case(menu);
    if (!display_text(core, menu, i, (to_die < 0) ? 0 : to_die))
        return (0);
    sfRenderWindow_display(menu->window);
    if (to_die != -42)
        sfRenderWindow_clear(menu->window, sfBlack);
    while (sfRenderWindow_pollEvent(menu->window, &(menu->event))) {
        (menu->event.type == sfEvtClosed) ?
sfRenderWindow_close(menu->window) : 0;
        if (menu->event.type == sfEvtKeyPressed &&
menu->event.key.code == sfKeyEscape)
            sfRenderWindow_close(menu->window);
        if (menu->event.type == sfEvtKeyPressed &&
menu->event.key.code == sfKeySpace)
            menu->stop = 0;
    }
    return (1);
}

void    display_win(corewar_t *core, menu_t *menu, size_t i)
{
    sfColor     color[] = {sfRed, sfGreen, sfYellow, sfBlue};

    display_all_corewar(core, menu, i, -42);
    sfText_setColor(menu->text, color[win(core)]);
    sfText_setPosition(menu->text, (sfVector2f){500, 300});
    sfText_setCharacterSize(menu->text, 400);
    sfText_setString(menu->text, "WIN");
    sfRenderWindow_drawText(menu->window, menu->text, NULL);
    sfRenderWindow_display(menu->window);
    while (sfRenderWindow_isOpen(menu->window)) {
        while (sfRenderWindow_pollEvent(menu->window, &(menu->event))) {
            (menu->event.type == sfEvtClosed) ?
sfRenderWindow_close(menu->window) : 0;
            (menu->event.type == sfEvtKeyPressed) ?
sfRenderWindow_close(menu->window) : 0;
        }
    }
}
