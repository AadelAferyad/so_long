/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:35:44 by aaferyad          #+#    #+#             */
/*   Updated: 2025/03/07 03:14:36 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*mlx_file_to_image(void *mlx, char *str)
{
	int		w;
	int		h;

	return (mlx_xpm_file_to_image(mlx, str, &w, &h));
}

void	create_collectible(t_game *game, int x, int y)
{
	void	*img;

	img = mlx_file_to_image(game->mlx, "./textures/coin1.xpm");
	if (!img)
		cleanup(game, 1);
	create_empty(game, x, y);
	mlx_put_image_to_window(game->mlx, game->win, img, x * 40, y * 40);
	mlx_destroy_image(game->mlx, img);
}

void	create_exit(t_game *game, int x, int y)
{
	void	*img;

	img = mlx_file_to_image(game->mlx, "./textures/door.xpm");
	if (!img)
		cleanup(game, 1);
	mlx_put_image_to_window(game->mlx, game->win, img, x * 40, y * 40);
	mlx_destroy_image(game->mlx, img);
}

void	create_player(t_game *game, int x, int y, char *str)
{
	void	*img;

	img = mlx_file_to_image(game->mlx, str);
	if (!img)
		cleanup(game, 1);
	mlx_put_image_to_window(game->mlx, game->win, img, x * 40, y * 40);
	mlx_destroy_image(game->mlx, img);
}

void	create_empty(t_game *game, int x, int y)
{
	void	*img;

	img = mlx_file_to_image(game->mlx, "./textures/empty.xpm");
	if (!img)
		cleanup(game, 1);
	mlx_put_image_to_window(game->mlx, game->win, img, x * 40, y * 40);
	mlx_destroy_image(game->mlx, img);
}
