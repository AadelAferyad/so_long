/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:19:41 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/19 22:43:25 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

void	check_num_of_coins(char **buffer, t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (buffer[i] && buffer[i + 1])
	{
		j = 0;
		while (buffer[i][j])
		{
			if (buffer[i][j] == 'C')
				map->coins++;
			else if (buffer[i][j] == 'P')
			{
				map->player[0] = i;
				map->player[1] = j;
			}
			else if (buffer[i][j] == 'E')
			{
				map->exit[0] = i;
				map->exit[1] = j;
			}
			j++;
		}
		i++;
	}
}

int	map_height(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		i++;
	return (i);
}

int	**allocate_map(char **buffer, t_map *map_info)
{
	int	**map;
	int	i;

	i = 0;
	map_info->height = map_height(buffer);
	map_info->width = (int) ft_strlen(buffer[0]);
	map = ft_calloc(sizeof(int *), map_info->height + 1);
	while (i < map_info->height)
	{
		map[i] = ft_calloc(sizeof(int), map_info->width + 1);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	create_map_new_value(int **map, char **buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j])
		{
			if (buffer[i][j] == '1')
				map[i][j] = -1;
			else if (buffer[i][j] == '0')
				map[i][j] = -2;
			else if (buffer[i][j] == 'C')
				map[i][j] = -3;
			else if (buffer[i][j] == 'E')
				map[i][j] = -4;
			else if (buffer[i][j] == 'P')
				map[i][j] = -5;
			j++;
		}
		i++;
	}
}

void	set_to_zero(int	**map, t_map *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (j < map_info->width)
			map[i][j++] = 0;
		i++;
	}
}

int	**create_map_flood_fill(int **map, char **buffer, t_map *map_info)
{
	set_to_zero(map, map_info);	
	create_map_new_value(map, buffer);
	return (map);
}

void	recursive_flood(int **map, int x, int y, t_map *map_info)
{
	if (x <= 0 || y <= 0 || x >= map_info->height || y >= map_info->width)
		return ;
	if (map[x][y] == -2)
	{
		if (x - )
		map[x][y] =  
	}
}

int	check_flood_fill_path(int **map, t_map *map_info, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	map[x][y] = 0;
	recursive_flood(map, x, y, map_info);
}

void	search_for_path(char **buffer, t_map *map)
{
	int	**grid;
	int	i;
	int	j;

	i = 0;
	grid = allocate_map(buffer, map);
	grid = create_map_flood_fill(grid, buffer, map);
	while (i < map->height)
	{
		while (j < map->width)
		{
			if (grid[i][j] == -3)
			{
				map->x = i;
				map->y = j;
				check_flood_fill_path(grid, map, i, j);
			}
			j++;
		}
		i++;
	}
}

void	map_checker(char **buffer)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	map->player = ft_calloc(sizeof(int), 2);
	map->exit = ft_calloc(sizeof(int), 2);
	check_num_of_coins(buffer, map);
	search_for_path(buffer, map);
}
