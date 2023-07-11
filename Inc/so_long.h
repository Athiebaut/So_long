/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:45:06 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/11 11:54:13 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_jeu
{
	char	**carte;
		int	carte_x;
		int	carte_y;
		int	joueur;
		int	points;
		int	sortie;
		int	invalide;
		
}		t_jeu;