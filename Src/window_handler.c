/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:05:11 by alix              #+#    #+#             */
/*   Updated: 2025/04/18 02:52:24 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

/**
 * @brief Closes the game window and frees allocated resources.
 * 
 * This function is responsible for properly closing the game window
 * and freeing any resources allocated during the game's execution.
 * It calls the `ft_free` function to handle resource cleanup and then
 * exits the program with a status code of 0.
 * 
 * @param so_long A pointer to the game structure containing all
 * necessary game data and resources to be freed.
 * 
 * @return Always returns 0, though the program exits before this
 * value is used.
 */
int	close_window(t_game *so_long)
{
	ft_free(so_long, 3);
	exit(0);
	return (0);
}

/**
 * @brief Fills the game window with appropriate elements based on the game map.
 *
 * This function iterates through the 2D game map stored in the `so_long` structure
 * and places corresponding graphical elements in the game window. The elements
 * are determined by the characters in the map:
 * - '1': Places borders using the `place_borders` function.
 * - '0': Places floor using the `place_floor` function.
 * - 'P': Places the player using the `place_player` function.
 * - 'C': Places collectible points using the `place_points` function.
 * - 'E': Places the exit using the `place_exit` function.
 *
 * @param so_long A pointer to the `t_game` structure containing the game state,
 *                including the map, dimensions, and other relevant data.
 */
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
}
