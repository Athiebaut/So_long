/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:02:58 by athiebau          #+#    #+#             */
/*   Updated: 2023/09/14 13:37:55 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

int static	calculate_moove(t_game *so_long, int enemy_status)
{
	int	x;
	int	y;

	x = so_long->e_x;
	y = so_long->e_y;
	if ((enemy_status == 0) && ((so_long->map[y][x + 1] != '1')
		&& (so_long->map[y][x + 1] != 'X') && (so_long->map[y][x + 1] != 'E')
		&& (so_long->map[y][x + 1] != 'C')))
		enemy_status = 0;
	else if ((enemy_status == 0) && ((so_long->map[y][x + 1] != '1')
		|| (so_long->map[y][x + 1] != 'X') || (so_long->map[y][x + 1] != 'E')
		|| (so_long->map[y][x + 1] != 'C')))
		enemy_status = 1;
	else if ((enemy_status == 1) && ((so_long->map[y][x - 1] != '1')
		&& (so_long->map[y][x - 1] != 'X') && (so_long->map[y][x - 1] != 'E')
		&& (so_long->map[y][x - 1] != 'C')))
		enemy_status = 1;
	else if ((enemy_status == 1) && ((so_long->map[y][x - 1] != '1')
		|| (so_long->map[y][x - 1] != 'X') || (so_long->map[y][x - 1] != 'E')
		|| (so_long->map[y][x - 1] != 'C')))
		enemy_status = 0;
	return (enemy_status);
}

void	enemies_movements(t_game *so_long)
{
	static int	enemy_status;
	int			x;
	int			y;

	x = so_long->e_x;
	y = so_long->e_y;
	if ((so_long->map[y][x - 1] == 'P') || (so_long->map[y][x + 1] == 'P'))
		(ft_printf("YOU LOSE. Try again ?\n"), close_window(so_long));
	enemy_status = calculate_moove(so_long, enemy_status);
	if (enemy_status == 0)
		enemy_0(so_long);
	else if (enemy_status == 1)
		enemy_1(so_long);
	fill_window(so_long);
}

void	place_patrol(t_game *so_long)
{
	if (so_long->file)
		mlx_destroy_image(so_long->mlx, so_long->file);
	so_long->e_x = so_long->x;
	so_long->e_y = so_long->y;
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, so_long->enemy_file,
			&so_long->pixel, &so_long->pixel);
	if (!so_long->file)
	{
		ft_printf("/!\\ Erreur, lecture d'image impossible. /!\\\n");
		ft_free(so_long, 4);
		exit (1);
	}
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->file,
		so_long->pixel * so_long->x, so_long->pixel * so_long->y);
}

void	place_enemy(t_game *so_long)
{
	if (so_long->file)
		mlx_destroy_image(so_long->mlx, so_long->file);
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, so_long->enemy_file,
			&so_long->pixel, &so_long->pixel);
	if (!so_long->file)
	{
		ft_printf("/!\\ Erreur, lecture d'image impossible. /!\\\n");
		ft_free(so_long, 4);
		exit (1);
	}
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->file,
		so_long->pixel * so_long->x, so_long->pixel * so_long->y);
}
