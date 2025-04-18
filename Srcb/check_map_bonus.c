/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:28:40 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:54:14 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

/**
 * @brief Prints an error message indicating that the map is not surrounded by walls,
 *        frees allocated resources, and exits the program.
 * 
 * This function is called when the map validation fails due to the map not being
 * properly enclosed by walls. It displays an error message to the user, cleans up
 * allocated resources using `ft_free`, and terminates the program with an exit code.
 * 
 * @param so_long A pointer to the game structure containing the map and other resources.
 */
static void	print_error(t_game *so_long)
{
	ft_printf("/!\\ Erreur, la carte n'est pas cernée de murs.\n");
	ft_printf("Merci d'en construire un à l'emplacement concerné. /!\\\n");
	ft_free(so_long, 1);
	exit(0);
}

/**
 * @brief Checks the horizontal borders (top and bottom rows) of the game map.
 * 
 * This function verifies that the first (top) and last (bottom) rows of the 
 * game map are completely surrounded by walls, represented by the character '1'.
 * If any character other than '1' is found in these rows, the function calls 
 * `print_error` to handle the error.
 * 
 * @param so_long A pointer to the game structure containing the map and its dimensions.
 * 
 * @note Assumes that the map is a valid 2D array and that `so_long->map_y` 
 * represents the number of rows in the map.
 */
static void	check_x_borders(t_game *so_long)
{
	int	i;
	int	last;

	i = 0;
	last = so_long->map_y - 1;
	while (so_long->map[0][i])
	{
		if (so_long->map[0][i] != '1')
			print_error(so_long);
		i++;
	}
	i = 0;
	while (so_long->map[last][i])
	{
		if (so_long->map[last][i] != '1')
			print_error(so_long);
		i++;
	}
}

/**
 * @brief Checks the vertical borders (left and right edges) of the game map
 *        to ensure they are properly enclosed with walls ('1').
 *
 * This function iterates through the rows of the map, excluding the first
 * and last rows, and verifies that the first and last columns of each row
 * contain the character '1'. If any of these conditions are not met, the
 * function calls `print_error` to handle the error.
 *
 * @param so_long A pointer to the game structure containing the map and
 *                its dimensions.
 */
static void	check_y_borders(t_game *so_long)
{
	int	i;
	int	last;

	i = 1;
	last = so_long->map_x - 1;
	while (i < so_long->map_y - 1)
	{
		if (so_long->map[i][0] != '1')
			print_error(so_long);
		i++;
	}
	i = 1;
	while (i < so_long->map_y - 1)
	{
		if (so_long->map[i][last] != '1')
			print_error(so_long);
		i++;
	}
}

/**
 * @brief Validates the game map for specific conditions and constraints.
 *
 * This function performs several checks on the game map to ensure it adheres
 * to the required format and rules:
 * - Verifies that there are no invalid characters in the map.
 * - Ensures that all rows of the map have the same length, making the map rectangular.
 * - Calls additional functions to validate the borders of the map.
 *
 * If any of the checks fail, an error message is printed, allocated resources
 * are freed, and the program exits.
 *
 * @param so_long A pointer to the game structure containing the map and other
 *                game-related data.
 */
void	check_map(t_game *so_long)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(so_long->map[0]);
	if (so_long->invalid > 0)
	{
		ft_printf("/!\\ Erreur, caracteres invalides presents. /!\\\n");
		ft_free(so_long, 1);
		exit(0);
	}
	while (so_long->map[i])
	{
		if (ft_strlen(so_long->map[i]) != len)
		{
			ft_printf("/!\\ Erreur, la carte n'est pas rectangulaire. /!\\\n");
			ft_free(so_long, 1);
			exit(0);
		}
		i++;
	}
	check_x_borders(so_long);
	check_y_borders(so_long);
}
