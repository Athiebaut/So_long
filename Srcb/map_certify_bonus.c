/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_certify_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:10:46 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:58:13 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"
#include <fcntl.h>

/**
 * @brief Validates the game map's essential elements and exits the program
 *        if the validation fails.
 *
 * This function performs the following checks:
 * - Ensures that the `so_long->en` variable is initialized to -1 if it is not already set.
 * - Verifies that there is exactly one player (`so_long->player == 1`),
 *   exactly one exit (`so_long->exit == 1`), and at least one collectible
 *   (`so_long->points >= 1`) on the map.
 *
 * If any of these conditions are not met, an error message is printed to
 * the standard output, allocated resources are freed using `ft_free`, and
 * the program exits with a status of 0.
 *
 * @param so_long A pointer to the game structure containing map and game state data.
 */
static void	ft_lina(t_game *so_long)
{
	if (!so_long->en)
		so_long->en = -1;
	if (so_long->player != 1 || so_long->exit != 1 || so_long->points < 1)
	{
		ft_printf("/!\\ Erreur, nombre de joueur, sortie ");
		ft_printf("ou collectibles incorrect. /!\\\n");
		ft_free(so_long, 1);
		exit(0);
	}
}

/**
 * @brief Validates the characters in the provided map and updates the game state.
 *
 * This function iterates through the map string and performs the following checks:
 * - Counts the occurrences of specific characters ('A', 'X', 'P', 'C', 'E').
 * - Validates the map format by checking for invalid characters and improper newline placements.
 * - Updates the `so_long` structure with the counts of players, enemies, points, exits, and invalid entries.
 *
 * @param map The map string to be validated.
 * @param so_long A pointer to the game structure (`t_game`) where the results of the validation
 *                will be stored.
 *
 * @note The function assumes that the map is a null-terminated string.
 * @note If the map contains invalid characters or formatting issues, the `invalid` field
 *       in the `so_long` structure will be incremented.
 * @note The function calls `ft_lina(so_long)` at the end for additional processing.
 */
static void	check_characters(char *map, t_game *so_long)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i] == '\n' && ((map[i + 1] == '\n') || (!map[i + 1])))
			so_long->invalid++;
		if (map[i] == 'A')
			so_long->pat++;
		if (map[i] == 'A' || map[i] == 'X')
			so_long->en++;
		if (map[i] == 'P')
			so_long->player++;
		else if (map[i] == 'C')
			so_long->points++;
		else if (map[i] == 'E')
			so_long->exit++;
		else if (map[i] == '\n' && map[i + 1])
			i++;
		else if (map[i] != '1' && map[i] != '0' && map[i] != '\n'
			&& (map[i] != 'A' && map[i] != 'X') || map[0] == '\n')
			so_long->invalid++;
	}
	ft_lina(so_long);
}

/**
 * @brief Recursively validates the path in the game map starting from a given position.
 *
 * This function checks if the current position in the map is valid and updates the
 * game state accordingly. It increments the path points if a collectible ('C') is found,
 * and marks the position as visited by setting it to '1'. If the position is an exit ('E'),
 * it increments the path exit counter and marks the exit as visited. The function stops
 * recursion when encountering walls ('1'), enemies ('A', 'X'), or out-of-bounds positions.
 *
 * @param y The current y-coordinate (row) in the map.
 * @param x The current x-coordinate (column) in the map.
 * @param so_long A pointer to the game structure containing the map and game state.
 */
static void	path_certify(int y, int x, t_game *so_long)
{
	if (so_long->map[y][x] == 'C')
		so_long->path_points++;
	if (y < 0 || y >= so_long->map_y || x < 0 || x >= so_long->map_x
		|| so_long->map[y][x] == '1' || so_long->map[y][x] == 'E'
		|| so_long->map[y][x] == 'A' || so_long->map[y][x] == 'X')
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
 * @brief Validates the path in the game map to ensure it meets the required conditions.
 *
 * This function iterates through the game map to locate the player's starting position ('P').
 * Once found, it calls the `path_certify` function to verify the path's validity. The path
 * is considered valid if the number of path points matches the required points and the
 * number of exits matches the required exits. If the path is invalid, an error message is
 * printed, resources are freed, and the program exits.
 *
 * @param so_long A pointer to the game structure containing the map and related data.
 *
 * @note The function assumes that the map dimensions and other related data are already
 *       initialized in the `so_long` structure.
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
 * @brief Validates and processes the game map provided as input.
 *
 * This function performs the following steps:
 * 1. Opens the file specified in the command-line arguments.
 * 2. Reads the map data into a buffer.
 * 3. Validates the characters in the map to ensure they meet the game's requirements.
 * 4. Splits the map into a 2D array for further processing.
 * 5. Calculates the map's dimensions (width and height).
 * 6. Performs additional checks on the map structure and path validity.
 * 7. Frees and reinitializes certain resources for further use.
 * 8. Closes the file descriptor and frees allocated memory.
 *
 * @param av Command-line arguments, where av[1] is the path to the map file.
 * @param so_long Pointer to the game structure containing map and game state information.
 *
 * @note The function will terminate the program with an error message if:
 *       - The file cannot be opened.
 *       - The map fails any of the validation checks.
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
