/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:37:29 by athiebau          #+#    #+#             */
/*   Updated: 2023/09/22 12:27:01 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

void	exit_opening(t_game *so_long)
{
	int static	exit;
	int static	i;

	if (exit == 0)
	{
		if (i < 3)
			so_long->exit_file = "./Img/exit1.xpm";
		if (i >= 3 && i < 6)
			so_long->exit_file = "./Img/exit2.xpm";
		if (i >= 6 && i < 9)
			so_long->exit_file = "./Img/exit3.xpm";
		if (i >= 9 && i < 12)
			so_long->exit_file = "./Img/exit4.xpm";
		if (i == 12)
			exit = 1;
		i++;
	}
	else
		so_long->exit_file = "./Img/exit4.xpm";
}

void static	step_4(t_game *so_long)
{
	so_long->enemy_file = "./Img/enemy1.xpm";
	so_long->player_file = "./Img/player1.xpm";
	enemies_movements(so_long);
}

void static	step_4_8(t_game *so_long)
{
	so_long->enemy_file = "./Img/enemy2.xpm";
	so_long->player_file = "./Img/player2.xpm";
	enemies_movements(so_long);
}

int	frames(t_game *so_long)
{
	static int	i;

	if (i < 3)
		so_long->points_file = "./Img/coin1.xpm";
	if (i < 4)
		step_4(so_long);
	if (i >= 3 && i < 6)
		so_long->points_file = "./Img/coin2.xpm";
	if (i >= 4 && i < 8)
		step_4_8(so_long);
	if (i >= 6 && i < 9)
		so_long->points_file = "./Img/coin3.xpm";
	if (i >= 8)
	{
		so_long->enemy_file = "./Img/enemy3.xpm";
		so_long->player_file = "./Img/player3.xpm";
		enemies_movements(so_long);
	}
	if (i >= 9)
		so_long->points_file = "./Img/coin4.xpm";
	if (i == 12)
		i = 0;
	i++;
	return (0);
}

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
