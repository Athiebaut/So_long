/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:37:29 by athiebau          #+#    #+#             */
/*   Updated: 2023/09/07 14:52:19 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

int	frames(t_game *so_long)
{
	static int	i;

	if (i < 3)
		so_long->points_file = "./Img/coin1.xpm";
	if (i < 4)
	{
		so_long->enemy_file = "./Img/enemy1.xpm";
		so_long->player_file = "./Img/player1.xpm";
	}
	if (i > 3 && i < 6)
		so_long->points_file = "./Img/coin2.xpm";
	if (i > 4 && i < 8)
	{
		so_long->enemy_file = "./Img/enemy2.xpm";
		so_long->player_file = "./Img/player2.xpm";
	}
	if (i > 6)
		so_long->points_file = "./Img/coin3.xpm";
	if (i > 8)
	{
		so_long->enemy_file = "./Img/enemy3.xpm";
		so_long->player_file = "./Img/player3.xpm";
		so_long->points_file = "./Img/coin4.xpm";
	}
	if (i == 12)
		i = 0;
	fill_window(so_long);
	i++;
	return 0;
}

/*void	door_animation(t_game *so_long)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (i < 2)
		so_long->exit_file = "./Img/exit2.xpm";
		if (i > 2 && i < 4)
		so_long->exit_file = "./Img/exit3.xpm";
		if (i > 4)
		so_long->exit_file = "./Img/exit4.xpm";
		fill_window(so_long);
		i++;
	}
}*/
