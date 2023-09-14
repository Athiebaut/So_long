/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_certify_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:10:46 by athiebau          #+#    #+#             */
/*   Updated: 2023/09/14 12:22:29 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"
#include <fcntl.h>

static void	check_characters(char *map, t_game *so_long)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			so_long->player++;
		else if (map[i] == 'C')
			so_long->points++;
		else if (map[i] == 'E')
			so_long->exit++;
		else if (map[i] == '\n')
			i++;
		else if (map[i] != '1' && map[i] != '0' && map[i] != '\n'
			&& map[i] != 'A' && map[i] != 'X')
			so_long->invalid++;
		i++;
	}
	if (so_long->player != 1 || so_long->exit != 1 || so_long->points < 1)
	{
		ft_printf("/!\\ Erreur, nombre de joueur, sortie ");
		ft_printf("ou collectibles incorrect. /!\\\n");
		ft_free(so_long, 1);
		exit(0);
	}
}

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
