/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:37:29 by athiebau          #+#    #+#             */
/*   Updated: 2023/09/06 13:52:43 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

static void	update_map(t_game *so_long)
{
	so_long->y = 0;
	while ((so_long->y) < (so_long->map_y))
	{
		so_long->x = 0;
		while ((so_long->x) < (so_long->map_x))
		{
			if (so_long->map[so_long->y][so_long->x] == 'A')
				place_enemy(so_long);
			if (so_long->map[so_long->y][so_long->x] == 'P')	
				place_player(so_long);
			if (so_long->map[so_long->y][so_long->x] == 'C')	
				place_points(so_long);
			so_long->x++;
		}
		so_long->y++;
	}
	so_long->x = 0;
	so_long->y = 0;
}

int	frames(t_game *so_long)
{
	static int	i;

	i = 0;
	if (i < 30)
		so_long->points_file = "./Img/coin1.xpm";
	if (i < 40)
	{
		so_long->enemy_file = "./Img/enemy1.xpm";
		so_long->player_file = "./Img/player1.xpm";
	}
	if (i > 30 && i < 60)
		so_long->points_file = "./Img/coin2.xpm";
	if (i > 40 && i < 80)
	{
		so_long->enemy_file = "./Img/enemy2.xpm";
		so_long->player_file = "./Img/player2.xpm";
	}
	if (i > 60)
		so_long->points_file = "./Img/coin3.xpm";
	if (i > 80)
	{
		so_long->enemy_file = "./Img/enemy3.xpm";
		so_long->player_file = "./Img/player3.xpm";
		so_long->points_file = "./Img/coin4.xpm";
	}
	if (i == 120)
		i = 0;
	update_map(so_long);
	i++;
	return 0;
}
