/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:50:17 by athiebau          #+#    #+#             */
/*   Updated: 2023/08/30 22:49:56 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	place_borders(t_game *so_long)
{
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, "./Img/wall.xpm",
			&so_long->pixel, &so_long->pixel);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->file,
		so_long->pixel * so_long->x, so_long->pixel * so_long->y);
}

void	place_player(t_game *so_long)
{
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, "./Img/player.xpm",
			&so_long->pixel, &so_long->pixel);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->file,
		so_long->pixel * so_long->x, so_long->pixel * so_long->y);
}

void	place_points(t_game *so_long)
{
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, "./Img/points.xpm",
			&so_long->pixel, &so_long->pixel);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->file,
		so_long->pixel * so_long->x, so_long->pixel * so_long->y);
}

void	place_exit(t_game *so_long)
{
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, "./Img/exit.xpm",
			&so_long->pixel, &so_long->pixel);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->file,
		so_long->pixel * so_long->x, so_long->pixel * so_long->y);
}
