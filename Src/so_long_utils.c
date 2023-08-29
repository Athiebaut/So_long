/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:29:41 by athiebau          #+#    #+#             */
/*   Updated: 2023/08/29 16:36:44 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	ft_free(t_game *so_long)
{
	int	i;

	i = 0;
	while (so_long->map[i])
	{
		free(so_long->map[i]);
		i++;
	}
	free(so_long->map);
	free(so_long->buffer);
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

	//buffer = (char *)malloc(sizeof(char) * 11);
	if (!buffer)
		return (NULL);
	reads = 1;
	while (reads > 0)
	{
		reads = read(fd, buffer, 1024);
		if (reads == -1)
		{
			//free(buffer);
			return (NULL);
		}
		buffer[reads] = '\0';
		map = ft_strjoin(map, buffer);
	}
	//free(buffer);
	return (map);
}
