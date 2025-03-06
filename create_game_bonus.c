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

void	create_enemy(t_game *game, int x, int y)
{
	void	*img;

	img = mlx_file_to_image(game->mlx, "./sprites/enemy.xpm");
	game->enemy_y = y;
	game->enemy_x = x;
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
			if (game->map[y][x] == EXIT)
				create_exit(game, x, y);
			if (game->map[y][x] == 'N')
				create_enemy(game, x, y);
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
		if (game->map[y][x] == EXIT && game->coins)
			return ;
		create_empty(game, game->x, game->y);
		create_animation(game, x, y);
		moves++;
		ft_putnbr_fd(moves, 1);
		ft_putchar('\n');
		if ((game->map[y][x] == EXIT && !game->coins) || (x == game->enemy_x && y == game->enemy_y))
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

int	find_enemy_path(t_game *game, int x, int y)
{
	if (x <= 0 || x >= game->width || y <= 0 || y >= game->height)
		return (0);
	if (x == game->x && y == game->y)
		cleanup(game);
	if (game->map[y][x] == EMPTY)
		return (1);

	return (0);
}

void	move_enemy(t_game *game)
{
	static int	j;
	int	x;
	int	y;

	y = game->enemy_y;
	x = game->enemy_x;
	if (!j && find_enemy_path(game, x + 1, y))
		x++;
	else if (!j && find_enemy_path(game, x, y + 1))
		y++;
	else
		j = 1;
	if (j && find_enemy_path(game, x - 1, y))
		x--;
	else if (j && find_enemy_path(game, x, y - 1))
		y--;
	else
		j = 0;
	create_empty(game, game->enemy_x, game->enemy_y);
	create_enemy(game, x, y);
}

int no_event(t_game *game)
{
	static int	i;

	if (i < DELAY)
	{
		i++;
		return (0);
	}
	move_enemy(game);
	i = 0;
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
