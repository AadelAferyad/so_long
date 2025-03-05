/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:33:38 by aaferyad          #+#    #+#             */
/*   Updated: 2025/03/03 04:52:34 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "parser/parser.h"
# include "mlx.h"

# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define ESC 65307

# define DELAY 5000

typedef struct game_map
{
	int		y;
	int		x;
	int		exit_y;
	int		exit_x;
	int		width;
	int		height;
	int		coins;
	int		door;
	char	**map;
	void	*mlx;
	void	*win;
}	t_game;

void	game_init(t_game *game);
void	create_collectible(t_game *game, int x, int y);
void	create_exit(t_game *game, int x, int y);
void	create_player(t_game *game, int x, int y, char *str);
void	create_empty(t_game *game, int x, int y);
void	*mlx_file_to_image(void *mlx, char *str);
void	n_coins_player_pos(t_game *game);
int		cleanup(t_game *game);
void	player_animation_front(t_game *game, int x, int y);
void	create_animation(t_game *game, int x, int y);
void	player_animation_back(t_game *game, int x, int y);
void	player_animation_right(t_game *game, int x, int y);
void	player_animation_left(t_game *game, int x, int y);

#endif
