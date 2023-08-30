/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:55:36 by athiebau          #+#    #+#             */
/*   Updated: 2023/08/30 22:47:28 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

static void	window(t_game *so_long)
{
	so_long->pixel = 60;
	so_long->mlx = mlx_init();
	so_long->mlx_win = mlx_new_window(so_long->mlx, so_long->pixel
			* so_long->map_x, so_long->pixel
			* so_long->map_y, "Advance Effect");
	ft_printf("4\n");
	fill_window(so_long);
}

static void	check_args(int ac, char **av)
{
	int	len;

	if (ac != 2)
	{
		ft_printf("Error, mauvais nombre d'arguments.\n");
		exit(0);
	}
	len = ft_strlen(av[1]);
	if (av[1][len - 4] != '.' || av[1][len - 3] != 'b'
		|| av[1][len - 2] != 'e' || av[1][len - 1] != 'r')
	{
		ft_printf("Error, extension de la map incorrecte, ");
		ft_printf("merci de fournir un fichier \'.ber\'.\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_game	so_long;

	check_args(ac, av);
	ft_printf("1\n");
	ft_bzero(&so_long, sizeof(t_game));
	ft_printf("2\n");
	map_certify(av, &so_long);
	ft_printf("3\n");
	window(&so_long);
	ft_printf("5\n");
	mlx_loop(so_long.mlx);
}
