/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:21:48 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/22 10:22:52 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_upper_bottom_walls(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] != WALL)
			return (1);
		i++;
	}
	return (0);
}

int	check_walls(char **map, struct s_parser **map_info)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if ((!i || !map[i + 1]) && check_upper_bottom_walls(map[i]))
			return (1);
		else if (map[i][0] != WALL || map[i][(*map_info)->x - 1] != WALL)
			return (1);
		i++;
	}
	return (0);
}

int	check_is_map_rectangle(char **map, struct s_parser **map_info)
{
	int	i;

	i = 1;
	(*map_info)->x = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int) ft_strlen(map[i]) != (*map_info)->x)
			return (1);
		i++;
	}
	(*map_info)->y = i;
	if ((*map_info)->y >= (*map_info)->x)
		return (1);
	return (0);
}

int	check_map_requirements(char c, struct s_parser **map)
{
	int	i;

	i = 0;
	if (c == PLAYER)
	{
		if ((*map)->player == 1)
			return (1);
		(*map)->player = 1;
	}
	if (c == EXIT)
	{
		if ((*map)->exit == 1)
			return (1);
		(*map)->exit = 1;
	}
	if (c == COIN)
		(*map)->collectible++;
	while (MAP_CHAR[i])
	{
		if (c == MAP_CHAR[i])
			return (0);
		i++;
	}
	return (1);
}
