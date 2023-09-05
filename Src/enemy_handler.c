/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:30:25 by athiebau          #+#    #+#             */
/*   Updated: 2023/09/05 12:31:32 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	place_enemy(t_game *so_long)
{
	if (so_long->file)
		mlx_destroy_image(so_long->mlx, so_long->file);
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, "./Img/enemy.xpm",
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