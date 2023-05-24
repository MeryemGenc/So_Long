#ifndef SO_LONG_H
# define SOLONG_H

# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define IMG_SIZE 100    // Anlatsana biraz, neden 100?
/*
    -> Libft kullanılmayan fonksiyonları sil.
    -> Struct'lardaki her 1 değişken ne işe yarar?
    -> her bir fonksiyon ne işe yarar?
    -> get_next_line -> libft içinde ondaki yorum satırlarına bak - kaldır



    -> tüm yorum satırlarını temizle
*/

typedef struct s_image
{
    char *character;
    char *wall;
    char *coin;
    char *door;
    char *bg;
    int img_width;
    int img_height;
} t_image;

typedef struct s_int_map
{
    int read_count;
} t_int_map;

typedef struct s_data
{
    char    **map;
    char    *mlx;
    char    *win;
    char    *tmp_map; // eski isim: map_tmp
    int     map_width;
    int     map_height;
    int     player_x;
    int     player_y;
    int     player_count;
    int     exit_count;
    int     exit_x;
    int     exit_y;
    int     wall_count;
    int     coin_count;
    int     unwanted_char_count; // unwanted_character_count
    int     collected_coin; // coin_collected
    int     step_count;
    t_image img;
    t_int_map i_map;
} t_data;

// main.c
void err_msg(char *message);
int mouse_hook(int mousecode, t_data *data);
int exit_door(t_data *data);

// Map control 
void map_control(char **argv, t_data *data);
void tmp_control(char *map_name);
void ber_control(char *map_name);

// size control
void size_control(t_data *data);
void wall_control(t_data *data);
void min_element_control(t_data *data);

// mlx create
void image_create(t_data *data);
void map_read(t_data *data); 
void mlx_create(t_data *data);

// hook
int press(t_data *data);
int key_hook(int keycode, t_data *data);

// mlx_put
void map_put(int i, int j, t_data *data);
void map_create(t_data *data);
void map_background_put(t_data *data);

#endif