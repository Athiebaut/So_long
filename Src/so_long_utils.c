/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:29:41 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/20 16:28:37 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

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
		map = str_join(map, buffer);
	}
	free(buffer);
	return (map);
}

char	*str_chr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*str_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((sizeof(char)) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	free(s1);
	return (str);
}