/*
** EPITECH PROJECT, 2017
** window
** File description:
** window
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

int	display_usage2(int ac, char **av)
{
	if(ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
		display_usage();
		return EXIT_SUCCESS;
	}
	else if(ac == 2 && av[1][0] == '-' && av[1][1] == 'g') {
		window_usage();
		return EXIT_SUCCESS;
	}
	else if(ac > 2)
		return (84);

	return EXIT_SUCCESS;
}

int main(int ac, char **av)
{
	sfVideoMode	mode = {1280, 769, 32};
	int		score = 0;
	int		missed = 0;
	sfClock		*clock;
	sfFont		*arial_font;
	sfText		*score_text;
	sfRenderWindow	*window;
	sfTexture	*texture;
	sfTexture	*background;
	sfTexture	*cross_texture;
	sfTexture	*heart_texture;
	sfTexture	*heart_texture2;
	sfTexture	*heart_texture3;
	sfSprite	*sprite;
	sfSprite	*heart_sprite;
	sfSprite	*heart_sprite2;
	sfSprite	*heart_sprite3;
	sfSprite	*cross_sprite;
	sfSprite	*spritebackground;
	sfIntRect	intrect1;
	sfIntRect	*heart_rect;
	sfIntRect	*cross_rect;
	sfIntRect	*intrect4;
	sfEvent		event;
	sfSoundBuffer	*soundbuffer;
	sfSound		*sound;
	int		pressed;
	framebuffer_t	*framebuffer;
	sfVector2f	movementxy;
	sfVector2i	mouse_x_y;
	sfVector2f	score_position;
	sfVector2f	mouse_position2;
	sfVector2f	position;
	sfVector2f	newPosition;
	sfVector2i	mouseposition;
	sfVector2f	setnewposition;
	sfVector2f	heart_position;
	sfVector2f	heart_position2;
	sfVector2f	heart_position3;
	sfFloatRect	test;

	if(ac != 1) {
		display_usage2(ac, av);
		return (0);
	}

	window = sfRenderWindow_create(mode, "Cyber Vader {EPITECH} 2.0", sfResize | sfClose, NULL);

	framebuffer = framebuffer_create(1280, 769);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	sfRenderWindow_setFramerateLimit(window, 60);

	intrect1 = create_rect2(0, 0, 110, 110);
	clock = sfClock_create();

	intrect4 = create_rect(0, 0, 1280, 769);
	cross_rect = create_rect(0, 0, 61, 61);
	heart_rect = create_rect(0, 0, 16, 16);
	
	movementxy.x = 10;
	movementxy.y = 0;
	
	score_position = create_vector(10, 10);
	heart_position = create_vector(100, 10);
	heart_position2 = create_vector(110, 10);
	heart_position3 = create_vector(120, 10);
	
	background = sfTexture_createFromFile("background.png", intrect4);
	texture = sfTexture_createFromFile("spritesheet.png", NULL);
	cross_texture = sfTexture_createFromFile("cross.png", cross_rect);
	heart_texture = sfTexture_createFromFile("heart.png", heart_rect);
	heart_texture2 = sfTexture_createFromFile("heart2.png", heart_rect);
	heart_texture3 = sfTexture_createFromFile("heart3.png", heart_rect);
     
	if (!texture)
		return EXIT_FAILURE;
	
	spritebackground = sfSprite_create();
	sprite = sfSprite_create();
	heart_sprite = sfSprite_create();
	heart_sprite2 = sfSprite_create();
	heart_sprite3 = sfSprite_create();
	cross_sprite = sfSprite_create();
	Set_Texture1(sprite, spritebackground, cross_sprite, texture, background, cross_texture);
	Set_Texture2(heart_sprite, heart_sprite2, heart_sprite3, heart_texture, heart_texture2, heart_texture3);
	sfSprite_setPosition(sprite, movementxy);
	sfSprite_setPosition(heart_sprite, heart_position);
	sfSprite_setPosition(heart_sprite2, heart_position2);
	sfSprite_setPosition(heart_sprite3, heart_position3);
	score_text = create_text();
	arial_font = create_font("arial.ttf", score_text, score_position, 30);
	sound = create_sound();
	soundbuffer = create_soundbuffer("ducksound.wav", sound);
	
	while (sfRenderWindow_isOpen(window)) {
		test = sfSprite_getGlobalBounds(sprite);
		position = sfSprite_getPosition(sprite);
		mouseposition = sfMouse_getPositionRenderWindow(window);
		mouse_x_y = sfMouse_getPositionRenderWindow(window);
		mouse_position2.x = (float)mouse_x_y.x - (55 / 2);
		mouse_position2.y = (float)mouse_x_y.y - (55 / 2);
		sfSprite_setPosition(cross_sprite, mouse_position2);
		if(sfClock_getElapsedTime(clock).microseconds > 40000)
			intrect1 = animation(sprite, intrect1, movementxy, clock, 220, 110);
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
			pressed = sfMouse_isButtonPressed(sfMouseLeft);
			if(sfFloatRect_contains(&test, mouseposition.x, mouseposition.y) == sfTrue && pressed == 1) {
				score += 1;
				movementxy.x += 5;
				display_score(score, score_text, sprite, setnewposition);
			}
			else if(sfFloatRect_contains(&test, mouseposition.x, mouseposition.y) != sfTrue && pressed == 1) {
				missed++;
				my_putstr("Too Bad !");
				my_putchar('\n');
				my_putstr("Missed ");
				my_put_nbr(missed);
				my_putchar('\n');
				
				if(missed == 1) {
					sfSprite_destroy(heart_sprite);
					heart_sprite = NULL;
				}
				else if(missed == 2) {
					sfSprite_destroy(heart_sprite2);
					heart_sprite2 = NULL;
				}
				else if(missed == 3) {
					my_putstr("Final Score: ");
					my_put_nbr(score);
					my_putchar('\n');
					my_putstr("Final Missed: ");
					my_put_nbr(missed);
					my_putchar('\n');
					framebuffer_destroy(framebuffer);
					destroy_sprites(sprite, spritebackground, cross_sprite);
					destroy_hearts(heart_sprite, heart_sprite2, heart_sprite3);
					destroy_texture(cross_texture, texture, background);
					destroy_heart_texture(heart_texture, heart_texture2, heart_texture3);
					destroy_ft(arial_font, score_text);
					destroy_sound(sound, soundbuffer);
					sfRenderWindow_destroy(window);
					return EXIT_SUCCESS;
				}
			}
		}
		if (position.x > 1280) {
			newPosition.x = 0;
			newPosition.y = rand() % (769 + 1 - 110) + 0;
			sfSprite_setPosition(sprite, newPosition);
		}
		sfRenderWindow_clear(window, sfBlack);
		draw_sprites(window, spritebackground, sprite, cross_sprite, score_text);
		draw_hearts(window, heart_sprite, heart_sprite2, heart_sprite3);
		sfRenderWindow_display(window);
	}
	destroy_sprites(sprite, spritebackground, cross_sprite);
	destroy_texture(cross_texture, texture, background);
	destroy_hearts(heart_sprite, heart_sprite2, heart_sprite3);
	destroy_ft(arial_font, score_text);
	destroy_sound(sound, soundbuffer);
	framebuffer_destroy(framebuffer);
	sfRenderWindow_destroy(window);
	return EXIT_SUCCESS;
}
