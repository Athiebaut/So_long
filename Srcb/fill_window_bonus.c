/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:50:17 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:56:12 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

/**
 * @brief Places the floor image at the specified position in the game window.
 *
 * This function loads the floor image from the file "./Img/floor.xpm" and places
 * it in the game window at the position determined by the current values of
 * `so_long->x` and `so_long->y`. If a previous floor image exists, it is destroyed
 * before loading the new one. If the image cannot be loaded, an error message is
 * printed, resources are freed, and the program exits.
 *
 * @param so_long A pointer to the game structure containing the necessary
 *                information for rendering and managing the game state.
 *
 * @note The function assumes that `so_long->mlx` and `so_long->mlx_win` are
 *       properly initialized. The `so_long->pixel` value is used as the size
 *       of each tile in the game.
 *
 * @warning If the image file cannot be read, the program will terminate with
 *          an exit code of 1.
 */
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

/**
 * @brief Places the border images on the game window.
 *
 * This function loads the wall image from the specified file path and places
 * it at the appropriate position on the game window. If the image cannot be
 * loaded, an error message is printed, resources are freed, and the program
 * exits with an error code.
 *
 * @param so_long A pointer to the game structure containing the necessary
 *                information for rendering (e.g., mlx instance, window, 
 *                image file, pixel size, and coordinates).
 *
 * @note The function assumes that the `so_long` structure is properly
 *       initialized before calling this function.
 * @note If a previous image is already loaded in `so_long->file`, it will
 *       be destroyed before loading the new image.
 * @note The program will terminate if the image file cannot be loaded.
 */
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

/**
 * @brief Places the player character on the game window at the specified position.
 * 
 * This function updates the player's position in the game structure and renders
 * the player's image on the game window. If the player's image already exists, 
 * it is destroyed and replaced with a new one. If loading the player's image fails, 
 * the function prints an error message, frees allocated resources, and exits the program.
 * 
 * @param so_long A pointer to the game structure containing game state and resources.
 * 
 * @note The function assumes that the `so_long` structure is properly initialized 
 *       and contains valid data for rendering.
 * 
 * @error If the player's image file cannot be loaded, the program will terminate 
 *        with an error message.
 */
void	place_player(t_game *so_long)
{
	if (so_long->file)
		mlx_destroy_image(so_long->mlx, so_long->file);
	so_long->p_x = so_long->x;
	so_long->p_y = so_long->y;
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, so_long->player_file,
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
 * @brief Places the points image on the game window at the specified position.
 * 
 * This function handles the rendering of the points image in the game window.
 * It first destroys any previously loaded image for the points, then loads
 * the new image from the file specified in `so_long->points_file`. If the image
 * cannot be loaded, an error message is printed, resources are freed, and the
 * program exits. Finally, the image is placed in the game window at the
 * position determined by `so_long->x` and `so_long->y`.
 * 
 * @param so_long A pointer to the game structure containing all necessary
 *                game data, including the graphics context, window, and
 *                file paths.
 * 
 * @note The function assumes that `so_long->mlx`, `so_long->points_file`,
 *       `so_long->x`, and `so_long->y` are properly initialized.
 * 
 * @warning If the image file cannot be loaded, the program will terminate
 *          with an error message.
 */
void	place_points(t_game *so_long)
{
	if (so_long->file)
		mlx_destroy_image(so_long->mlx, so_long->file);
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, so_long->points_file,
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
 * @brief Places the exit image in the game window.
 *
 * This function determines the appropriate exit image to display based on the
 * game's current state. If there are remaining points to collect, it sets the
 * exit image to a closed state. Otherwise, it calls `exit_opening` to handle
 * the open state. The function then loads the image file, checks for errors,
 * and places the image at the appropriate position in the game window.
 *
 * @param so_long A pointer to the game structure containing all game-related
 *                data, including the graphics context, window, and game state.
 *
 * @note If the image file cannot be read, the function prints an error message,
 *       frees allocated resources, and terminates the program with an exit code
 *       of 1.
 */
void	place_exit(t_game *so_long)
{
	if (so_long->points != 0)
		so_long->exit_file = "./Img/exit1.xpm";
	else
		exit_opening(so_long);
	if (so_long->file)
		mlx_destroy_image(so_long->mlx, so_long->file);
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, so_long->exit_file,
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
