/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:55:36 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:52:01 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

/**
 * @brief Handles the error when the game window size exceeds the screen size.
 *
 * This function prints an error message to the console, frees allocated 
 * resources associated with the game, and terminates the program.
 *
 * @param so_long A pointer to the game structure containing game-related data.
 */
void	window_error(t_game *so_long)
{
	ft_printf("/!\\ Erreur, taille de la fenetre plus grande que l'ecran. /!\\\n");
	ft_free(so_long, 2);
	exit(1);
}

/**
 * @brief Initializes and creates a new game window for the "so_long" game.
 *
 * This function sets up the game window by initializing the necessary
 * graphical components using the MiniLibX library. It calculates the
 * appropriate window size based on the map dimensions and a predefined
 * pixel size. If the screen size is insufficient to accommodate the
 * desired window size, an error is raised. The function also handles
 * memory cleanup and exits the program in case of initialization failures.
 *
 * @param so_long A pointer to the game structure containing game state
 *                and configuration data.
 *
 * @details
 * - The function initializes the MiniLibX library using `mlx_init()`.
 * - It retrieves the screen size using `mlx_get_screen_size()` and ensures
 *   the desired window size fits within the screen dimensions.
 * - If the screen size is insufficient, `window_error()` is called to handle
 *   the error.
 * - A new window is created using `mlx_new_window()`. If the window creation
 *   fails, the function frees allocated resources and exits.
 * - Finally, the `fill_window()` function is called to populate the window
 *   with the initial game content.
 *
 * @note The function assumes that the `so_long` structure is properly
 *       initialized before being passed to it.
 *
 * @warning If any initialization step fails, the program will terminate
 *          after freeing allocated resources.
 */
static void	window(t_game *so_long)
{
	int	sizex;
	int	sizey;

	sizex = 0;
	sizey = 0;
	so_long->pixel = 60;
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
	{
		ft_free(so_long, 0);
		exit(1);
	}
	mlx_get_screen_size(so_long->mlx, &sizex, &sizey);
	if (sizex < so_long->pixel * so_long->map_x || sizey < so_long->pixel
		* so_long->map_y)
		window_error(so_long);
	so_long->mlx_win = mlx_new_window(so_long->mlx, so_long->pixel
			* so_long->map_x, so_long->pixel
			* so_long->map_y, "Advance Effect");
	if (!so_long->mlx_win)
	{
		ft_free(so_long, 2);
		exit(1);
	}
	fill_window(so_long);
}

/**
 * @brief Validates the command-line arguments passed to the program.
 *
 * This function checks if the correct number of arguments is provided
 * and ensures that the file passed as an argument has the correct `.ber` extension.
 * If the validation fails, the program prints an error message and exits.
 *
 * @param ac The argument count passed to the program.
 * @param av The argument vector containing the program name and arguments.
 *
 * @note The function expects exactly two arguments: the program name and the file path.
 *       The file path must end with the `.ber` extension.
 *
 * @warning If the number of arguments is incorrect or the file extension is invalid,
 *          the program will terminate with an error message.
 */
static void	check_args(int ac, char **av)
{
	int	len;

	if (ac != 2)
	{
		ft_printf("/!\\ Erreur, mauvais nombre d'arguments. /!\\\n");
		exit(0);
	}
	len = ft_strlen(av[1]);
	if (av[1][len - 4] != '.' || av[1][len - 3] != 'b'
		|| av[1][len - 2] != 'e' || av[1][len - 1] != 'r')
	{
		ft_printf("/!\\ Erreur, extension de la map incorrecte, ");
		ft_printf("merci de fournir un fichier \'.ber\'. /!\\\n");
		exit(0);
	}
}

/**
 * @brief Entry point of the so_long program.
 * 
 * This function initializes the game, verifies the input arguments,
 * sets up the game map, creates the game window, and starts the event loop.
 * It also handles cleanup of resources upon program termination.
 * 
 * @param ac The argument count passed to the program.
 * @param av The argument vector containing the program arguments.
 * 
 * The function performs the following steps:
 * 1. Validates the command-line arguments using `check_args`.
 * 2. Initializes the `t_game` structure to zero using `ft_bzero`.
 * 3. Validates and processes the game map using `map_certify`.
 * 4. Creates the game window using `window`.
 * 5. Sets up event hooks for key presses and window close events using `mlx_hook`.
 * 6. Starts the main event loop using `mlx_loop`.
 * 7. Frees allocated resources using `ft_free` before exiting.
 */
int	main(int ac, char **av)
{
	t_game	so_long;

	check_args(ac, av);
	ft_bzero(&so_long, sizeof(t_game));
	map_certify(av, &so_long);
	window(&so_long);
	mlx_hook(so_long.mlx_win, 2, 1L << 0, key_hook, &so_long);
	mlx_hook(so_long.mlx_win, 17, 0, close_window, &so_long);
	mlx_loop(so_long.mlx);
	ft_free(&so_long, 3);
}
