/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:29:41 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 03:01:17 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

/**
 * @brief Moves the enemy character in the game map.
 * 
 * This function updates the game map to move the enemy character
 * ('A') one position to the left. It replaces the current position
 * of the enemy with '0' (empty space) and sets the new position
 * to 'A'.
 * 
 * ('A') one position to the right. It replaces the current position
 * of the enemy with '0' (empty space) and sets the new position to 'A'.
 * 
 * @param so_long A pointer to the game structure containing the map
 *                and the enemy's current coordinates (e_x, e_y).
 */
void	enemy_0(t_game *so_long)
{
	so_long->map[so_long->e_y][so_long->e_x] = '0';
	so_long->map[so_long->e_y][so_long->e_x + 1] = 'A';
}

/**
 * @brief Moves the enemy character (type 'A') one position to the left on the game map.
 * 
 * This function updates the game map by setting the current position of the enemy
 * to '0' (empty space) and moving the enemy one position to the left. It assumes
 * that the enemy's current position is stored in the `e_x` and `e_y` fields of the
 * `t_game` structure.
 * 
 * @param so_long Pointer to the game structure containing the map and enemy position.
 */
void	enemy_1(t_game *so_long)
{
	so_long->map[so_long->e_y][so_long->e_x] = '0';
	so_long->map[so_long->e_y][so_long->e_x - 1] = 'A';
}

/**
 * @brief Frees allocated memory and destroys graphical resources based on the provided info flag.
 * 
 * This function is responsible for cleaning up resources used by the game. It frees the map,
 * buffer, and graphical resources (images, windows, and display) depending on the value of the
 * `info` parameter.
 * 
 * @param so_long Pointer to the game structure containing all resources to be freed.
 * @param info Integer flag that determines which resources to free:
 *             - 1: Frees the buffer.
 *             - 2: Frees the display and mlx instance.
 *             - 3: Frees the buffer, destroys the image, window, display, and mlx instance.
 *             - 4: Destroys the window, display, and mlx instance.
 * 
 * The function ensures that all allocated memory and graphical resources are properly released
 * to prevent memory leaks.
 */
void	ft_free(t_game *so_long, int info)
{
	int	i;

	i = -1;
	if (so_long->map)
	{
		while (so_long->map[++i])
			free(so_long->map[i]);
		free(so_long->map);
	}
	if (info == 1)
		free(so_long->buffer);
	if (info == 3)
	{
		mlx_destroy_image(so_long->mlx, so_long->file);
		mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	}
	if (info == 4)
		mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	if (info == 2 || info == 3 || info == 4)
	{
		mlx_destroy_display(so_long->mlx);
		free(so_long->mlx);
	}
}

/**
 * @brief Counts the number of lines in a 2D array of strings.
 * 
 * This function iterates through the given 2D array of strings (`carte`)
 * and counts how many non-NULL entries it contains. It assumes that the
 * array is NULL-terminated.
 * 
 * @param carte A NULL-terminated 2D array of strings.
 * @return The number of lines (non-NULL entries) in the array.
 */
size_t	count_lines(char **carte)
{
	size_t	i;

	i = 0;
	while (carte[i])
		i++;
	return (i);
}

/**
 * @brief Reads the content of a map file and stores it in a dynamically 
 * allocated string.
 * 
 * This function reads data from the file descriptor `fd` in chunks of 1024 
 * bytes and appends it to the `map` string using `ft_strjoin`. If an error 
 * occurs during reading, it prints an error message, frees the `map` string, 
 * and exits the program with a status of 1.
 * 
 * @param fd The file descriptor of the map file to be read.
 * @param map A pointer to the initial map string, which can be NULL or 
 * an already allocated string.
 * 
 * @return A pointer to the dynamically allocated string containing the 
 * complete map content. The caller is responsible for freeing this memory.
 * 
 * @note The function assumes that `ft_strjoin` handles memory allocation 
 * and appends the content correctly. Ensure `ft_strjoin` is implemented 
 * properly to avoid memory leaks or undefined behavior.
 * 
 * @warning If the `read` system call fails, the program will terminate 
 * with an error message.
 */
char	*get_the_map(int fd, char *map)
{
	int		reads;
	char	buffer[1024];

	reads = 1;
	while (reads > 0)
	{
		reads = read(fd, buffer, 1024);
		if (reads == -1)
		{
			ft_printf ("/!\\ Erreur, lecture de la map impossible. /!\\\n");
			free(map);
			exit(1);
		}
		buffer[reads] = '\0';
		map = ft_strjoin(map, buffer);
	}
	return (map);
}
