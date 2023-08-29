/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:05:11 by alix              #+#    #+#             */
/*   Updated: 2023/08/29 16:28:18 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

static void	fill_area(t_game *so_long)
{
	so_long->y = 0;
	while((so_long->y) < (so_long->map_y))
	{
		so_long->x = 0;
		while ((so_long->x) < (so_long->map_x))
		{
			so_long->file = mlx_xpm_file_to_image(so_long->mlx,
				"./Img/Sol.xpm", &so_long->pixel, &so_long->pixel);
			mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->file,
				so_long->pixel * so_long->x, so_long->pixel * so_long->y);
			so_long->x++;
		}
		so_long->y++;
	}
}

void	fill_window(t_game *so_long)
{
	fill_area(so_long);
	so_long->y = 0;
	while((so_long->y) < (so_long->map_y))
	{
		so_long->x = 0;
		while ((so_long->x) < (so_long->map_x))
		{
			if (so_long->map[so_long->y][so_long->x] == '1')
				place_borders(so_long);
			if (so_long->map[so_long->y][so_long->x] == 'P')
				place_player(so_long);
			so_long->x++;
		}
		so_long->y++;
	}
}