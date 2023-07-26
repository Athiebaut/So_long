/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:45:06 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/26 16:14:23 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Printf/ft_printf.h"
# include "../Libft/libft.h"

typedef struct s_jeu
{
	char	*buffer;
	char	**carte;
		int	carte_x;
		int	carte_y;
		int	joueur;
		int	points;
		int	sortie;
		int	invalides;
		int	x;
		int	y;
		int	chemin_points;
		int	chemin_sortie;
		
}		t_jeu;

void	ft_free(t_jeu *so_long);
char	*get_the_map(int fd);
size_t	count_lines(char **carte);

void	valider_carte(int ac, char **av, t_jeu *so_long);

void	check_carte(t_jeu *so_long);