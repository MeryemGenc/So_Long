#include "so_long.h"

static void step_count(t_data *data)
{
    data->step_count++;
    ft_printf("Step: %d\r", data->step_count);
}

static  int real_walking(int y, int x, t_data *data) // gidilecek yön uygun mu? gidince yapılacak işlemler vs. kontroller halledilir
{
    if (data->map[data->player_y + y][data->player_x + x] == '1')
        return (0);
    else if (data->map[data->player_y + y][data->player_x + x] == 'C')
    {
        data->map[data->player_y + y][data->player_x + x] = '0';
        data->collected_coin++;
    }
    else if (data->map[data->player_y + y][data->player_x + x] == 'E')
    {
        if (data->collected_coin == data->coin_count)
        {
            exit_door(data);
            return (0);
        } 
    }
    return (1);
}

static  int walking(int keycode, t_data *data, int x) // kontroller sonrası sonuç olumlu ise yürütme işlemi gerçekleşir
{
    if (keycode == 0 || keycode == 2)
    {
        if (real_walking(0, x, data) == 0) // y koordinatı için 0 - x koordinatı iiçin x gönderiliyor
            return 0;
        mlx_put_image_to_window(data->mlx, data->win, data->img.bg, data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
        data->player_x += x;
    }
    if (keycode == 13 || keycode == 1)
    {
        if (real_walking(-x, 0, data) == 0) //y koordinatı için -x - x koordinatı için 0 gönderiliyor->neden '-':düz/ters yönde gitme bilgisi
            return 0;
        mlx_put_image_to_window(data->mlx, data->win, data->img.bg, data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
        data->player_y -= x;
    }
    step_count(data);
    press(data);
    return (0);
}

int press(t_data *data) // basılan tuşa göre gerekli işlemi yapar
{
    mlx_put_image_to_window(data->mlx, data->win, data->img.bg, data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
    mlx_put_image_to_window(data->mlx, data->win, data->img.character, data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
    if (data->map[data->exit_y][data->exit_x])
    {
        mlx_put_image_to_window(data->mlx, data->win, data->img.door, data->exit_x * IMG_SIZE, data->exit_y * IMG_SIZE);
        mlx_put_image_to_window(data->mlx, data->win, data->img.character, data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
    }
    return (0);
}

int key_hook(int keycode, t_data *data) // basılan tuşa göre fonksiyon çağırır
{
    if (keycode == 53)
        err_msg("Exit Success!");
    if (keycode == 2 || keycode == 13)
       walking(keycode, data, 1);
    if (keycode == 0 || keycode == 1)
       walking(keycode, data, -1);
    return (0);
}