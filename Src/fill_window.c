/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:50:17 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:48:17 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

/**
 * @brief Places the floor image at the specified position in the game window.
 *
 * This function loads the floor image from the file "./Img/floor.xpm" and places
 * it in the game window at the position determined by the `x` and `y` coordinates
 * of the `so_long` structure. If a previous floor image exists, it is destroyed
 * before loading the new one. If the image cannot be loaded, an error message is
 * printed, resources are freed, and the program exits.
 *
 * @param so_long A pointer to the game structure containing the necessary
 *                information for rendering and managing the game state.
 *
 * @note The function assumes that the `mlx`, `mlx_win`, `pixel`, `x`, and `y`
 *       fields of the `so_long` structure are properly initialized.
 * @note If the image file cannot be read, the program will terminate with an
 *       error message.
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
 * @brief Places the border image on the game window at the specified position.
 *
 * This function handles the placement of border images in the game window.
 * It first destroys any previously loaded image for the border, then loads
 * a new image from the file "./Img/wall.xpm". If the image cannot be loaded,
 * an error message is printed, resources are freed, and the program exits.
 * Finally, the loaded image is placed on the game window at the calculated
 * position based on the pixel size and coordinates.
 *
 * @param so_long A pointer to the game structure containing the necessary
 *                data for rendering and managing the game state.
 *
 * @note The function assumes that the `so_long` structure is properly
 *       initialized and contains valid pointers for `mlx` and `mlx_win`.
 *       The `pixel`, `x`, and `y` fields are used to calculate the position
 *       of the image in the window.
 *
 * @warning If the image file cannot be loaded, the program will terminate
 *          with an error message.
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
 * @brief Places the player character on the game window at the current position.
 *
 * This function updates the player's position in the game structure and renders
 * the player image at the specified coordinates on the game window. If a previous
 * player image exists, it is destroyed before loading the new one. If the image
 * file cannot be loaded, the function prints an error message, frees allocated
 * resources, and exits the program.
 *
 * @param so_long A pointer to the game structure containing game state and resources.
 *
 * @note The function assumes that the `so_long` structure is properly initialized
 *       and contains valid pointers for the MLX instance and window.
 *
 * @error If the player image file cannot be loaded, the program will terminate
 *        with an error message.
 */
void	place_player(t_game *so_long)
{
	if (so_long->file)
		mlx_destroy_image(so_long->mlx, so_long->file);
	so_long->p_x = so_long->x;
	so_long->p_y = so_long->y;
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, "./Img/player1.xpm",
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
 * @brief Places a points image on the game window at a specific position.
 *
 * This function handles the placement of a points image on the game window.
 * It first destroys any previously loaded image to free resources, then loads
 * a new image from the specified file path. If the image cannot be loaded,
 * an error message is printed, resources are freed, and the program exits.
 * Finally, the image is rendered at the specified coordinates on the window.
 *
 * @param so_long A pointer to the game structure containing the necessary
 *                information for rendering (e.g., mlx instance, window, 
 *                image file path, pixel size, and coordinates).
 *
 * @note The function assumes that the `so_long` structure is properly
 *       initialized and contains valid data.
 *
 * @warning If the image file cannot be loaded, the program will terminate
 *          with an error message.
 */
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

/**
 * @brief Places the exit image on the game window at the specified coordinates.
 *
 * This function loads an XPM image file representing the exit and places it
 * on the game window at the position determined by the `x` and `y` fields
 * of the `so_long` structure. If an image was previously loaded, it is
 * destroyed before loading the new one. If the image cannot be loaded, an
 * error message is printed, resources are freed, and the program exits.
 *
 * @param so_long A pointer to the game structure containing the necessary
 *                information for rendering and managing the game state.
 *
 * @note The function assumes that `so_long->mlx` and `so_long->mlx_win` are
 *       properly initialized. It also assumes that `so_long->pixel` contains
 *       the size of a single tile in pixels.
 *
 * @warning If the image file cannot be loaded, the program will terminate
 *          with an error message.
 */
void	place_exit(t_game *so_long)
{
	if (so_long->file)
		mlx_destroy_image(so_long->mlx, so_long->file);
	so_long->file = mlx_xpm_file_to_image(so_long->mlx, "./Img/exit1.xpm",
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
