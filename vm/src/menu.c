/*
** EPITECH PROJECT, 2019
** menu.c
** File description:
** menu -g
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "my.h"

static void display_menu(menu_t *menu, canoe_t *canoe, int ac, char **av)
{
    char const *string1 = "Corewar : nobody asked for it.";
    char const *string2 = "Start";
    char const *string3 = "Canoe";
    sfVector2i mouse = sfMouse_getPositionRenderWindow(menu->window);

    sfRenderWindow_drawSprite(menu->window, menu->s_menu, NULL);
    sfText_setPosition(menu->text_menu, (sfVector2f){250, 100});
    sfText_setCharacterSize(menu->text_menu, 80);
    sfText_setColor(menu->text_menu, sfBlack);
    sfText_setString(menu->text_menu, string1);
    sfRenderWindow_drawText(menu->window, menu->text_menu, NULL);
    sfText_setPosition(menu->text_menu, (sfVector2f){885, 500});
    sfText_setCharacterSize(menu->text_menu, 40);
    sfText_setString(menu->text_menu, string2);
    sfText_setColor(menu->text_menu, sfWhite);
    if (mouse.x >= 864 && mouse.x <= 1044 && mouse.y >= 480 && mouse.y <= 570) {
        sfText_setColor(menu->text_menu, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_destroy(menu->music);
            select_p(menu, ac, av, 0);
        }
    }
    sfRenderWindow_drawText(menu->window, menu->text_menu, NULL);
    sfText_setPosition(menu->text_menu, (sfVector2f){870, 650});
    sfText_setString(menu->text_menu, string3);
    sfText_setColor(menu->text_menu, sfWhite);
    if (mouse.x >= 864 && mouse.x <= 1044 && mouse.y >= 645 && mouse.y <= 705) {
        sfText_setColor(menu->text_menu, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            canoe_ft(menu, canoe);
    }
    sfRenderWindow_drawText(menu->window, menu->text_menu, NULL);
    sfText_setPosition(menu->text_menu, (sfVector2f){650, 745});
    sfText_setString(menu->text_menu, "Instruction par Instruction");
    sfText_setColor(menu->text_menu, sfWhite);
    if (mouse.x >= 640 && mouse.x <= 1340 && mouse.y >= 745 && mouse.y <= 800) {
        sfText_setColor(menu->text_menu, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_destroy(menu->music);
            select_p(menu, ac, av, 1);
        }
    }
    sfRenderWindow_drawText(menu->window, menu->text_menu, NULL);
}

int     init(menu_t *menu, canoe_t *canoe)
{
    char const *name = "VM COREWAR";
    sfFont *font = sfFont_createFromFile(FONT);

    menu->text_menu = sfText_create();
    canoe->clock = sfClock_create();
    canoe->t_canoe = sfTexture_createFromFile(CANOE, NULL);
    canoe->s_canoe = sfSprite_create();
    menu->music = sfMusic_createFromFile(MUSIC);
    menu->t_menu = sfTexture_createFromFile(MENU, NULL);
    menu->s_menu = sfSprite_create();
    menu->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
name, sfFullscreen, NULL);
    if (!menu->window || !canoe->t_canoe || !canoe->s_canoe || !menu->music ||
!menu->t_menu || !menu->s_menu || !menu->text_menu || !font)
        return (0);
    sfSprite_setTexture(menu->s_menu, menu->t_menu, sfTrue);
    sfSprite_setTexture(canoe->s_canoe, canoe->t_canoe, sfTrue);
    sfRenderWindow_setFramerateLimit(menu->window, 10);
    sfMusic_play(menu->music);
    sfMusic_setLoop(menu->music, sfTrue);
    sfText_setFont(menu->text_menu, font);
    return (1);
}

void    event(menu_t *menu)
{
    while (sfRenderWindow_pollEvent(menu->window, &menu->event)) {
        if (menu->event.type == sfEvtClosed) {
            sfMusic_destroy(menu->music);
            sfRenderWindow_close(menu->window);
        }
        if (menu->event.type == sfEvtKeyPressed &&
menu->event.key.code == sfKeyEscape) {
            sfMusic_destroy(menu->music);
            sfRenderWindow_close(menu->window);
        }
    }
}

int menu_window(int ac, char **av)
{
    menu_t menu;
    canoe_t canoe;

    if (!init(&menu, &canoe))
        return (1);
    while (sfRenderWindow_isOpen(menu.window)) {
        display_menu(&menu, &canoe, ac, av);
        sfRenderWindow_display(menu.window);
        event(&menu);
    }
    return 0;
}
