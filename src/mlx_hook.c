#include "so_long.h"

void hook(t_data *data)
{
    mlx_hook(data->win, 2, 1L << 2, key_hook, data);
    mlx_hook(data->win, 17, 1L << 2, mouse_hook, data);
}


