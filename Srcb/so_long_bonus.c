/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:55:36 by athiebau          #+#    #+#             */
/*   Updated: 2023/09/25 11:51:42 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long_bonus.h"

static void	window_error(t_game *so_long)
{
	ft_printf("/!\\ Erreur, taille de la fenetre plus grande que l'ecran. /!\\\n");
	ft_free(so_long, 2);
	exit(1);
}

static void	window(t_game *so_long)
{
	int	sizex;
	int	sizey;
	
	sizex = 0;
	sizey = 0;
	so_long->pixel = 60;
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
	{
		ft_free(so_long, 0);
		exit(1);
	}
	mlx_get_screen_size(so_long->mlx, &sizex, &sizey);
	if (sizex < so_long->pixel * so_long->map_x || sizey < so_long->pixel * so_long->map_y)
		window_error(so_long);
	so_long->mlx_win = mlx_new_window(so_long->mlx, (so_long->pixel
				* so_long->map_x) + 100, so_long->pixel
			* so_long->map_y, "Advance Effect");
	if (!so_long->mlx_win)
		(ft_free(so_long, 2), exit(1));
	so_long->enemy_file = "./Img/enemy1.xpm";
	so_long->player_file = "./Img/player1.xpm";
	so_long->points_file = "./Img/coin1.xpm";
	so_long->exit_file = "./Img/exit1.xpm";
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
	mlx_loop_hook(so_long.mlx, frames, &so_long);
	mlx_hook(so_long.mlx_win, 2, 1L << 0, key_hook, &so_long);
	mlx_hook(so_long.mlx_win, 17, 0, close_window, &so_long);
	mlx_loop(so_long.mlx);
	ft_free(&so_long, 3);
}
