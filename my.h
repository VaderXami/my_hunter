/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** project my_hunter
*/
#ifndef _MY_H_
#define _MY_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window/Context.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/JoystickIdentification.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <SFML/Window/Touch.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/Window.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/System/Export.h>
#include <SFML/System.h>
#include <SFML/Audio/Listener.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/SoundBufferRecorder.h>
#include <SFML/Audio/SoundRecorder.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/SoundStream.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/FontInfo.h>
#include <SFML/Graphics/Glyph.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/Graphics/Export.h>
#include <stddef.h>
#include <unistd.h>

void	my_putchar(char c);
int	my_putstr(char *str);
int	my_put_nbr(int nb);
char	*my_set_nbr(int nb);

sfIntRect	*create_rect(int left, int top, int width, int height);
sfIntRect	create_rect2(int left, int top, int width, int height);
sfIntRect	animation(sfSprite *sprite, sfIntRect rect, sfVector2f movementxy, sfClock *clock, int x, int y);
sfVector2f	create_vector(int x, int y);
void	destroy_texture(sfTexture *cross_texture, sfTexture *texture, sfTexture *background);
void	destroy_heart_texture(sfTexture *heart_texture, sfTexture *heart_texture2, sfTexture *heart_texture3);
void	destroy_sound(sfSound *sound, sfSoundBuffer *soundbuffer);
void	destroy_sprites(sfSprite *sprite, sfSprite *spritebackground, sfSprite *cross_sprite);
void	destroy_hearts(sfSprite *heart_sprite, sfSprite *heart_sprite2, sfSprite *heart_sprite3);
void	draw_hearts(sfRenderWindow *window, sfSprite *heart_sprite, sfSprite *heart_sprite2, sfSprite *heart_sprite3);
void	draw_sprites(sfRenderWindow *window, sfSprite *spritebackground, sfSprite *sprite, sfSprite *cross_sprite, sfText *score_text);
void	display_usage(void);
sfSound		*create_sound(void);
sfSoundBuffer	*create_soundbuffer(char const *filename, sfSound *sound);
void	display_score(int score, sfText *score_text,  sfSprite *sprite, sfVector2f setnewposition);
sfText	*create_text(void);
sfFont	*create_font(char const *filename, sfText *text, sfVector2f position, int size);
void	destroy_ft(sfFont *font, sfText *text);
void	Set_Texture1(sfSprite *sprite, sfSprite *cross_sprite, sfSprite *spritebackground, sfTexture *texture, sfTexture *cross_texture, sfTexture *background);
void	Set_Texture2(sfSprite *heart_sprite, sfSprite *heart_sprite2, sfSprite *heart_sprite3, sfTexture *heart_texture, sfTexture *heart_texture2, sfTexture *heart_texture3);
sfWindow	*window_usage(void);

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};

typedef struct framebuffer framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);

#endif /*_MY_H_*/
