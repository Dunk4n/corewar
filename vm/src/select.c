/*
** EPITECH PROJECT, 2019
** src/select
** File description:
** fireplace 4k
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "my.h"

int     init_select(menu_t *menu)
{
    menu->choose = sfMusic_createFromFile(CHOOSE_MUSIC);
    menu->t_sfond = sfTexture_createFromFile("img/choose.png", NULL);
    menu->s_sfond = sfSprite_create();
    menu->t_1 = sfTexture_createFromFile("img/1.png", NULL);
    menu->s_1 = sfSprite_create();
    menu->t_42 = sfTexture_createFromFile("img/42.png", NULL);
    menu->s_42 = sfSprite_create();
    menu->t_octo = sfTexture_createFromFile("img/octobre.png", NULL);
    menu->s_octo = sfSprite_create();
    menu->t_vic = sfTexture_createFromFile("img/victorious.png", NULL);
    menu->s_vic = sfSprite_create();
    menu->t_zork = sfTexture_createFromFile("img/zork.png", NULL);
    menu->s_zork = sfSprite_create();
    menu->t_wa = sfTexture_createFromFile("img/wagnerita.png", NULL);
    menu->s_wa = sfSprite_create();
    if (!menu->t_sfond || !menu->s_sfond || !menu->t_1 || !menu->s_1 ||
!menu->t_42 || !menu->s_42 || !menu->t_octo || !menu->s_octo || !menu->t_vic ||
!menu->s_vic || !menu->t_zork || !menu->s_zork || !menu->t_wa || !menu->s_wa)
        return (0);
    sfMusic_play(menu->choose);
    sfMusic_setLoop(menu->choose, sfTrue);
    sfMusic_setVolume(menu->choose, 30);
    sfSprite_setTexture(menu->s_sfond, menu->t_sfond, sfTrue);
    sfSprite_setPosition(menu->s_1, (sfVector2f){100, 300});
    sfSprite_setTexture(menu->s_1, menu->t_1, sfTrue);
    sfSprite_setPosition(menu->s_42, (sfVector2f){390, 300});
    sfSprite_setTexture(menu->s_42, menu->t_42, sfTrue);
    sfSprite_setPosition(menu->s_octo, (sfVector2f){680, 300});
    sfSprite_setTexture(menu->s_octo, menu->t_octo, sfTrue);
    sfSprite_setPosition(menu->s_vic, (sfVector2f){970, 300});
    sfSprite_setTexture(menu->s_vic, menu->t_vic, sfTrue);
    sfSprite_setPosition(menu->s_zork, (sfVector2f){1260, 300});
    sfSprite_setTexture(menu->s_zork, menu->t_zork, sfTrue);
    sfSprite_setPosition(menu->s_wa, (sfVector2f){1550, 300});
    sfSprite_setTexture(menu->s_wa, menu->t_wa, sfTrue);
    sfText_setCharacterSize(menu->text_menu, 40);
    sfText_setColor(menu->text_menu, sfRed);
    return (1);
}

void    display_select(menu_t *menu)
{
    sfRenderWindow_drawSprite(menu->window, menu->s_sfond, NULL);
    sfRenderWindow_drawSprite(menu->window, menu->s_1, NULL);
    sfRenderWindow_drawSprite(menu->window, menu->s_42, NULL);
    sfRenderWindow_drawSprite(menu->window, menu->s_octo, NULL);
    sfRenderWindow_drawSprite(menu->window, menu->s_vic, NULL);
    sfRenderWindow_drawSprite(menu->window, menu->s_zork, NULL);
    sfRenderWindow_drawSprite(menu->window, menu->s_wa, NULL);
}

int     clic_p(menu_t *menu)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(menu->window);
    int     pos[] = {100, 390, 680, 970, 1260, 1550};
    size_t  i = 0;

    while (i < 6) {
        if (mouse.x >= pos[i] && mouse.x <= pos[i] + 270 &&
mouse.y >= 300 && mouse.y <= 570 && sfMouse_isButtonPressed(sfMouseLeft)) {
            return (i);
        }
        i++;
    }
    return (-1);
}

void    store(menu_t *menu, int *tab)
{
    int     tmp = clic_p(menu);
    size_t  i = 0;

    while (tmp > -1 && i < 4) {
        if (tab[i] == -1) {
            tab[i] = tmp;
            return ;
        }
        i++;
    }
}

void    display_core(menu_t *menu, int *tab)
{
    size_t  i = 0;
    int     pos[] = {100, 580, 1050, 1530};
    char    *name[] = {"1", "42", "octobre", "baby", "zork", "wagnerita"};

    while (i < 4) {
        if (tab[i] >= 0) {
            sfText_setPosition(menu->text_menu, (sfVector2f){pos[i], 960});
            sfText_setString(menu->text_menu, name[tab[i] % 6]);
            sfRenderWindow_drawText(menu->window, menu->text_menu, NULL);
        }
        i++;
    }
}

void    send_prog(menu_t *menu, int *tab, int fg)
{
    char    *name_const[] = {"./champ/1.cor", "./champ/42.cor", "./champ/octobre.cor", "./champ/baby.cor", "./champ/zork.cor", "./champ/wagnerita_vf.cor"};
    char    *name[6] = {"corewar", NULL, NULL, NULL, NULL, NULL};
    size_t  i = 0;

    while (tab[i] >= 0 && i < 4) {
        name[i + 1] = name_const[tab[i] % 6];
        i++;
    }
    if (i > 0)
        start_core_war(i + 1, name, menu, fg);
}

int     event_p(menu_t *menu, int *tab, int fg)
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
        if (menu->event.type == sfEvtKeyPressed &&
menu->event.key.code == sfKeyReturn && tab[0] >= 0 && tab[1] >= 0) {
            send_prog(menu, tab, fg);
            return (0);
        }
    }
    return (1);
}

void    select_p(menu_t *menu, int ac, char **av, int fg)
{
    int tab[4] = {-1, -1, -1, -1};

    if (ac > 1) {
        start_core_war(ac, av, menu, fg);
        return ;
    }
    if (!init_select(menu))
        return ;
    while (sfRenderWindow_isOpen(menu->window)) {
        store(menu, tab);
        display_select(menu);
        display_core(menu, tab);
        sfRenderWindow_display(menu->window);
        if (!event_p(menu, tab, fg))
            return ;
    }
}
