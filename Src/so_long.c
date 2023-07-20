/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:55:36 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/20 16:01:33 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	map_init(t_jeu *so_long)
{
	so_long->carte = NULL;
	so_long->carte_x = 0;
	so_long->carte_y = 0;
	so_long->joueur = 0;
	so_long->points = 0;
	so_long->sortie = 0;
	so_long->invalides = 0;
}

void	check_args(int ac, char **av)
{
	int	len;
	
	if (ac != 2)
	{
		ft_printf("Error, mauvais nombre d'arguments.\n");
		exit(0);
	}
	len = ft_strlen(av[1]);
	if (av[1][len - 4] != '.' || av[1][len - 3] != 'b' || av[1][len - 2] != 'e' || av[1][len - 1] != 'r')
	{
		ft_printf("Error, extension de la map incorrecte, merci de fournir un fichier \'.ber\'.\n");
		exit (1);
	}
}

int	main(int ac, char **av)
{
	t_jeu	so_long;

	check_args(ac, av);
	map_init(&so_long);
	valider_carte(ac, av, &so_long);
}