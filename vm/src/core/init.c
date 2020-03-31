/*
** EPITECH PROJECT, 2019
** src/core/init
** File description:
** epitech > 42
*/

#include <stdlib.h>
#include "corwar.h"

static  int     init_text(menu_t *menu)
{
    sfFont  *font = sfFont_createFromFile(FONT);

    menu->text = sfText_create();
    if (!font || !menu->text)
        return (0);
    sfText_setFont(menu->text, font);
    sfText_setCharacterSize(menu->text, 40);
    sfSprite_setOrigin(menu->s_case, (sfVector2f){menu->size.x / 2,
menu->size.y / 2});
    menu->angl = 0;
    menu->stop = 1;
    return (1);

}

int     init_img(menu_t *menu, corewar_t *core)
{
    size_t i = 0;

    while (i < MEM_SIZE) {
        menu->color[i] = colorrf[(core->who[i] + 1) % 5];
        i++;
    }
    menu->t_case = sfTexture_createFromFile("diamant.jpg", NULL);
    menu->s_case = sfSprite_create();
    menu->t_fond = sfTexture_createFromFile("asura.jpg", NULL);
    menu->s_fond = sfSprite_create();
    if (!menu->t_case || !menu->s_case || !menu->t_fond || !menu->s_fond)
        return (0);
    sfSprite_setTexture(menu->s_case, menu->t_case, sfTrue);
    sfSprite_setTexture(menu->s_fond, menu->t_fond, sfTrue);
    sfSprite_setPosition(menu->s_fond, (sfVector2f){77, 0});
    menu->size = sfTexture_getSize(menu->t_case);
    menu->start = (sfVector2f){50, 150};
    if (!init_text(menu))
        return (0);
    return (1);
}
