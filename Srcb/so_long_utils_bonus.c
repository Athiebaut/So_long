/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:29:41 by athiebau          #+#    #+#             */
/*   Updated: 2023/09/14 13:38:09 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

void	enemy_0(t_game *so_long)
{
	so_long->map[so_long->e_y][so_long->e_x] = '0';
	so_long->map[so_long->e_y][so_long->e_x + 1] = 'A';
}

void	enemy_1(t_game *so_long)
{
	so_long->map[so_long->e_y][so_long->e_x] = '0';
	so_long->map[so_long->e_y][so_long->e_x - 1] = 'A';
}

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
		mlx_destroy_display(so_long->mlx);
	}
	if (info == 4)
	{
		mlx_destroy_window(so_long->mlx, so_long->mlx_win);
		mlx_destroy_display(so_long->mlx);
	}
	if (info == 2 || info == 3 || info == 4)
		free(so_long->mlx);
}

size_t	count_lines(char **carte)
{
	size_t	i;

	i = 0;
	while (carte[i])
		i++;
	return (i);
}

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
