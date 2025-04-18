/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:32:35 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:57:11 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

/**
 * @brief Handles the player's upward movement in the game.
 *
 * This function updates the player's position on the game map when moving up.
 * It also checks for specific conditions such as winning, losing, or collecting
 * points, and performs the necessary actions based on the current state of the game.
 *
 * @param so_long A pointer to the game structure containing the game state.
 *
 * Function behavior:
 * - Increments the player's move counter (`p_moove`).
 * - Checks if the player reaches the exit ('E') and has collected all points (`points == 0`),
 *   in which case the player wins, and the game window is closed.
 * - Checks if the player encounters an enemy ('A' or 'X'), in which case the player loses,
 *   and the game window is closed.
 * - If the player collects a collectible ('C'), the points counter is decremented.
 * - Updates the game map to reflect the player's new position ('P') and clears the old position ('0').
 */
void	up(t_game *so_long)
{
	so_long->p_moove++;
	if (so_long->map[so_long->p_y - 1][so_long->p_x] == 'E'
		&& so_long->points == 0)
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y - 1][so_long->p_x] == 'A'
		|| so_long->map[so_long->p_y - 1][so_long->p_x] == 'X')
	{
		ft_printf("YOU LOSE. Try again ?\n");
		close_window(so_long);
	}	
	if (so_long->map[so_long->p_y - 1][so_long->p_x] == 'C')
		so_long->points--;
	so_long->map[so_long->p_y][so_long->p_x] = '0';
	so_long->map[so_long->p_y - 1][so_long->p_x] = 'P';
}

/**
 * @brief Handles the player's movement downwards in the game.
 *
 * This function updates the player's position on the game map when moving
 * down. It increments the move counter, checks for various conditions
 * (e.g., reaching the exit, encountering an enemy, or collecting a collectible),
 * and updates the game state accordingly.
 *
 * @param so_long A pointer to the game structure containing the game state.
 *
 * Behavior:
 * - If the player moves onto the exit tile ('E'), a win message is displayed,
 *   and the game window is closed.
 * - If the player moves onto an enemy tile ('A' or 'X'), a lose message is
 *   displayed, and the game window is closed.
 * - If the player moves onto a collectible tile ('C'), the collectible count
 *   is decremented.
 * - The player's current position is updated on the map, replacing the
 *   previous position with '0' and the new position with 'P'.
 */
void	down(t_game *so_long)
{
	so_long->p_moove++;
	if (so_long->map[so_long->p_y + 1][so_long->p_x] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y + 1][so_long->p_x] == 'A'
		|| so_long->map[so_long->p_y + 1][so_long->p_x] == 'X')
	{
		ft_printf("YOU LOSE. Try again ?\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y + 1][so_long->p_x] == 'C')
		so_long->points--;
	so_long->map[so_long->p_y][so_long->p_x] = '0';
	so_long->map[so_long->p_y + 1][so_long->p_x] = 'P';
}

/**
 * @brief Handles the player's movement to the right in the game.
 * 
 * This function updates the player's position on the game map when moving
 * to the right. It also checks for specific conditions based on the content
 * of the target cell:
 * - If the target cell contains 'E', the player wins, and the game window is closed.
 * - If the target cell contains 'A' or 'X', the player loses, and the game window is closed.
 * - If the target cell contains 'C', the player's points are decremented.
 * 
 * The function increments the player's move counter and updates the map to
 * reflect the new position of the player.
 * 
 * @param so_long A pointer to the game structure containing the game state.
 */
void	right(t_game *so_long)
{
	so_long->p_moove++;
	if (so_long->map[so_long->p_y][so_long->p_x + 1] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y][so_long->p_x + 1] == 'A'
		|| so_long->map[so_long->p_y][so_long->p_x + 1] == 'X')
	{
		ft_printf("YOU LOSE. Try again ?\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y][so_long->p_x + 1] == 'C')
		so_long->points--;
	so_long->map[so_long->p_y][so_long->p_x] = '0';
	so_long->map[so_long->p_y][so_long->p_x + 1] = 'P';
}

/**
 * @brief Handles the player's movement to the left in the game.
 *
 * This function updates the game state when the player moves left. It increments
 * the player's move counter, checks the tile to the left of the player's current
 * position, and performs actions based on the tile's content:
 * - If the tile contains 'E', the player wins, and the game window is closed.
 * - If the tile contains 'A' or 'X', the player loses, and the game window is closed.
 * - If the tile contains 'C', the player's collectible points are decremented.
 * 
 * The function also updates the player's position on the map by setting the
 * current tile to '0' (empty) and the new tile to 'P' (player).
 *
 * @param so_long A pointer to the game structure containing the game state.
 */
void	left(t_game *so_long)
{
	so_long->p_moove++;
	if (so_long->map[so_long->p_y][so_long->p_x - 1] == 'E')
	{
		ft_printf("GG YOU WIN !\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y][so_long->p_x - 1] == 'A'
		|| so_long->map[so_long->p_y][so_long->p_x - 1] == 'X')
	{
		ft_printf("YOU LOSE. Try again ?\n");
		close_window(so_long);
	}
	if (so_long->map[so_long->p_y][so_long->p_x - 1] == 'C')
		so_long->points--;
	so_long->map[so_long->p_y][so_long->p_x] = '0';
	so_long->map[so_long->p_y][so_long->p_x - 1] = 'P';
}

/**
 * key_hook - Handles key press events and updates the game state accordingly.
 * 
 * @keycode: The keycode of the key that was pressed.
 * @so_long: A pointer to the game structure containing the game state.
 * 
 * This function processes key press events and performs actions based on the
 * key pressed:
 * - If the Escape key (keycode 65307) is pressed, the game window is closed.
 * - If the 'W' key (keycode 119) is pressed, the player moves up if the move
 *   is valid (not blocked by walls or an exit unless all points are collected).
 * - If the 'S' key (keycode 115) is pressed, the player moves down if the move
 *   is valid.
 * - If the 'D' key (keycode 100) is pressed, the player moves right if the move
 *   is valid.
 * - If the 'A' key (keycode 97) is pressed, the player moves left if the move
 *   is valid.
 * 
 * The function checks the game state (e.g., player's position, collected points,
 * and map layout) to determine whether a move is valid. If the move is valid,
 * it calls the appropriate movement function (up, down, right, or left).
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
