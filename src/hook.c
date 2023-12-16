/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:02:07 by mgencali          #+#    #+#             */
/*   Updated: 2023/06/07 14:54:36 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	step_count(t_data *data)
{
	data->step_count++;
	ft_printf("Step: %d\r", data->step_count);
}

static int	real_walking(int y, int x, t_data *data)
{
	if (data->map[data->player_y + y][data->player_x + x] == '1')
		return (0);
	else if (data->map[data->player_y + y][data->player_x + x] == 'C')
	{
		data->map[data->player_y + y][data->player_x + x] = '0';
		data->coin_collected++;
	}
	else if (data->map[data->player_y + y][data->player_x + x] == 'E')
	{
		if (data->coin_collected == data->coin_count)
		{
			exit_door(data);
			return (0);
		}
	}
	return (1);
}

static int	walking(int keycode, t_data *data, int x)
{
	if (keycode == 0 || keycode == 2)
	{
		if (real_walking(0, x, data) == 0)
			return (0);
		mlx_put_image_to_window(data->mlx, data->win, data->img.bg,
			data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
			data->player_x += x;
	}
	if (keycode == 13 || keycode == 1)
	{
		if (real_walking(-x, 0, data) == 0)
			return (0);
		mlx_put_image_to_window(data->mlx, data->win, data->img.bg,
			data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
		data->player_y -= x;
	}
	step_count(data);
	press(keycode, data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		err_msg("Exit Success");
	else if (keycode == 2 || keycode == 13)
		walking(keycode, data, 1);
	else if (keycode == 0 || keycode == 1)
		walking(keycode, data, -1);
	return (0);
}

int	press(int keycode, t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.bg,
		data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	select_char_side(keycode, data);
	if (data->map[data->exit_y][data->exit_x])
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img.door,
			data->exit_x * IMG_SIZE, data->exit_y * IMG_SIZE);
		select_char_side(keycode, data);
	}
	return (0);
}
