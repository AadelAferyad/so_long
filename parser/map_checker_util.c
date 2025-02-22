/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:24:47 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/22 10:39:07 by aaferyad         ###   ########.fr       */
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
	int		i;

	i = 0;
	map_info->height = map_height(buffer);
	map_info->width = (int) ft_strlen(buffer[0]);
	map = ft_calloc(sizeof(char *), map_info->height + 1);
	if (!map)
		cleanup_map_checker(MALLOC, buffer, map_info);
	while (i < map_info->height)
	{
		map[i] = ft_strdup(buffer[i]);
		if (!map[i])
		{
			free_map(map);
			cleanup_map_checker(MALLOC, buffer, map_info);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}
