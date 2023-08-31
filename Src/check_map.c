/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:28:40 by athiebau          #+#    #+#             */
/*   Updated: 2023/08/31 16:56:48 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

static void	print_error(t_game *so_long)
{
	ft_printf("/!\\ Erreur, la carte n'est pas cernée de murs.\n");
	ft_printf("Merci d'en construire un à l'emplacement concerné. /!\\\n");
	ft_free(so_long, 1);
	exit(0);
}

static void	check_x_borders(t_game *so_long)
{
	int	i;
	int	last;

	i = 0;
	last = so_long->map_y - 1;
	while (so_long->map[0][i])
	{
		if (so_long->map[0][i] != '1')
			print_error(so_long);
		i++;
	}
	i = 0;
	while (so_long->map[last][i])
	{
		if (so_long->map[last][i] != '1')
			print_error(so_long);
		i++;
	}
}

static void	check_y_borders(t_game *so_long)
{
	int	i;
	int	last;

	i = 1;
	last = so_long->map_x - 1;
	while (i < so_long->map_y - 1)
	{
		if (so_long->map[i][0] != '1')
			print_error(so_long);
		i++;
	}
	i = 1;
	while (i < so_long->map_y - 1)
	{
		if (so_long->map[i][last] != '1')
			print_error(so_long);
		i++;
	}
}

void	check_map(t_game *so_long)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(so_long->map[0]);
	if (so_long->invalid > 0)
	{
		ft_printf("/!\\ Erreur, caracteres invalides presents. /!\\\n");
		ft_free(so_long, 1);
		exit(0);
	}
	while (so_long->map[i])
	{
		if (ft_strlen(so_long->map[i]) != len)
		{
			ft_printf("/!\\ Erreur, la carte n'est pas rectangulaire. /!\\\n");
			ft_free(so_long, 1);
			exit(0);
		}
		i++;
	}
	check_x_borders(so_long);
	check_y_borders(so_long);
}
