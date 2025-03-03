/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:35:20 by aaferyad          #+#    #+#             */
/*   Updated: 2025/03/03 05:02:38 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create_wall(t_game *game, int x, int y)
{
	void	*img;

	if (!y)
		img = mlx_file_to_image(game->mlx, "./sprites/bot_wall.xpm");
	else if (y == game->height - 1)
		img = mlx_file_to_image(game->mlx, "./sprites/up_wall.xpm");
	else if (x == game->width - 1)
		img = mlx_file_to_image(game->mlx, "./sprites/right_wall.xpm");
	else if (!x)
		img = mlx_file_to_image(game->mlx, "./sprites/left_wall.xpm");
	else
		img = mlx_file_to_image(game->mlx, "./sprites/wall.xpm");
	if (!img)
		exit(21);
	mlx_put_image_to_window(game->mlx, game->win, img, x * 40, y * 40);
	mlx_destroy_image(game->mlx, img);
}

void	rander_game(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->coins = 0;
	n_coins_player_pos(game);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == WALL)
				create_wall(game, x, y);
			if (game->map[y][x] == COIN)
				create_collectible(game, x, y);
			if (game->map[y][x] == PLAYER)
				create_player(game, x, y, "./sprites/front_walk8.xpm");
			if (game->map[y][x] == EMPTY)
				create_empty(game, x, y);
			x++;
		}
		y++;
	}
}


void	movment(t_game *game, int x, int y)
{
	static int	moves;

	if (game->map[y][x] != WALL)
	{
		if (game->map[y][x] == COIN)
		{
			game->map[y][x] = EMPTY;
			game->coins--;
		}
		if (!game->coins)
			create_exit(game, game->exit_x, game->exit_y);
		create_empty(game, game->x, game->y);
		create_animation(game, x, y);
		moves++;
		ft_putnbr_fd(moves, 1);
		ft_putchar('\n');
		if (game->map[y][x] == EXIT && !game->coins)
			cleanup(game);
		game->x = x;
		game->y = y;
	}
}

int	handle_key(int key_code, t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (key_code == ESC)
		cleanup(game);
	if (key_code == UP)
		y--;
	else if (key_code == DOWN)
		y++;
	else if (key_code == LEFT)
		x--;
	else if (key_code == RIGHT)
		x++;
	else
		return (0);
	movment(game, x, y);
	return (0);
}

int no_event(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->map[i])
	{
		j = 1;
		while (game->map[i][j])
		{
			if (game->map[i][j] == COIN)
			{
				create_collectible(game, j, i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 40,
			game->height * 40, "so_long");
	rander_game(game);
	mlx_loop_hook(game->mlx, no_event, game);
	mlx_hook(game->win, 2, 3, handle_key, game);
	mlx_hook(game->win, 17, 2, cleanup, game);
	mlx_loop(game->mlx);
}
