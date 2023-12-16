/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_char_side.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:32:54 by mgencali          #+#    #+#             */
/*   Updated: 2023/06/08 15:32:55 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	select_char_side(int keycode, t_data *data)
{
	if (keycode == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img.character_left,
			data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	if (keycode == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->img.character_right,
			data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	if (keycode == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img.character,
			data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	if (keycode == 13)
		mlx_put_image_to_window(data->mlx, data->win, data->img.character_back,
			data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
}
