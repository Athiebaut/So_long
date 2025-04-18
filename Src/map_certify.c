/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_certify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:10:46 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:50:09 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"
#include <fcntl.h>

/**
 * @brief Validates the characters in the game map and updates the game state.
 *
 * This function iterates through the provided map string and performs the following checks:
 * - Counts the occurrences of the player ('P'), collectible items ('C'), and exit ('E').
 * - Ensures that the map does not contain invalid characters (anything other than '1', '0', '\n', 'P', 'C', or 'E').
 * - Checks for invalid newline placements, such as consecutive newlines or a newline at the start of the map.
 * - Updates the `invalid`, `player`, `points`, and `exit` fields of the `t_game` structure accordingly.
 *
 * If the map does not meet the required conditions (exactly one player, at least one collectible, and exactly one exit),
 * the function prints an error message, frees allocated resources, and terminates the program.
 *
 * @param map A string representing the game map.
 * @param so_long A pointer to the `t_game` structure containing the game state.
 */
static void	check_characters(char *map, t_game *so_long)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i] == '\n' && ((map[i + 1] == '\n') || (!map[i + 1])))
			so_long->invalid++;
		if (map[i] == 'P')
			so_long->player++;
		else if (map[i] == 'C')
			so_long->points++;
		else if (map[i] == 'E')
			so_long->exit++;
		else if (map[i] == '\n' && map[i + 1])
			i++;
		else if (map[i] != '1' && map[i] != '0' && map[i] != '\n'
			|| map[0] == '\n')
			so_long->invalid++;
	}
	if (so_long->player != 1 || so_long->exit != 1 || so_long->points < 1)
	{
		ft_printf("/!\\ Erreur, nombre de joueur, sortie ");
		ft_printf("ou collectibles incorrect. /!\\\n");
		(ft_free(so_long, 1), exit(0));
	}
}

/**
 * @brief Recursively validates the path in the game map starting from a given position.
 *
 * This function checks the validity of the path in the game map by traversing it
 * recursively. It increments counters for collectible items ('C') and exit points ('E')
 * encountered during the traversal. The function also marks visited positions on the map
 * to avoid revisiting them.
 *
 * @param y The current row index in the map.
 * @param x The current column index in the map.
 * @param so_long A pointer to the game structure containing the map and related data.
 *
 * @details
 * - If the current position contains a collectible ('C'), the `path_points` counter is incremented.
 * - If the current position is out of bounds, contains a wall ('1'), or is an exit ('E'),
 *   the function stops further traversal from that position.
 * - If the current position is an exit ('E'), the `path_exit` counter is incremented, and
 *   the position is marked as visited by setting it to '1'.
 * - The function recursively calls itself for the left, right, up, and down neighbors of
 *   the current position.
 *
 * @note The map is modified in-place during the traversal, with visited positions being
 *       marked as '1'.
 */
static void	path_certify(int y, int x, t_game *so_long)
{
	if (so_long->map[y][x] == 'C')
		so_long->path_points++;
	if (y < 0 || y >= so_long->map_y || x < 0 || x >= so_long->map_x
		|| so_long->map[y][x] == '1' || so_long->map[y][x] == 'E')
	{
		if (so_long->map[y][x] == 'E')
		{
			so_long->path_exit++;
			so_long->map[y][x] = '1';
		}
		return ;
	}
	so_long->map[y][x] = '1';
	path_certify(y, (x - 1), so_long);
	path_certify(y, (x + 1), so_long);
	path_certify((y - 1), x, so_long);
	path_certify((y + 1), x, so_long);
}

/**
 * @brief Validates the path in the game map to ensure all required points 
 *        and exits are reachable from the player's starting position.
 *
 * This function iterates through the game map to locate the player's starting 
 * position ('P'). Once found, it calls the `path_certify` function to verify 
 * the path's validity. If the path is valid, the function resets the player's 
 * coordinates and exits. Otherwise, it prints an error message, frees allocated 
 * resources, and terminates the program.
 *
 * @param so_long A pointer to the game structure containing the map and 
 *                other game-related data.
 *
 * @note The function assumes that the map is properly initialized and that 
 *       the game structure contains valid data.
 * @note If the path is invalid, the program will terminate with an error message.
 */
static void	check_path(t_game *so_long)
{
	so_long->y = 0;
	while (++so_long->y < so_long->map_y)
	{
		so_long->x = 0;
		while (++so_long->x < so_long->map_x)
		{
			if (so_long->map[so_long->y][so_long->x] == 'P')
			{
				path_certify(so_long->y, so_long->x, so_long);
				if (so_long->path_points == so_long->points
					&& so_long->path_exit == so_long->exit)
				{
					so_long->x = 0;
					so_long->y = 0;
					return ;
				}
				else
				{
					ft_printf("/!\\ Erreur, le chemin n'est pas valide. /!\\\n");
					ft_free(so_long, 1);
					exit(0);
				}
			}	
		}
	}
}

/**
 * @brief Validates and processes the game map from a file.
 * 
 * This function opens the file specified in the command-line arguments,
 * reads its contents, validates the map, and prepares it for use in the game.
 * It performs several checks to ensure the map is valid and initializes
 * the game structure with the map data.
 * 
 * @param av Command-line arguments, where av[1] is the file path to the map.
 * @param so_long Pointer to the game structure containing game-related data.
 * 
 * @note The function will terminate the program with an error message if:
 *       - The file cannot be opened.
 *       - The map fails validation checks.
 * 
 * @details Steps performed by the function:
 *          1. Opens the file specified in av[1].
 *          2. Reads the map data into a buffer.
 *          3. Validates the characters in the map.
 *          4. Splits the map into a 2D array and calculates its dimensions.
 *          5. Performs additional map validation and pathfinding checks.
 *          6. Frees and reinitializes the map buffer for further use.
 *          7. Closes the file descriptor.
 * 
 * @warning Ensure that the file path provided in av[1] is valid and accessible.
 *          The function uses `exit(1)` to terminate the program on failure.
 */
void	map_certify(char **av, t_game *so_long)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("/!\\ Erreur, impossible d'ouvrir le fichier. /!\\\n");
		exit (1);
	}
	so_long->buffer = get_the_map(fd, so_long->buffer);
	check_characters(so_long->buffer, so_long);
	so_long->map = ft_split(so_long->buffer, '\n');
	so_long->map_x = ft_strlen(so_long->map[0]);
	so_long->map_y = count_lines(so_long->map);
	check_map(so_long);
	check_path(so_long);
	ft_free(so_long, 0);
	so_long->map = ft_split(so_long->buffer, '\n');
	free(so_long->buffer);
	close(fd);
}
