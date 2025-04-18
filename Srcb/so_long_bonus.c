/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:55:36 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:59:06 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

/**
 * @brief Handles the error when the game window size exceeds the screen size.
 * 
 * This function prints an error message to the console, frees allocated 
 * resources associated with the game, and terminates the program with an 
 * exit status of 1.
 * 
 * @param so_long A pointer to the game structure containing game-related data.
 */
static void	window_error(t_game *so_long)
{
	ft_printf("/!\\ Erreur, taille de la fenetre plus grande que l'ecran. /!\\\n");
	ft_free(so_long, 2);
	exit(1);
}

/**
 * @brief Initializes the game window and sets up the graphical environment.
 *
 * This function creates a new game window using the MiniLibX library, initializes
 * the necessary graphical resources, and ensures that the window dimensions fit
 * within the screen size. It also sets up file paths for game assets such as the
 * enemy, player, points, and exit images.
 *
 * @param so_long A pointer to the t_game structure containing game state and configuration.
 *
 * @details
 * - The function initializes the MiniLibX library and checks for successful initialization.
 * - It retrieves the screen size and ensures the game window fits within the screen.
 * - If the window dimensions exceed the screen size, it calls `window_error` to handle the error.
 * - The function allocates a new window and checks for successful creation.
 * - File paths for game assets are assigned to the corresponding fields in the `so_long` structure.
 * - Finally, the `fill_window` function is called to populate the window with the game elements.
 *
 * @note If any initialization step fails, the function frees allocated resources
 *       and exits the program with an error status.
 *
 * @see mlx_init
 * @see mlx_get_screen_size
 * @see mlx_new_window
 * @see fill_window
 * @see ft_free
 * @see window_error
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
		(ft_free(so_long, 0), exit(1));
	mlx_get_screen_size(so_long->mlx, &sizex, &sizey);
	if (sizex < so_long->pixel * so_long->map_x || sizey < so_long->pixel
		* so_long->map_y)
		window_error(so_long);
	so_long->mlx_win = mlx_new_window(so_long->mlx, (so_long->pixel
				* so_long->map_x) + 100, so_long->pixel
			* so_long->map_y, "Advance Effect");
	if (!so_long->mlx_win)
		(ft_free(so_long, 2), exit(1));
	so_long->enemy_file = "./Img/enemy1.xpm";
	so_long->player_file = "./Img/player1.xpm";
	so_long->points_file = "./Img/coin1.xpm";
	so_long->exit_file = "./Img/exit1.xpm";
	fill_window(so_long);
}

/**
 * @brief Validates the command-line arguments passed to the program.
 * 
 * This function checks if the correct number of arguments is provided
 * and ensures that the file specified as the second argument has the
 * correct `.ber` extension. If any of these conditions are not met,
 * the program will print an error message and terminate.
 * 
 * @param ac The argument count passed to the program.
 * @param av The argument vector (array of strings) passed to the program.
 * 
 * @note The function expects exactly two arguments (program name and file path).
 *       The file path must end with the `.ber` extension.
 * 
 * @warning If the number of arguments is incorrect or the file extension
 *          is invalid, the program will exit with a status of 0.
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
 * @brief Entry point of the so_long_bonus program.
 * 
 * This function initializes the game, verifies the input arguments,
 * sets up the game map, creates the game window, and starts the game loop.
 * It also handles user input and ensures proper cleanup of resources.
 * 
 * @param ac The argument count passed to the program.
 * @param av The argument vector containing program arguments.
 * 
 * The function performs the following steps:
 * 1. Validates the command-line arguments using `check_args`.
 * 2. Initializes the `t_game` structure to zero using `ft_bzero`.
 * 3. Validates and processes the game map using `map_certify`.
 * 4. Creates the game window using `window`.
 * 5. Sets up the game loop and frame rendering using `mlx_loop_hook`.
 * 6. Configures event hooks for key presses and window close events using `mlx_hook`.
 * 7. Starts the main event loop using `mlx_loop`.
 * 8. Frees allocated resources using `ft_free` before exiting.
 */
int	main(int ac, char **av)
{
	t_game	so_long;

	check_args(ac, av);
	ft_bzero(&so_long, sizeof(t_game));
	map_certify(av, &so_long);
	window(&so_long);
	mlx_loop_hook(so_long.mlx, frames, &so_long);
	mlx_hook(so_long.mlx_win, 2, 1L << 0, key_hook, &so_long);
	mlx_hook(so_long.mlx_win, 17, 0, close_window, &so_long);
	mlx_loop(so_long.mlx);
	ft_free(&so_long, 3);
}
