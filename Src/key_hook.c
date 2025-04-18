/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:32:35 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:49:13 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

/**
 * @brief Handles the player's upward movement in the game.
 *
 * This function updates the player's position on the game map when moving up.
 * It increments the movement counter, checks for specific conditions such as
 * reaching the exit ('E') or collecting a collectible ('C'), and updates the
 * game state accordingly. If the player reaches the exit, the game ends with
 * a victory message. If a collectible is encountered, the player's points
 * are decremented. The function also updates the map to reflect the player's
 * new position and redraws the game window.
 *
 * @param so_long A pointer to the game structure containing the game state,
 *                including the map, player position, movement counter, and
 *                points.
 */
void	up(t_game *so_long)
{
	so_long->p_moove++;
	ft_printf("Mouvements : %d\n", so_long->p_moove);
	if (so_long->map[so_long->p_y - 1][so_long->p_x] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}	
	if (so_long->map[so_long->p_y - 1][so_long->p_x] == 'C')
		so_long->points--;
	so_long->map[so_long->p_y][so_long->p_x] = '0';
	so_long->map[so_long->p_y - 1][so_long->p_x] = 'P';
	fill_window(so_long);
}

/**
 * @brief Handles the player's downward movement in the game.
 * 
 * This function updates the player's position on the game map when moving
 * downwards. It increments the movement counter, checks for specific
 * conditions (e.g., reaching the exit or collecting an item), and updates
 * the game state accordingly.
 * 
 * @param so_long A pointer to the game structure containing the game state.
 * 
 * Function behavior:
 * - Increments the player's movement counter and prints the updated count.
 * - Checks if the player reaches the exit ('E') and ends the game if true.
 * - Decreases the collectible points if the player moves onto a collectible ('C').
 * - Updates the game map to reflect the player's new position.
 * - Calls `fill_window` to refresh the game window with the updated map.
 */
void	down(t_game *so_long)
{
	so_long->p_moove++;
	ft_printf("Mouvements : %d\n", so_long->p_moove);
	if (so_long->map[so_long->p_y + 1][so_long->p_x] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y + 1][so_long->p_x] == 'C')
		so_long->points--;
	so_long->map[so_long->p_y][so_long->p_x] = '0';
	so_long->map[so_long->p_y + 1][so_long->p_x] = 'P';
	fill_window(so_long);
}

/**
 * @brief Handles the player's movement to the right in the game.
 * 
 * This function updates the player's position on the game map when moving
 * to the right. It increments the movement counter, checks for specific
 * conditions such as reaching the exit ('E') or collecting a collectible ('C'),
 * and updates the game state accordingly. If the player reaches the exit,
 * the game ends with a victory message. The function also updates the map
 * to reflect the player's new position and redraws the game window.
 * 
 * @param so_long A pointer to the game structure containing the game state,
 *                including the map, player position, movement counter, and
 *                collectible points.
 */
void	right(t_game *so_long)
{
	so_long->p_moove++;
	ft_printf("Mouvements : %d\n", so_long->p_moove);
	if (so_long->map[so_long->p_y][so_long->p_x + 1] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y][so_long->p_x + 1] == 'C')
		so_long->points--;
	so_long->map[so_long->p_y][so_long->p_x] = '0';
	so_long->map[so_long->p_y][so_long->p_x + 1] = 'P';
	fill_window(so_long);
}

/**
 * @brief Handles the player's movement to the left in the game.
 *
 * This function updates the player's position on the game map when moving left.
 * It increments the movement counter, checks for specific conditions such as
 * reaching the exit ('E') or collecting a collectible ('C'), and updates the
 * game state accordingly. If the player reaches the exit, the game ends with
 * a win message. If a collectible is encountered, the player's points are
 * decremented. The function also updates the map to reflect the player's new
 * position and redraws the game window.
 *
 * @param so_long A pointer to the game structure containing the game state,
 *                including the map, player position, movement counter, and
 *                points.
 */
void	left(t_game *so_long)
{
	so_long->p_moove++;
	ft_printf("Mouvements : %d\n", so_long->p_moove);
	if (so_long->map[so_long->p_y][so_long->p_x - 1] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y][so_long->p_x - 1] == 'C')
		so_long->points--;
	so_long->map[so_long->p_y][so_long->p_x] = '0';
	so_long->map[so_long->p_y][so_long->p_x - 1] = 'P';
	fill_window(so_long);
}

/**
 * key_hook - Handles key press events and performs corresponding actions.
 * 
 * @keycode: The keycode of the key that was pressed.
 * @so_long: A pointer to the game structure containing game state and data.
 * 
 * This function processes key press events and performs actions based on the
 * key pressed:
 * - If the Escape key (keycode 65307) is pressed, the game window is closed.
 * - If the 'W' key (keycode 119) is pressed, the player moves up, provided
 *   the movement is valid (not blocked by walls or an exit unless all points
 *   are collected).
 * - If the 'S' key (keycode 115) is pressed, the player moves down, provided
 *   the movement is valid.
 * - If the 'D' key (keycode 100) is pressed, the player moves right, provided
 *   the movement is valid.
 * - If the 'A' key (keycode 97) is pressed, the player moves left, provided
 *   the movement is valid.
 * 
 * The function checks the game state (e.g., remaining points to collect) and
 * the map layout to determine whether a movement is allowed.
 * 
 * Return: Always returns 0.
 */
int	key_hook(int keycode, t_game *so_long)
{
	int	y;
	int	x;

	y = so_long->p_y;
	x = so_long->p_x;
	if (keycode == 65307)
		close_window(so_long);
	if (keycode == 119 && ((so_long->points != 0 && so_long->map[y - 1][x]
			!= 'E' && so_long->map[y - 1][x] != '1') || (so_long->points
			== 0 && so_long->map[y - 1][x] != '1')))
		up(so_long);
	if (keycode == 115 && ((so_long->points != 0 && so_long->map[y + 1][x]
			!= 'E' && so_long->map[y + 1][x] != '1') || (so_long->points
			== 0 && so_long->map[y + 1][x] != '1')))
		down(so_long);
	if (keycode == 100 && ((so_long->points != 0 && so_long->map[y][x + 1]
			!= 'E' && so_long->map[y][x + 1] != '1') || (so_long->points
			== 0 && so_long->map[y][x + 1] != '1')))
		right(so_long);
	if (keycode == 97 && ((so_long->points != 0 && so_long->map[y][x - 1]
			!= 'E' && so_long->map[y][x - 1] != '1') || (so_long->points
			== 0 && so_long->map[y][x - 1] != '1')))
		left(so_long);
	return (0);
}
