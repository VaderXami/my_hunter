/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** functions
*/

#include "my.h"

sfWindow	 *window_usage(void)
{
	sfVideoMode mode = {1920, 1090, 32};
	sfRenderWindow* window;
	sfTexture* texture;
	sfSprite* sprite;
	sfEvent event;
	sfIntRect	*rect;
	framebuffer_t *framebuffer;
	
	window = sfRenderWindow_create(mode, "Usage Window", sfResize | sfClose, NULL);	
	framebuffer = framebuffer_create(800, 600);
	rect = create_rect(0, 0, 1920, 1090);
	texture = sfTexture_createFromFile("bacground1.png", rect);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfRenderWindow_setFramerateLimit(window, 62);
	while (sfRenderWindow_isOpen(window))
	{
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfRenderWindow_display(window);
	}
	framebuffer_destroy(framebuffer);
	sfSprite_destroy(sprite);
	sfTexture_destroy(texture);
	sfRenderWindow_destroy(window);
	return EXIT_SUCCESS;
}

void	display_usage(void)
{
	my_putchar('\n');
	my_putstr("my_hunter created with CSFML by: Cyber Vader\n");
	my_putchar('\n');
	my_putstr("USAGE\n");
	my_putstr("   ./my_hunter\n");
	my_putchar('\n');
	my_putstr("OPTIONS");
	my_putchar('\n');
	my_putstr("-h           print the usage and quit.\n");
	my_putstr("-g           display the example in graphical mode\n");
	my_putchar('\n');
	my_putstr("USER INTERACTIONS\n");
	my_putstr(" MOUSE(Left Key)   SHOOT.\n");
}

sfIntRect	animation(sfSprite *sprite, sfIntRect rect, sfVector2f vector, sfClock *clock, int x, int left)
{
	if(rect.left == x)
	{
		rect.left = 0;
	}
	else
		rect.left = rect.left + left;
	sfSprite_setTextureRect(sprite, rect);
	sfSprite_move(sprite, vector);
	sfClock_restart(clock);
	return (rect);
}

