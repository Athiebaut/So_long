/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:32:35 by athiebau          #+#    #+#             */
/*   Updated: 2023/09/07 14:59:16 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

void	print_movements(t_game *so_long)
{
	char	*str;
	
	str = ft_itoa(so_long->p_moove - 1);
	if (!str)
		ft_free(so_long, 3);
	mlx_string_put(so_long->mlx, so_long->mlx_win,
		(so_long->pixel * so_long->map_x) + 5, 10, 0x80ff0000,
		"Mouvements :");
	mlx_string_put(so_long->mlx, so_long->mlx_win,
		(so_long->pixel * so_long->map_x) + 80, 10, 0x80000000,
		str);
	free(str);
	str = ft_itoa(so_long->p_moove);
	if (!str)
		ft_free(so_long, 3);
	mlx_string_put(so_long->mlx, so_long->mlx_win,
		(so_long->pixel * so_long->map_x) + 80, 10, 0x80ff0000,
		str);
	free(str);
}

void	up(t_game *so_long)
{
	so_long->p_moove++;
	if (so_long->map[so_long->p_y - 1][so_long->p_x] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y - 1][so_long->p_x] == 'A')
	{
		ft_printf("YOU LOSE. Try again ?\n");
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
	if (so_long->map[so_long->p_y + 1][so_long->p_x] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y + 1][so_long->p_x] == 'A')
	{
		ft_printf("YOU LOSE. Try again ?\n");
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
	if (so_long->map[so_long->p_y][so_long->p_x + 1] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y][so_long->p_x + 1] == 'A')
	{
		ft_printf("YOU LOSE. Try again ?\n");
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
	if (so_long->map[so_long->p_y][so_long->p_x - 1] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y][so_long->p_x - 1] == 'A')
	{
		ft_printf("YOU LOSE. Try again ?\n");
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
	int	y;
	int	x;

	y = so_long->p_y;
	x = so_long->p_x;
	if (keycode == 65307)
		close_window(so_long);
	if (keycode == 119 && ((so_long->points != 0 && so_long->map[y - 1][x]
			!= 'E' && so_long->map[y - 1][x] != '1') || (so_long->points
			== 0 && so_long->map[y - 1][x] != '1')))
		up(so_long);
	if (keycode == 115 && ((so_long->points != 0 && so_long->map[y + 1][x]
			!= 'E' && so_long->map[y + 1][x] != '1') || (so_long->points
			== 0 && so_long->map[y + 1][x] != '1')))
		down(so_long);
	if (keycode == 100 && ((so_long->points != 0 && so_long->map[y][x + 1]
			!= 'E' && so_long->map[y][x + 1] != '1') || (so_long->points
			== 0 && so_long->map[y][x + 1] != '1')))
		right(so_long);
	if (keycode == 97 && ((so_long->points != 0 && so_long->map[y][x - 1]
			!= 'E' && so_long->map[y][x - 1] != '1') || (so_long->points
			== 0 && so_long->map[y][x - 1] != '1')))
		left(so_long);
	return (0);
}
