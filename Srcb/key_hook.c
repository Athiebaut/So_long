/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:32:35 by athiebau          #+#    #+#             */
/*   Updated: 2023/09/04 15:23:39 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	up(t_game *so_long)
{
	so_long->p_moove++;
	ft_printf("Mouvements : %d\n", so_long->p_moove);
	if (so_long->map[so_long->p_y - 1][so_long->p_x] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}	
	if (so_long->map[so_long->p_y - 1][so_long->p_x] == 'C')
		so_long->points--;
	so_long->map[so_long->p_y][so_long->p_x] = '0';
	so_long->map[so_long->p_y - 1][so_long->p_x] = 'P';
	fill_window(so_long);
}

void	down(t_game *so_long)
{
	so_long->p_moove++;
	ft_printf("Mouvements : %d\n", so_long->p_moove);
	if (so_long->map[so_long->p_y + 1][so_long->p_x] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y + 1][so_long->p_x] == 'C')
		so_long->points--;
	so_long->map[so_long->p_y][so_long->p_x] = '0';
	so_long->map[so_long->p_y + 1][so_long->p_x] = 'P';
	fill_window(so_long);
}

void	right(t_game *so_long)
{
	so_long->p_moove++;
	ft_printf("Mouvements : %d\n", so_long->p_moove);
	if (so_long->map[so_long->p_y][so_long->p_x + 1] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y][so_long->p_x + 1] == 'C')
		so_long->points--;
	so_long->map[so_long->p_y][so_long->p_x] = '0';
	so_long->map[so_long->p_y][so_long->p_x + 1] = 'P';
	fill_window(so_long);
}

void	left(t_game *so_long)
{
	so_long->p_moove++;
	ft_printf("Mouvements : %d\n", so_long->p_moove);
	if (so_long->map[so_long->p_y][so_long->p_x - 1] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y][so_long->p_x - 1] == 'C')
		so_long->points--;
	so_long->map[so_long->p_y][so_long->p_x] = '0';
	so_long->map[so_long->p_y][so_long->p_x - 1] = 'P';
	fill_window(so_long);
}

int	key_hook(int keycode, t_game *so_long)
{
	if (keycode == 65307)
		close_window(so_long);
	if (keycode == 119 && ((so_long->points != 0
		&& so_long->map[so_long->p_y - 1][so_long->p_x] != 'E'
		&& so_long->map[so_long->p_y - 1][so_long->p_x] != '1')
		|| (so_long->points == 0 
		&& so_long->map[so_long->p_y - 1][so_long->p_x] != '1')))
		up(so_long);
	if (keycode == 115 && ((so_long->points != 0
		&& so_long->map[so_long->p_y + 1][so_long->p_x] != 'E'
		&& so_long->map[so_long->p_y + 1][so_long->p_x] != '1')
		|| (so_long->points == 0 
		&& so_long->map[so_long->p_y + 1][so_long->p_x] != '1')))
		down(so_long);
	if (keycode == 100 && ((so_long->points != 0
		&& so_long->map[so_long->p_y][so_long->p_x + 1] != 'E'
		&& so_long->map[so_long->p_y][so_long->p_x + 1] != '1')
		|| (so_long->points == 0 
		&& so_long->map[so_long->p_y][so_long->p_x + 1] != '1')))
		right(so_long);
	if (keycode == 97 && ((so_long->points != 0
		&& so_long->map[so_long->p_y][so_long->p_x - 1] != 'E'
		&& so_long->map[so_long->p_y][so_long->p_x - 1] != '1')
		|| (so_long->points == 0 
		&& so_long->map[so_long->p_y][so_long->p_x - 1] != '1')))
		left(so_long);
	return (0);
}
