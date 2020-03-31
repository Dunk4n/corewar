/*
** EPITECH PROJECT, 2019
** canoe
** File description:
** canoe pacome <3
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "my.h"

static int echap(menu_t *menu)
{
    while (sfRenderWindow_pollEvent(menu->window, &menu->event)) {
        if (menu->event.type == sfEvtClosed) {
            sfRenderWindow_close(menu->window);
            return true;
        }
        if (menu->event.type == sfEvtKeyPressed &&
menu->event.key.code == sfKeyEscape)
            return true;
    }
    return false;
}

void canoe_ft(menu_t *menu, canoe_t *canoe)
{
    while (sfRenderWindow_isOpen(menu->window)) {
        canoe->time = sfClock_getElapsedTime(canoe->clock);
        canoe->seconds = canoe->time.microseconds / 1000000.0;
        if (echap(menu)) {
            sfClock_restart(canoe->clock);
            return;
        }
        if (canoe->seconds > 2.5) {
            sfClock_restart(canoe->clock);
            return;
        }
        sfRenderWindow_drawSprite(menu->window, canoe->s_canoe, NULL);
        sfRenderWindow_display(menu->window);
    }
}
