/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:16:21 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/22 10:16:56 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_background(t_mlx *mlx_ptr, char **map)
{
	int	img_width;
	int	img_height;
	int	i;
	int	j;
	void	*image;
	int	p;

	i = 0;
	p = 32;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == WALL)
			{
				image = mlx_xpm_file_to_image(mlx_ptr->mlx, "./sprites/2.xpm", &img_width, &img_height);
				if (!image)
					return ;
				mlx_put_image_to_window(mlx_ptr->mlx, mlx_ptr->win, image, j * p, i * p);
				mlx_destroy_image(mlx_ptr->mlx, image);
			}
			/*else if (map[i][j] == EMPTY)*/
			/*{*/
			/*	image = mlx_xpm_file_to_image(mlx_ptr->mlx, "./sprites/1.xpm", &img_width, &img_height);*/
			/*	if (!image)*/
			/*		return ;*/
			/*	mlx_put_image_to_window(mlx_ptr->mlx, mlx_ptr->win, image, j * 32, i * 32);*/
			/*	mlx_destroy_image(mlx_ptr->mlx, image);*/
			/*}*/
			else if (map[i][j] == COIN)
			{
				image = mlx_xpm_file_to_image(mlx_ptr->mlx, "./sprites/5.xpm", &img_width, &img_height);
				if (!image)
					return ;
				mlx_put_image_to_window(mlx_ptr->mlx, mlx_ptr->win, image, j * p, i * p);
				mlx_destroy_image(mlx_ptr->mlx, image);
			}
			else if (map[i][j] == EXIT)
			{
				image = mlx_xpm_file_to_image(mlx_ptr->mlx, "./sprites/6.xpm", &img_width, &img_height);
				if (!image)
					return ;
				mlx_put_image_to_window(mlx_ptr->mlx, mlx_ptr->win, image, j * p, i * p);
				mlx_destroy_image(mlx_ptr->mlx, image);
			}
			j++;
		}
		i++;
	}

}

void	map_dimensions(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->x = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		i++;
	}
	game->y = i;
}

int	main(int ac, char **av)
{
	t_game	game;
	t_mlx	mlx_ptr;

	game.map = parser(ac, av);
	map_dimensions(&game);
	mlx_ptr.mlx = mlx_init();
	mlx_ptr.win = mlx_new_window(mlx_ptr.mlx, game.x * 16, game.y * 16, "so_long");
	create_background(&mlx_ptr, game.map);
	mlx_loop(mlx_ptr.mlx);
	free(game.map);
	return (0);
}
