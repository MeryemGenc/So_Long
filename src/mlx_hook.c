/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:01:57 by mgencali          #+#    #+#             */
/*   Updated: 2023/06/08 15:32:34 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 2, key_hook, data);
	mlx_hook(data->win, 17, 1L << 2, mouse_hook, data);
}
