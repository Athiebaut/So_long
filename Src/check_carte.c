/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_carte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:28:40 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/26 16:18:03 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

static void	verifier_limites_x(t_jeu *so_long)
{
	int	i;
	int	last;

	i = -1;
	last = so_long->carte_y - 1;
	while (so_long->carte[0][++i])
	{
		if(so_long->carte[0][i] != '1')
		{
			ft_printf("Error, la carte n'est pas cernee de murs.\n");
			ft_free(so_long);
			exit(0);	
		}
	}
	i = -1;
	while (so_long->carte[last][++i])
	{
		if(so_long->carte[last][i] != '1')
		{
			ft_printf("Error, la carte n'est pas cernee de murs.\n");
			ft_free(so_long);
			exit(0);	
		}
	}
}

static void	verifier_limites_y(t_jeu *so_long)
{
	int	i;
	int	last;

	i = 0;
	last = so_long->carte_x - 1;
	while(++i < so_long->carte_y - 1)
	{
		if(so_long->carte[i][0] != '1')
		{
			ft_printf("Error, la carte n'est pas cernee de murs.\n");
			ft_free(so_long);
			exit(0);	
		}	
	}
	i = 0;
	while(++i < so_long->carte_y - 1)
	{
		if(so_long->carte[i][last] != '1')
		{
			ft_printf("Error, la carte n'est pas cernee de murs.\n");
			ft_free(so_long);
			exit(0);	
		}	
	}
}

void	check_carte(t_jeu *so_long)
{
	int	i;
	int	len;
	int	tmp;

	i = -1;
	len = ft_strlen(so_long->carte[0]);
	if (so_long->invalides > 0)
	{
		ft_printf("Error, caracteres invalides presents.\n");
		ft_free(so_long);
		exit(0);
	}
	while(so_long->carte[++i])
	{
		if (ft_strlen(so_long->carte[i]) != len)
			{
				ft_printf("Error, la carte n'est pas rectangulaire.\n");
				ft_free(so_long);
				exit(0);
			}
	}
	verifier_limites_x(so_long);
	verifier_limites_y(so_long);
}