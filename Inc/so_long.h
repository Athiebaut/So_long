/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:45:06 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/20 16:01:37 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Printf/ft_printf.h"
# include "../Libft/libft.h"

typedef struct s_jeu
{
	char	**carte;
		int	carte_x;
		int	carte_y;
		int	joueur;
		int	points;
		int	sortie;
		int	invalides;
		
}		t_jeu;

char	*str_join(char *s1, char *s2);
char	*str_chr(char *s, int c);
char	*get_the_map(int fd);
size_t	count_lines(char **carte);

void	check_characters(char *map, t_jeu *so_long);
void	valider_carte(int ac, char **av, t_jeu *so_long);