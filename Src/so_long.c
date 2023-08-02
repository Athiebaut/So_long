/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:55:36 by athiebau          #+#    #+#             */
/*   Updated: 2023/08/01 23:59:20 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

static void fenetre(t_jeu *so_long)
{
	so_long->pixel = 60;
	so_long->mlx = mlx_init();
	so_long->mlx_win = mlx_new_window(so_long->mlx, so_long->pixel * so_long->carte_x,
	 so_long->pixel * so_long->carte_y, "Advance Effect");
	remplir_fenetre(so_long);
}


// static void	map_init(t_jeu *so_long)
// {
// 	so_long->buffer = NULL;
// 	so_long->carte = NULL;
// 	so_long->carte_x = 0;
// 	so_long->carte_y = 0;
// 	so_long->joueur = 0;
// 	so_long->points = 0;
// 	so_long->sortie = 0;
// 	so_long->invalides = 0;
// 	so_long->chemin_points = 0;
// 	so_long->chemin_sortie = 0;
// }

static void	check_args(int ac, char **av) //check 2 arguments + fichier '.ber'
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
		exit (0);
	}
}

int	main(int ac, char **av)
{
	t_jeu	so_long;

	check_args(ac, av);
	ft_bzero(&so_long, sizeof(t_jeu));
	// map_init(&so_long);
	valider_carte(av, &so_long);
	fenetre(&so_long);
	mlx_loop(so_long.mlx);
}