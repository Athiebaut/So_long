/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:10:46 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/20 16:26:16 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"
#include <fcntl.h>

void	check_characters(char *map, t_jeu *so_long)
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

void	ft_free(t_jeu *so_long)
{
	int	i;

	i = 0;
	while(so_long->carte[i])
	{
		free(so_long->carte[i]);
		i++;
	}
	free(so_long->carte);
}

void	check_map(t_jeu *so_long)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	len = ft_strlen(so_long->carte[i]);
	if (so_long->invalides > 0)
	{
		ft_printf("Error, caracteres invalides presents.\n");
		ft_free(so_long);
		exit(0);
	}
	/*while(carte[i])
	{
		
	}*/
}


void	valider_carte(int ac, char **av, t_jeu *so_long)
{
	char	*buffer;
	int	fd;
	//char **maps;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error, impossible de lire le fichier.\n");
		exit (1);
	}
	buffer = get_the_map(fd);
	check_characters(buffer, so_long);
	/*maps = ft_split(buffer, '\n');
	while(*maps)
	{
		ft_printf("%s\n\n", *maps);
		maps++;
	}*/
	so_long->carte = ft_split(buffer, '\n');
	so_long->carte_x = ft_strlen(so_long->carte[0]);
	so_long->carte_y = count_lines(so_long->carte);
	check_map(so_long);
	
	ft_printf("%i\n", so_long->carte_x);
	ft_printf("%i\n", so_long->carte_y);
}
