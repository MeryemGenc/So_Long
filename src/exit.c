/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:02:13 by mgencali          #+#    #+#             */
/*   Updated: 2023/06/07 14:33:23 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msg(char *msg)
{
	ft_printf("%s", msg);
	exit (0);
}

int	mouse_hook(int mousecode, t_data *data)
{
	(void)mousecode;
	(void)data;
	err_msg("Exit Success");
	return (0);
}

void	exit_door(t_data *data)
{
	if (data->coin_collected != data->coin_count)
		return ;
	ft_printf("\n>>>> Move Count: %d\n", data->step_count);
	err_msg("FINISH");
}
