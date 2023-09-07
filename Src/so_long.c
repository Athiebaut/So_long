/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:55:36 by athiebau          #+#    #+#             */
/*   Updated: 2023/09/04 14:32:59 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

static void	window(t_game *so_long)
{
	so_long->pixel = 60;
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
	{
		ft_free(so_long, 0);
		exit(1);
	}
	so_long->mlx_win = mlx_new_window(so_long->mlx, so_long->pixel
			* so_long->map_x, so_long->pixel
			* so_long->map_y, "Advance Effect");
	if (!so_long->mlx_win)
	{
		ft_free(so_long, 2);
		exit(1);
	}
	fill_window(so_long);
}

static void	check_args(int ac, char **av)
{
	int	len;

	if (ac != 2)
	{
		ft_printf("/!\\ Erreur, mauvais nombre d'arguments. /!\\\n");
		exit(0);
	}
	len = ft_strlen(av[1]);
	if (av[1][len - 4] != '.' || av[1][len - 3] != 'b'
		|| av[1][len - 2] != 'e' || av[1][len - 1] != 'r')
	{
		ft_printf("/!\\ Erreur, extension de la map incorrecte, ");
		ft_printf("merci de fournir un fichier \'.ber\'. /!\\\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_game	so_long;

	check_args(ac, av);
	ft_bzero(&so_long, sizeof(t_game));
	map_certify(av, &so_long);
	window(&so_long);
	mlx_hook(so_long.mlx_win, 2, 1L << 0, key_hook, &so_long);
	mlx_hook(so_long.mlx_win, 17, 0, close_window, &so_long);
	mlx_loop(so_long.mlx);
	ft_free(&so_long, 3);
}
