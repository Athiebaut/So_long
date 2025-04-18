/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:05:11 by alix              #+#    #+#             */
/*   Updated: 2025/04/18 03:01:48 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

/**
 * @brief Closes the game window and frees allocated resources.
 * 
 * This function is responsible for properly closing the game window,
 * freeing all allocated resources associated with the game, and exiting
 * the program with a status code of 0.
 * 
 * @param so_long A pointer to the game structure containing all game-related data.
 * 
 * @return Always returns 0.
 */
int	close_window(t_game *so_long)
{
	ft_free(so_long, 3);
	exit(0);
	return (0);
}

/**
 * fill_window - Renders the game window by placing various elements
 *               based on the map configuration.
 * @so_long: Pointer to the game structure containing map data and state.
 *
 * This function iterates through the 2D map array and places the appropriate
 * graphical elements in the game window based on the map characters:
 *   - '1': Places borders using the place_borders function.
 *   - '0': Places floor tiles using the place_floor function.
 *   - 'P': Places the player using the place_player function.
 *   - 'C': Places collectible points using the place_points function.
 *   - 'E': Places the exit using the place_exit function.
 *   - 'A': Places patrol enemies if the enemy count (en) is greater than 0,
 *          using the place_patrol function.
 *   - 'X': Places stationary enemies if the enemy count (en) is greater than 0,
 *          using the place_enemy function.
 *
 * After rendering the map, the function introduces a small delay using
 * usleep to control the rendering speed and calls print_movements to
 * display the player's movement count.
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
			if (so_long->map[so_long->y][so_long->x] == 'A' && so_long->en > 0)
				place_patrol(so_long);
			if (so_long->map[so_long->y][so_long->x] == 'X' && so_long->en > 0)
				place_enemy(so_long);
			so_long->x++;
		}
		so_long->y++;
	}
	(usleep(10000), print_movements(so_long));
}
