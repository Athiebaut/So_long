/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:50:17 by athiebau          #+#    #+#             */
/*   Updated: 2023/09/05 11:28:16 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	place_floor(t_game *so_long)
{
	if (so_long->file)
		mlx_destroy_image(so_long->mlx, so_long->file);
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, "./Img/floor.xpm",
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

void	place_borders(t_game *so_long)
{
	if (so_long->file)
		mlx_destroy_image(so_long->mlx, so_long->file);
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, "./Img/wall.xpm",
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

void	place_player(t_game *so_long)
{
	if (so_long->file)
		mlx_destroy_image(so_long->mlx, so_long->file);
	so_long->p_x = so_long->x;
	so_long->p_y = so_long->y;
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, "./Img/player.xpm",
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

void	place_points(t_game *so_long)
{
	if (so_long->file)
		mlx_destroy_image(so_long->mlx, so_long->file);
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, "./Img/points.xpm",
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

void	place_exit(t_game *so_long)
{
	if (so_long->file)
		mlx_destroy_image(so_long->mlx, so_long->file);
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, "./Img/exit.xpm",
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
