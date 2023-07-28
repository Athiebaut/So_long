/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplir_fenetre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:50:17 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/28 15:29:52 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	mettre_limites(t_jeu *so_long)
{
	so_long->fichier = mlx_xpm_file_to_image(so_long->mlx,
				"./Img/Mur.xpm", &so_long->pixel, &so_long->pixel);
			mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->fichier,
				so_long->pixel * so_long->x, so_long->pixel * so_long->y);
}

void	mettre_joueur(t_jeu *so_long)
{
	so_long->fichier = mlx_xpm_file_to_image(so_long->mlx,
				"./Img/perso.xpm", &so_long->pixel, &so_long->pixel);
			mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->fichier,
				50 * so_long->x, 50 * so_long->y);
}