/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:29:41 by athiebau          #+#    #+#             */
/*   Updated: 2023/08/02 00:12:07 by alix             ###   ########.fr       */
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

#include <stdio.h>
char	*get_the_map(int fd, char *map)
{
	char	buffer[1024];
	int	reads;
	
	// buffer = (char *)malloc(sizeof(char) * 11);
	if (!buffer)
		return (NULL);
	reads = 1;
	while (reads > 0)
	{
		reads = read(fd, buffer, 1024);
		printf("I am wrong : %d\n", reads);
		if (reads == -1)
		{
			// free(buffer);
			return (NULL);
		}
		buffer[reads] = '\0';
		map = ft_strjoin(map, buffer);
	}
	// free(buffer);
	return (map);
}


