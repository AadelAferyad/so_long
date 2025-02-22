/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:19:41 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/22 11:01:18 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

/*void	print_map(char **buffer)*/
/*{*/
/*	int	i;*/
/*	int	j;*/
/**/
/*	i = 0;*/
/**/
/*	while (buffer[i])*/
/*	{*/
/*		j = 0;*/
/*		while (buffer[i][j])*/
/*		{*/
/*			printf("%c", buffer[i][j]);*/
/*			j++;*/
/*		}*/
/*		printf("\n");*/
/*		i++;*/
/*	}*/
/*}*/

void	recursive_flood(char **map, int x, int y, t_map *map_info)
{
	if (x <= 0 || y <= 0 || x >= map_info->width || y >= map_info->height
		|| map[y][x] == WALL)
		return ;
	if (map_info->coins_exit <= 0 || map[y][x] == 'N')
		return ;
	if (map[y][x] == COIN)
		map_info->coins_exit--;
	else if (map[y][x] == EXIT)
		map_info->coins_exit--;
	/*if (map[y][x] != COIN && map[y][x] != EXIT && map[y][x] == '0')*/
	/*	map[y][x] = 'N';*/
	map[y][x] = 'N';
	recursive_flood(map, x + 1, y, map_info);
	recursive_flood(map, x - 1, y, map_info);
	recursive_flood(map, x, y + 1, map_info);
	recursive_flood(map, x, y - 1, map_info);
}

void	check_flood_fill_path(char **map, t_map *map_info)
{
	int	x;
	int	y;

	player_position(map, &x, &y);
	recursive_flood(map, x, y, map_info);
}

void	num_of_coins(char **map, t_map *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == COIN || map[i][j] == EXIT)
				map_info->coins_exit++;
			j++;
		}
		i++;
	}
}

void	check_for_valid_path(char **buffer, t_map *map)
{
	char	**grid;

	grid = allocate_map(buffer, map);
	num_of_coins(grid, map);
	check_flood_fill_path(grid, map);
	free_map(grid);
	if (map->coins_exit <= 0)
	{
		free(map);
		return ;
	}
	free(map);
	free_map(buffer);
	ft_putstr_fd(INVALID, 2);
	exit(1);
}

void	map_checker(char **buffer)
{
	t_map	*map_info;

	map_info = ft_calloc(sizeof(t_map), 1);
	if (!map_info)
	{
		free_map(buffer);
		ft_putstr_fd(MALLOC, 2);
		exit(1);
	}
	check_for_valid_path(buffer, map_info);
}
