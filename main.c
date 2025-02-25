/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:16:21 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/24 13:35:12 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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

int	main(int ac, char **av)
{
	t_game	game;

	game.map = parser(ac, av);
	map_dimensions(&game);
	game_init(&game);
	free(game.map);
	return (0);
}
