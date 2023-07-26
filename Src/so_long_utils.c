/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:29:41 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/26 16:16:48 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	ft_free(t_jeu *so_long)
{
	int	i;

	i = 0;
	while(so_long->carte[i])
	{
		free(so_long->carte[i]);
		i++;
	}
	free(so_long->carte);
	free(so_long->buffer);
}

size_t	count_lines(char **carte)
{
	size_t	i;

	i = 0;
	while(carte[i])
		i++;
	return (i);
}

char	*get_the_map(int fd)
{
	char	*buffer;
	char	*map;
	int	reads;

	buffer = (char *)malloc(11);
	if (!buffer)
		return (NULL);
	reads = 1;
	while (reads > 0)
	{
		reads = read(fd, buffer, 10);
		if (reads == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[reads] = '\0';
		map = ft_strjoin(map, buffer);
	}
	free(buffer);
	return (map);
}


