/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:03:10 by athiebau          #+#    #+#             */
/*   Updated: 2023/09/14 13:38:31 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../Libft/libft.h"
# include "../Printf/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*file;
	char	*buffer;
	char	**map;
	int		map_x;
	int		map_y;
	int		player;
	char	*player_file;
	int		p_x;
	int		p_y;
	int		p_moove;
	int		enemy;
	char	*enemy_file;
	int		e_x;
	int		e_y;
	int		points;
	char	*points_file;
	int		exit;
	char	*exit_file;
	int		invalid;
	int		x;
	int		y;
	int		path_points;
	int		path_exit;
	int		pixel;

}			t_game;

void		ft_free(t_game *so_long, int info);
char		*get_the_map(int fd, char *map);
size_t		count_lines(char **carte);

void		map_certify(char **av, t_game *so_long);
void		check_map(t_game *so_long);

void		fill_window(t_game *so_long);
int			close_window(t_game *so_long);

void		place_floor(t_game *so_long);
void		place_borders(t_game *so_long);
void		place_player(t_game *so_long);
void		place_points(t_game *so_long);
void		place_exit(t_game *so_long);

int			key_hook(int keycode, t_game *so_long);

void		print_movements(t_game *so_long);

void		enemy_0(t_game *so_long);
void		enemy_1(t_game *so_long);

void		place_enemy(t_game *so_long);
void		place_patrol(t_game *so_long);
void		enemies_movements(t_game *so_long);

int			frames(t_game *so_long);
void		exit_opening(t_game *so_long);
#endif