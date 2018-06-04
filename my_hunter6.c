/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** functions
*/

#include "my.h"

sfText	*create_text(void)
{
	sfText	*text;

	text = sfText_create();
	return (text);
}

sfFont	*create_font(char const *filename, sfText *text, sfVector2f position, int size)
{
	sfFont	*font;
	
	font = sfFont_createFromFile(filename);
	sfText_setFont(text, font);
	sfText_setPosition(text, position);
	sfText_setCharacterSize(text, size);
	return (font);
}

void	destroy_ft(sfFont *font, sfText *text)
{
	sfFont_destroy(font);
	sfText_destroy(text);
}

void	Set_Texture1(sfSprite *sprite, sfSprite *cross_sprite, sfSprite *spritebackground, sfTexture *texture, sfTexture *cross_texture, sfTexture *background)
{
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setTexture(cross_sprite, cross_texture, sfTrue);
	sfSprite_setTexture(spritebackground, background, sfTrue);
	sfTexture_setSmooth(texture, sfTrue);
	sfTexture_setSmooth(background, sfTrue);
	sfTexture_setSmooth(cross_texture, sfTrue);
}

void	Set_Texture2(sfSprite *heart_sprite, sfSprite *heart_sprite2, sfSprite *heart_sprite3, sfTexture *heart_texture, sfTexture *heart_texture2, sfTexture *heart_texture3)
{
	sfSprite_setTexture(heart_sprite, heart_texture, sfTrue);
	sfSprite_setTexture(heart_sprite2, heart_texture2, sfTrue);
	sfSprite_setTexture(heart_sprite3, heart_texture3, sfTrue);
	sfTexture_setSmooth(heart_texture, sfTrue);
	sfTexture_setSmooth(heart_texture2, sfTrue);
	sfTexture_setSmooth(heart_texture3, sfTrue);
}

