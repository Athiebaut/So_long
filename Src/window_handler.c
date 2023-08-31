/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:05:11 by alix              #+#    #+#             */
/*   Updated: 2023/08/31 16:58:10 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	close_window(t_game *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	ft_free(so_long, 0);
	exit(1);
}

void	fill_window(t_game *so_long)
{
	so_long->y = 0;
	while ((so_long->y) < (so_long->map_y))
	{
		so_long->x = 0;
		while ((so_long->x) < (so_long->map_x))
		{
			if (so_long->map[so_long->y][so_long->x] == '1')
				place_borders(so_long);
			if (so_long->map[so_long->y][so_long->x] == '0')
				place_floor(so_long);
			if (so_long->map[so_long->y][so_long->x] == 'P')
				place_player(so_long);
			if (so_long->map[so_long->y][so_long->x] == 'C')
				place_points(so_long);
			if (so_long->map[so_long->y][so_long->x] == 'E')
				place_exit(so_long);
			so_long->x++;
		}
		so_long->y++;
	}
	ft_printf("Mouvements : %d\n", so_long->p_moove);
}
