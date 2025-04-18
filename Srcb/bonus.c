/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:37:29 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:53:21 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

/**
 * @brief Updates the exit file path in the game structure to create an animation effect.
 *
 * This function manages the animation of the exit by cycling through a series of
 * image files. It uses two static variables:
 * - `exit`: Determines whether the animation should continue or stop.
 * - `i`: Keeps track of the current frame in the animation sequence.
 *
 * The animation progresses through four different images (`exit1.xpm` to `exit4.xpm`)
 * based on the value of `i`. Once `i` reaches 12, the animation stops, and the exit
 * remains on the final image (`exit4.xpm`).
 *
 * @param so_long Pointer to the game structure containing the `exit_file` field.
 */
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

/**
 * @brief Performs the fourth step in the game setup, initializing enemy and 
 * player image file paths and triggering enemy movements.
 * 
 * This function sets the file paths for the enemy and player sprites and 
 * calls the `enemies_movements` function to handle the logic for enemy 
 * movements in the game.
 * 
 * @param so_long A pointer to the t_game structure containing the game state.
 */
void static	step_4(t_game *so_long)
{
	so_long->enemy_file = "./Img/enemy1.xpm";
	so_long->player_file = "./Img/player1.xpm";
	enemies_movements(so_long);
}

/**
 * @brief Updates the game assets and triggers enemy movements.
 *
 * This function sets the file paths for the enemy and player images
 * to their respective secondary versions. It then calls the 
 * `enemies_movements` function to handle the movement logic for enemies.
 *
 * @param so_long A pointer to the game structure containing game state
 *                and asset information.
 */
void static	step_4_8(t_game *so_long)
{
	so_long->enemy_file = "./Img/enemy2.xpm";
	so_long->player_file = "./Img/player2.xpm";
	enemies_movements(so_long);
}

/**
 * frames - Updates the game state based on the current frame count.
 * 
 * This function modifies the game assets (e.g., images for coins, enemies, 
 * and the player) and triggers specific game behaviors depending on the 
 * value of a static frame counter `i`. The counter increments with each 
 * call and resets after reaching a specific value.
 * 
 * @param so_long A pointer to the game structure containing game state 
 *                and asset file paths.
 * 
 * Behavior:
 * - Updates the `points_file` to different coin images based on the value of `i`.
 * - Calls helper functions `step_4` and `step_4_8` at specific frame intervals.
 * - Updates `enemy_file` and `player_file` to different images when `i >= 8`.
 * - Triggers enemy movements when `i >= 8`.
 * - Resets the frame counter `i` to 0 when it reaches 12.
 * 
 * @return Always returns 0.
 */
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

/**
 * @brief Displays the player's movement count on the game window.
 *
 * This function renders the number of movements the player has made
 * on the game window using the MiniLibX library. It first calculates
 * the movement count by decrementing the player's movement counter
 * (`p_moove`) by 1, converts it to a string using `ft_itoa`, and displays
 * it on the screen. Then, it displays the current movement count without
 * decrementing. If memory allocation for the string fails, the function
 * calls `ft_free` to handle cleanup and exits the program.
 *
 * @param so_long A pointer to the `t_game` structure containing the game
 *                state, including the MiniLibX instance, window, and
 *                player movement count.
 *
 * @note The function assumes that `so_long->p_moove` is properly initialized
 *       and that the MiniLibX library is correctly set up.
 * @note The function uses hardcoded pixel offsets for positioning the text
 *       on the screen.
 * @note The function frees the memory allocated for the movement count
 *       strings after rendering them.
 */
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
