/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:02:58 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:55:10 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

/**
 * @brief Calculates the next move direction for an enemy based on its current
 *        position and status within the game map.
 *
 * @param so_long Pointer to the game structure containing the map and enemy
 *        position information.
 * @param enemy_status The current movement status of the enemy (0 or 1).
 *        - 0: Moving to the right.
 *        - 1: Moving to the left.
 *
 * @return The updated movement status of the enemy:
 *         - 0: Continue moving to the right.
 *         - 1: Continue moving to the left.
 *
 * The function checks the tiles adjacent to the enemy's current position
 * (either to the right or left, depending on the current status) to determine
 * if the enemy can continue moving in the same direction or needs to change
 * direction. The enemy cannot move into tiles containing:
 * - '1': Wall.
 * - 'X': Another enemy.
 * - 'E': Exit.
 * - 'C': Collectible.
 *
 * Logical conditions are used to evaluate whether the enemy should maintain
 * its current direction or switch to the opposite direction.
 */
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

/**
 * @brief Handles the movements of enemies in the game and checks for player collision.
 *
 * This function manages the behavior of enemies in the game. It checks if the player
 * is adjacent to the enemy's current position, and if so, triggers a game-over scenario.
 * The function also calculates the next movement of the enemy and updates its position
 * accordingly. Finally, it refreshes the game window to reflect the updated state.
 *
 * @param so_long A pointer to the game structure containing the game state, including
 *                the map, enemy position, and other relevant data.
 *
 * @note The function assumes that the game structure and its fields are properly initialized.
 *       It also assumes that the map is a valid 2D array with boundaries.
 */
void	enemies_movements(t_game *so_long)
{
	static int	enemy_status;
	int			x;
	int			y;

	if (so_long->pat > 0)
	{
		x = so_long->e_x;
		y = so_long->e_y;
		if (so_long->en > 0 && (so_long->map[y][x - 1] == 'P')
			|| (so_long->map[y][x + 1] == 'P'))
			(ft_printf("YOU LOSE. Try again ?\n"), close_window(so_long));
		enemy_status = calculate_moove(so_long, enemy_status);
		if (enemy_status == 0)
			enemy_0(so_long);
		else if (enemy_status == 1)
			enemy_1(so_long);
	}
	fill_window(so_long);
}

/**
 * @brief Places the patrol (enemy) image on the game window at the specified
 *        coordinates and updates the patrol's position.
 *
 * This function handles the placement of the patrol (enemy) image in the game.
 * It first destroys any previously loaded patrol image to free resources.
 * Then, it updates the patrol's position (`e_x` and `e_y`) to the current
 * coordinates (`x` and `y`). After that, it loads the patrol image from the
 * specified file and places it on the game window at the appropriate position.
 * If the image cannot be loaded, the function prints an error message, frees
 * allocated resources, and exits the program.
 *
 * @param so_long A pointer to the game structure containing game state,
 *                resources, and configuration.
 *
 * @note The function assumes that the `so_long` structure is properly
 *       initialized and contains valid pointers for the MLX library.
 * @note If the image file cannot be loaded, the program will terminate.
 */
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

/**
 * @brief Places an enemy image on the game window at a specified position.
 *
 * This function handles the placement of an enemy image in the game window.
 * It first destroys any previously loaded enemy image, then loads a new image
 * from the specified file path, and finally places it at the desired position
 * on the game window. If the image cannot be loaded, the function prints an
 * error message, frees allocated resources, and exits the program.
 *
 * @param so_long A pointer to the game structure containing game state and
 *                resources, including the enemy image file path, pixel size,
 *                and position coordinates.
 *
 * @note The function assumes that the `so_long` structure is properly
 *       initialized and contains valid data for the enemy image file path,
 *       pixel size, and position coordinates.
 *
 * @warning If the image file cannot be loaded, the program will terminate
 *          with an error message.
 */
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
