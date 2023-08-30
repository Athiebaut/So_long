/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:45:06 by athiebau          #+#    #+#             */
/*   Updated: 2023/08/30 22:42:51 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Printf/ft_printf.h"
# include "../Libft/libft.h"
# include "../mlx_linux/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*file;
	char	*buffer;
	char	**map;
		int	map_x;
		int	map_y;
		int	player;
		int	points;
		int	exit;
		int	invalid;
		int	x;
		int	y;
		int	path_points;
		int	path_exit;
		int	pixel;
		
}		t_game;

void	ft_free(t_game *so_long);
char	*get_the_map(int fd, char *map);
size_t	count_lines(char **carte);

void	map_certify(char **av, t_game *so_long);
void	check_map(t_game *so_long);

void	fill_window(t_game *so_long);
void	place_borders(t_game *so_long);
void	place_player(t_game *so_long);
void	place_points(t_game *so_long);
void	place_exit(t_game *so_long);