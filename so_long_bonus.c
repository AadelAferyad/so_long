/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:34:23 by aaferyad          #+#    #+#             */
/*   Updated: 2025/03/02 23:36:34 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	n_coins_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->map[i])
	{
		j = 1;
		while (game->map[i][j])
		{
			if (game->map[i][j] == PLAYER)
			{
				game->x = j;
				game->y = i;
			}
			if (game->map[i][j] == COIN)
				game->coins++;
			j++;
		}
		i++;
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

void	map_dimensions(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->width = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		i++;
	}
	game->height = i;
}

static void	exit_dimensions(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == EXIT)
			{
				game->exit_x = j;
				game->exit_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	game.map = parser(ac, av, 1);
	map_dimensions(&game);
	exit_dimensions(&game);
	game_init(&game);
	free(game.map);
	return (0);
}
