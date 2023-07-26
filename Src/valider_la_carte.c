/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valider_la_carte.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:10:46 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/26 16:42:52 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"
#include <fcntl.h>

static void	check_characters(char *map, t_jeu *so_long)
{
	int	i;

	i = 0;
	while(map[i])
	{
		if (map[i] == 'P')
			so_long->joueur++;
		else if (map[i] == 'C')
			so_long->points++;
		else if (map[i] == 'E')
			so_long->sortie++;
		else if (map[i] == '\n')
			i++;
		else if (map[i] != '1' && map[i] != '0' && map[i] != '\n')
			so_long->invalides++;
		i++;
	}
	if (so_long->joueur != 1 || so_long->sortie != 1 || so_long->points < 1)
	{
		ft_printf("Error, nombre de joueur, sortie ou collectibles incorrect.\n");
		free(map);
		exit(0);
	}
}

void	valider_chemin(int y, int x, t_jeu *so_long)
{
	if (so_long->carte[y][x] == 'E')
		so_long->chemin_sortie++;
	if (so_long->carte[y][x] == 'C')
		so_long->chemin_points++;
	if (y < 0 || y >= so_long->carte_y || x < 0 || x >= so_long->carte_x || so_long->carte[y][x] == '1')
		return ;
	so_long->carte[y][x] = '1';
	/*for (int i = 0; i < so_long->carte_y; i++)
	{
		ft_printf("%s\n", so_long->carte[i]);
	}
	ft_printf("--------------------\n");*/
	valider_chemin(y, (x - 1), so_long);
	valider_chemin(y, (x + 1), so_long);
	valider_chemin((y - 1), x, so_long);
	valider_chemin((y + 1), x, so_long);
}

void	check_chemin(t_jeu *so_long)
{
	so_long->y = 0;
	while(++so_long->y < so_long->carte_y)
	{
		so_long->x = 0;
		while(++so_long->x < so_long->carte_x)
		{
			if (so_long->carte[so_long->y][so_long->x] == 'P')
			{
				valider_chemin(so_long->y, so_long->x, so_long);
				if (so_long->chemin_points == so_long->points && so_long->chemin_sortie == so_long->sortie)
				{
					so_long->x = 0;
					so_long->y = 0;
					ft_printf("Good\n");
					return ;
				}
				else
				{
					ft_printf("Error, le chemin n'est pas valide.\n");
					ft_free(so_long);
					exit(0);	
				}
			}	
		}
	}
	
}

void	valider_carte(int ac, char **av, t_jeu *so_long)
{
	int	fd;
	write(1, "coucou\n", 7);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error, impossible de lire le fichier.\n");
		exit (1);
	}
	so_long->buffer = get_the_map(fd);
	check_characters(so_long->buffer, so_long);
	so_long->carte = ft_split(so_long->buffer, '\n');
	so_long->carte_x = ft_strlen(so_long->carte[0]);
	so_long->carte_y = count_lines(so_long->carte);
	check_carte(so_long);
	check_chemin(so_long);
	so_long->carte = ft_split(so_long->buffer, '\n');
	free(so_long->buffer);
	close(fd);
}
