/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 04:39:26 by aaferyad          #+#    #+#             */
/*   Updated: 2025/03/03 05:03:27 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create_animation(t_game *game, int x, int y)
{
	if (game->x > x)
		player_animation_left(game, x, y);
	if (game->x < x)
		player_animation_right(game, x, y);
	if (game->y < y)
		player_animation_front(game, x, y);
	if (game->y > y)
		player_animation_back(game, x, y);
}

void	player_animation_front(t_game *game, int x, int y)
{
	static int	i;

	if (i % 8 == 0)
		create_player(game, x , y, "./sprites/front_walk8.xpm");
	else if (i % 8 == 1)
		create_player(game, x , y, "./sprites/front_walk1.xpm");
	else if (i % 8 == 2)
		create_player(game, x , y, "./sprites/front_walk2.xpm");
	else if (i % 8 == 3)
		create_player(game, x , y, "./sprites/front_walk3.xpm");
	else if (i % 8 == 4)
		create_player(game, x , y, "./sprites/front_walk4.xpm");
	else if (i % 8 == 5)
		create_player(game, x , y, "./sprites/front_walk5.xpm");
	else if (i % 8 == 6)
		create_player(game, x , y, "./sprites/front_walk6.xpm");
	else if (i % 8 == 7)
		create_player(game, x , y, "./sprites/front_walk7.xpm");
	i++;
}

void	player_animation_back(t_game *game, int x, int y)
{
	static int	i;

	if (i % 8 == 0)
		create_player(game, x , y, "./sprites/back_walk8.xpm");
	else if (i % 8 == 1)
		create_player(game, x , y, "./sprites/back_walk1.xpm");
	else if (i % 8 == 2)
		create_player(game, x , y, "./sprites/back_walk2.xpm");
	else if (i % 8 == 3)
		create_player(game, x , y, "./sprites/back_walk3.xpm");
	else if (i % 8 == 4)
		create_player(game, x , y, "./sprites/back_walk4.xpm");
	else if (i % 8 == 5)
		create_player(game, x , y, "./sprites/back_walk5.xpm");
	else if (i % 8 == 6)
		create_player(game, x , y, "./sprites/back_walk6.xpm");
	else if (i % 8 == 7)
		create_player(game, x , y, "./sprites/back_walk7.xpm");
	i++;
}

void	player_animation_right(t_game *game, int x, int y)
{
	static int	i;

	if (i % 8 == 0)
		create_player(game, x , y, "./sprites/right_walk8.xpm");
	else if (i % 8 == 1)
		create_player(game, x , y, "./sprites/right_walk1.xpm");
	else if (i % 8 == 2)
		create_player(game, x , y, "./sprites/right_walk2.xpm");
	else if (i % 8 == 3)
		create_player(game, x , y, "./sprites/right_walk3.xpm");
	else if (i % 8 == 4)
		create_player(game, x , y, "./sprites/right_walk4.xpm");
	else if (i % 8 == 5)
		create_player(game, x , y, "./sprites/right_walk5.xpm");
	else if (i % 8 == 6)
		create_player(game, x , y, "./sprites/right_walk6.xpm");
	else if (i % 8 == 7)
		create_player(game, x , y, "./sprites/right_walk7.xpm");
	i++;
}
void	player_animation_left(t_game *game, int x, int y)
{
	static int	i;

	if (i % 8 == 0)
		create_player(game, x , y, "./sprites/left_walk8.xpm");
	else if (i % 8 == 1)
		create_player(game, x , y, "./sprites/left_walk1.xpm");
	else if (i % 8 == 2)
		create_player(game, x , y, "./sprites/left_walk2.xpm");
	else if (i % 8 == 3)
		create_player(game, x , y, "./sprites/left_walk3.xpm");
	else if (i % 8 == 4)
		create_player(game, x , y, "./sprites/left_walk4.xpm");
	else if (i % 8 == 5)
		create_player(game, x , y, "./sprites/left_walk5.xpm");
	else if (i % 8 == 6)
		create_player(game, x , y, "./sprites/left_walk6.xpm");
	else if (i % 8 == 7)
		create_player(game, x , y, "./sprites/left_walk7.xpm");
	i++;
}
