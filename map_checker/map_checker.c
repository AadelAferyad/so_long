/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:19:41 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/21 21:58:46 by aaferyad         ###   ########.fr       */
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

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**allocate_map(char **buffer, t_map *map_info)
{
	char	**map;
	int	i;

	i = 0;
	map_info->height = map_height(buffer);
	map_info->width = (int) ft_strlen(buffer[0]);
	map = ft_calloc(sizeof(char *), map_info->height + 1);
	if (!map)
		cleanup_map_checker("Error\n[malloc failed]: Could't malloc\n", buffer, map_info);
	while (i < map_info->height)
	{
		map[i] = ft_strdup(buffer[i]);
		if (!map[i])
		{
			free_map(map);
			cleanup_map_checker("Error\n[malloc failed]: Could't malloc\n", buffer, map_info);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
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
		printf("\n");
		i++;
	}
}
void	recursive_flood(char **map, int x, int y, t_map *map_info)
{
	if (x <= 0 || y <= 0 || x >= map_info->width || y >= map_info->height || map[y][x] == WALL)
		return ;
	if (map_info->coins_exit <= 0 || map[y][x] == 'N')
		return ;
	if (map[y][x] == COIN)
	{
		map_info->coins_exit--;
		map[y][x] = 'X';
	}
	else if (map[y][x] == EXIT)
	{
		map_info->coins_exit--;
		map[y][x] = 'W';
	}
	if (map[y][x] != 'W' && map[y][x] != 'X' && map[y][x] == '0')
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
	print_map(map);
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
		return ;
	free(map);
	free_map(buffer);
	ft_putstr_fd("Error\n [Invalid Map] no valid path\n", 2);
	exit(1);
}

void	map_checker(char **buffer)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
	{
		free_map(buffer);
		ft_putstr_fd("Error\n[malloc failed]: Could't malloc\n", 2);
		exit(1);
	}
	check_for_valid_path(buffer, map);
}
