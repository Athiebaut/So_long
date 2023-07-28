/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_fenetre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:05:11 by alix              #+#    #+#             */
/*   Updated: 2023/07/28 15:29:27 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

static void	remplir_surface(t_jeu *so_long)
{
	so_long->y = 0;
	while((so_long->y) < (so_long->carte_y))
	{
		so_long->x = 0;
		while ((so_long->x) < (so_long->carte_x))
		{
			so_long->fichier = mlx_xpm_file_to_image(so_long->mlx,
				"./Img/Sol.xpm", &so_long->pixel, &so_long->pixel);
			mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->fichier,
				so_long->pixel * so_long->x, so_long->pixel * so_long->y);
			so_long->x++;
		}
		so_long->y++;
	}
}

void	remplir_fenetre(t_jeu *so_long)
{
	remplir_surface(so_long);
	so_long->y = 0;
	while((so_long->y) < (so_long->carte_y))
	{
		so_long->x = 0;
		while ((so_long->x) < (so_long->carte_x))
		{
			if (so_long->carte[so_long->y][so_long->x] == '1')
				mettre_limites(so_long);
			if (so_long->carte[so_long->y][so_long->x] == 'P')
				mettre_joueur(so_long);
			so_long->x++;
		}
		so_long->y++;
	}
}