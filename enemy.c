/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:03:16 by aaferyad          #+#    #+#             */
/*   Updated: 2025/03/07 03:13:57 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create_enemy(t_game *game, int x, int y)
{
	void	*img;

	img = mlx_file_to_image(game->mlx, "./textures/enemy.xpm");
	game->enemy_y = y;
	game->enemy_x = x;
	if (!img)
		exit(21);
	mlx_put_image_to_window(game->mlx, game->win, img, x * 40, y * 40);
	mlx_destroy_image(game->mlx, img);
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
	int			x;
	int			y;

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

void	printer(t_game *game, int move)
{
	char	*s;
	void	*img;

	s = ft_itoa(move);
	if (!s)
		exit(2);
	img = mlx_file_to_image(game->mlx, "./textures/bot_wall.xpm");
	if (!img)
		exit(21);
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);
	mlx_destroy_image(game->mlx, img);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFF0000, s);
	mlx_string_put(game->mlx, game->win, 11, 20, 0xFF0000, s);
	mlx_string_put(game->mlx, game->win, 10, 21, 0xFF0000, s);
	free(s);
	ft_putnbr_fd(move, 1);
	ft_putchar('\n');
}

int	no_event(t_game *game)
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
