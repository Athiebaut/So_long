/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:29:41 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:50:54 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

/**
 * @brief Frees allocated memory and destroys graphical resources associated
 *        with the game.
 * 
 * This function is responsible for cleaning up resources used by the game,
 * including the map, buffer, and graphical components. The behavior of the
 * function depends on the value of the `info` parameter:
 * 
 * - If `info == 1`: Frees the buffer.
 * - If `info == 3`: Destroys the image and window, and cleans up the display.
 * - If `info == 4`: Destroys the window and cleans up the display.
 * - If `info == 2`, `info == 3`, or `info == 4`: Cleans up the display and
 *   frees the `mlx` instance.
 * 
 * @param so_long Pointer to the game structure containing resources to free.
 * @param info Integer flag indicating which resources to free and destroy.
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
 * This function iterates through a null-terminated array of strings
 * and returns the total number of lines (elements) in the array.
 *
 * @param carte A null-terminated array of strings.
 * @return The number of lines (elements) in the array.
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
 * This function reads data from a file descriptor in chunks of 1024 bytes 
 * and appends it to the provided map string. If an error occurs during 
 * reading, it prints an error message, frees the allocated memory for the 
 * map, and terminates the program.
 * 
 * @param fd The file descriptor of the map file to be read.
 * @param map A pointer to the initial map string (can be NULL).
 * 
 * @return A pointer to the dynamically allocated string containing the 
 * complete map content.
 * 
 * @note The function uses `ft_strjoin` to concatenate strings and assumes 
 * it handles memory allocation correctly. The caller is responsible for 
 * freeing the returned string to avoid memory leaks.
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
