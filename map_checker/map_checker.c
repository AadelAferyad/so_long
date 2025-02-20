/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:19:41 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/21 00:14:11 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

int	map_height(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		i++;
	return (i);
}

void	player_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == PLAYER)
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
		
}

char	**allocate_map(char **buffer, t_map *map_info)
{
	char	**map;
	int	i;

	i = 0;
	map_info->height = map_height(buffer);
	map_info->width = (int) ft_strlen(buffer[0]);
	map = ft_calloc(sizeof(char *), map_info->height + 1);
	while (i < map_info->height)
	{
		map[i] = ft_strdup(buffer[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	recursive_flood(char **map, int x, int y, t_map *map_info)
{
	if ((x >= map_info->width || y >= map_info->height) || map[x][y] == WALL)
		return ;
	if (map[x][y] == COIN)
		map[x][y] = 'X';
	if (map[x][y] == EXIT)
		map[x][y] = 'W';
	recursive_flood(map, x + 1, y, map_info);
	recursive_flood(map, x, y + 1, map_info);
	recursive_flood(map, x - 1, y, map_info);
	recursive_flood(map, x, y - 1, map_info);
}

void	check_flood_fill_path(char **map, t_map *map_info)
{
	int	x;
	int	y;

     	player_position(map, &x, &y);
	recursive_flood(map, x, y, map_info);
}

void	print_map(char **buffer)
{
	int	i;
	int	j;

	i = 0;

	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j])
		{
			printf("%c", buffer[i][j]);
			j++;
		}
		i++;
	}
}

void	check_for_valid_path(char **buffer, t_map *map)
{
	char	**grid;

	grid = allocate_map(buffer, map);
	print_map(grid);
	check_flood_fill_path(grid, map);
	print_map(grid);

}

void	map_checker(char **buffer)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	map->player = ft_calloc(sizeof(int), 2);
	map->exit = ft_calloc(sizeof(int), 2);
	check_for_valid_path(buffer, map);
}
