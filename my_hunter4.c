/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** functions
*/

#include "my.h"

void	destroy_texture(sfTexture *cross_texture, sfTexture *texture, sfTexture *background)
{
	sfTexture_destroy(cross_texture);
	sfTexture_destroy(texture);
	sfTexture_destroy(background);

}

void	destroy_heart_texture(sfTexture *heart_texture, sfTexture *heart_texture2, sfTexture *heart_texture3)
{
	sfTexture_destroy(heart_texture);
	sfTexture_destroy(heart_texture2);
	sfTexture_destroy(heart_texture3);
}

void	destroy_sound(sfSound *sound, sfSoundBuffer *soundbuffer)
{
	sfSound_stop(sound);
	sfSoundBuffer_destroy(soundbuffer);
	sfSound_destroy(sound);
}

void	destroy_sprites(sfSprite *sprite, sfSprite *spritebackground, sfSprite *cross_sprite)
{
	sfSprite_destroy(sprite);
	sfSprite_destroy(spritebackground);
	sfSprite_destroy(cross_sprite);
}

void	destroy_hearts(sfSprite *heart_sprite, sfSprite *heart_sprite2, sfSprite *heart_sprite3)
{
	sfSprite_destroy(heart_sprite);
	sfSprite_destroy(heart_sprite2);
	sfSprite_destroy(heart_sprite3);
}
