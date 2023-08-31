/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:29:41 by athiebau          #+#    #+#             */
/*   Updated: 2023/08/31 16:58:22 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	ft_free(t_game *so_long, int info)
{
	int	i;

	i = 0;
	if (so_long->map)
	{
		while (so_long->map[i])
		{
			free(so_long->map[i]);
			i++;
		}
		free(so_long->map);
	}
	if (so_long->buffer && info == 1)
		free(so_long->buffer);
	if (so_long->mlx)
		free(so_long->mlx);
	if (so_long->mlx_win)
		free(so_long->mlx_win);
}

size_t	count_lines(char **carte)
{
	size_t	i;

	i = 0;
	while (carte[i])
		i++;
	return (i);
}

char	*get_the_map(int fd, char *map)
{
	int		reads;
	char	buffer[1024];

	reads = 1;
	while (reads > 0)
	{
		reads = read(fd, buffer, 1024);
		if (reads == -1)
		{
			ft_printf ("/!\\ Erreur, lecture de la map impossible. /!\\\n");
			free(map);
			exit(1);
		}
		buffer[reads] = '\0';
		map = ft_strjoin(map, buffer);
	}
	return (map);
}
