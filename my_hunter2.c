/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** functions
*/

#include "my.h"

sfVector2f      create_vector(int x, int y)
{
	sfVector2f      vector;

	vector.x = x;
	vector.y = y;

	return (vector);
}

sfIntRect	create_rect2(int left, int top, int width, int height)
{
	sfIntRect	rect;

	rect.left = left;
	rect.top = top;
	rect.width = width;
	rect.height = height;

	return (rect);
}

sfIntRect	*create_rect(int left, int top, int width, int height)
{
	sfIntRect	*rect;
	rect = malloc(sizeof(*rect));
	rect->left = left;
	rect->top = top;
	rect->width = width;
	rect->height = height;

	return (rect);
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t	*buffer;
	
	buffer = malloc(sizeof(*buffer));
	buffer->width = width;
	buffer->height = height;
	buffer->pixels = malloc(sizeof(buffer->pixels));
	return(buffer);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
	free(framebuffer->pixels);
	free(framebuffer);
}
