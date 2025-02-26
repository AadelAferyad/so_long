/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:03:51 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/24 13:37:10 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_wall(t_game *game, int x, int y)
{
	int	width;
	int	height;
	void	*image;

	if (!y)
		image = mlx_xpm_file_to_image(game->mlx, "./sprites/bot_wall.xpm", &width, &height);
	else if (y == game->height - 1)
		image = mlx_xpm_file_to_image(game->mlx, "./sprites/up_wall.xpm", &width, &height);
	else if (x == game->width - 1)
		image = mlx_xpm_file_to_image(game->mlx, "./sprites/right_wall.xpm", &width, &height);
	else if (!x)
		image = mlx_xpm_file_to_image(game->mlx, "./sprites/left_wall.xpm", &width, &height);
	else
		image = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", &width, &height);
	if (!image)
		exit(21);
	mlx_put_image_to_window(game->mlx, game->win, image, x * 40, y * 40);
	mlx_destroy_image(game->mlx, image);
}

void	create_collectible(t_game *game, int x, int y)
{
	int	width;
	int	height;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, "./sprites/coin.xpm", &width, &height);
	if (!img)
		exit(21);
	mlx_put_image_to_window(game->mlx, game->win, img, x * 40, y * 40);
	mlx_destroy_image(game->mlx, img);

}

void	create_exit(t_game *game, int x, int y)
{
	int	width;
	int	height;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, "./sprites/door.xpm", &width, &height);
	if (!img)
		exit(21);
	mlx_put_image_to_window(game->mlx, game->win, img, x * 40, y * 40);
	mlx_destroy_image(game->mlx, img);
}

void	create_player(t_game *game, int x, int y)
{
	int	width;
	int	height;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm", &width, &height);
	if (!img)
		exit(21);
	mlx_put_image_to_window(game->mlx, game->win, img, x * 40, y * 40);
	mlx_destroy_image(game->mlx, img);
}

void	create_empty(t_game *game, int x, int y)
{
	int	width;
	int	height;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, "./sprites/empty.xpm", &width, &height);
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
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == WALL)
				create_wall(game, x, y);
			if (game->map[y][x] == COIN)
			{
				game->coins++;
				create_collectible(game, x, y);
			}
			if (game->map[y][x] == EXIT)
				create_exit(game, x, y);
			if (game->map[y][x] == PLAYER)
			{
				game->x = x;
				game->y = y;
				create_player(game, x, y);
			}
			x++;
		}
		y++;
	}
}

int	cleanup(t_game *game)
{
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

void	movment(t_game *game, int x , int y)
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
		create_player(game, x, y);
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
	movment(game, x , y);
	return (0);
}

void	game_init(t_game *game)
{

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 40, game->height * 40, "so_long");
	rander_game(game);
	mlx_hook(game->win, 2, 3, handle_key, game);
	mlx_hook(game->win, 17, 2, cleanup, game);
	mlx_loop(game->mlx);
}
