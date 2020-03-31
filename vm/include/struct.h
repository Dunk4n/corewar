/*
** EPITECH PROJECT, 2019
** main
** File description:
** struct
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include "op.h"

typedef struct menu_interface_s {
    sfEvent     event;
    sfMusic     *music;
    sfMusic     *choose;
    sfRenderWindow      *window;
    sfSprite    *s_menu;
    sfTexture   *t_menu;
    sfSprite    *s_case;
    sfTexture   *t_case;
    sfSprite    *s_fond;
    sfTexture   *t_fond;
    sfText      *text;
    sfText      *text_menu;
    sfVector2u  size;
    sfVector2f  start;
    sfColor     color[MEM_SIZE];
    int         angl;
    int         stop;
    sfSprite    *s_sfond;
    sfTexture   *t_sfond;
    sfSprite    *s_1;
    sfTexture   *t_1;
    sfSprite    *s_42;
    sfTexture   *t_42;
    sfSprite    *s_octo;
    sfTexture   *t_octo;
    sfSprite    *s_vic;
    sfTexture   *t_vic;
    sfSprite    *s_zork;
    sfTexture   *t_zork;
    sfSprite    *s_wa;
    sfTexture   *t_wa;
}menu_t;

typedef struct canoe_s {
    sfTime time;
    sfClock *clock;
    float seconds;
    sfEvent event;
    sfRenderWindow *window;
    sfSprite *s_canoe;
    sfTexture *t_canoe;
}canoe_t;
