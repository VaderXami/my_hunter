/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** functions
*/

#include "my.h"

void	draw_hearts(sfRenderWindow *window, sfSprite *heart_sprite, sfSprite *heart_sprite2, sfSprite *heart_sprite3)
{
	if (heart_sprite != NULL) 
		sfRenderWindow_drawSprite(window,heart_sprite, NULL);
	if(heart_sprite2 != NULL)
		sfRenderWindow_drawSprite(window, heart_sprite2, NULL);
	sfRenderWindow_drawSprite(window, heart_sprite3, NULL);
}

void	draw_sprites(sfRenderWindow *window, sfSprite *spritebackground, sfSprite *sprite, sfSprite *cross_sprite, sfText *score_text)
{
	sfRenderWindow_drawSprite(window, spritebackground, NULL);
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfRenderWindow_drawSprite(window, cross_sprite, NULL);
	sfRenderWindow_drawText(window, score_text, NULL);
}

sfSound		*create_sound(void)
{
	sfSound		*sound;
	
	sound = sfSound_create();
	return (sound);
}

sfSoundBuffer	*create_soundbuffer(char const *filename, sfSound *sound)
{
	sfSoundBuffer	*soundbuffer;

	soundbuffer = sfSoundBuffer_createFromFile(filename);
	sfSound_setBuffer(sound, soundbuffer);
	sfSound_play(sound);
	sfSound_setLoop(sound, sfTrue);
	return(soundbuffer);
}

void	display_score(int score, sfText *score_text,  sfSprite *sprite, sfVector2f setnewposition)
{
	char *score_char;
	
	my_putstr("Well Done !");
	my_putchar('\n');
	my_putstr("Score ");
	my_put_nbr(score);
	my_putchar('\n');
	score_char = my_set_nbr(score);
	sfText_setString(score_text, "Score");
	sfText_setString(score_text, score_char);
	setnewposition.x = 10;
	setnewposition.y = rand() % (769 + 1 - 110) + 0;
	sfSprite_setPosition(sprite, setnewposition);

	free(score_char);
}
