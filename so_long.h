/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:01:25 by aaferyad          #+#    #+#             */
/*   Updated: 2025/03/01 16:46:08 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "parser/parser.h"
# include "mlx.h"

# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define ESC 65307

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
void	create_player(t_game *game, int x, int y);
void	create_empty(t_game *game, int x, int y);
void	*mlx_file_to_image(void *mlx, char *str);
void	n_coins_player_pos(t_game *game);
int		cleanup(t_game *game, int ex);

#endif
