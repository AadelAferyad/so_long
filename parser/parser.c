/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:24:05 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/18 11:50:06 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_upper_bottom_walls(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] != '1')
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
		else if (map[i][0] != '1' || map[i][(*map_info)->x - 1] != '1')
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
		if (ft_strlen(map[i]) != (*map_info)->x)
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
	if (c == 'P')
	{
		if ((*map)->player == 1)
			return (1);
		(*map)->player = 1;
	}
	if (c == 'E')
	{
		if ((*map)->exit == 1)
			return (1);
		(*map)->exit = 1;
	}
	if (c == 'C')
		(*map)->collectible++;
	while (MAP_CHAR[i])
	{
		if (c == MAP_CHAR[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_map_content(char **map, struct s_parser **map_info)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_map_requirements(map[i][j], map_info))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	is_map_valid(char **map, struct s_parser **map_info)
{
	int	i;

	i = 0;
	if (check_is_map_rectangle(map, map_info) || check_walls(map, map_info))
	{
		/*free() Error handling [TODO] */
		exit(1);
	}
	if (check_map_content(map, map_info))
	{
		/*free() Error handling [TODO] */
		exit(1);
	}
}

char	*read_file(int fd)
{
	char	*sub_buffer;
	char	*buffer;

	buffer = NULL;
	sub_buffer = get_next_line(fd);
	while (sub_buffer)
	{
		buffer = ft_strjoin_gnl(buffer, sub_buffer);
		free(sub_buffer);
		if (!buffer)
			return (NULL);
		sub_buffer = get_next_line(fd);
	}
	return (buffer);
}

char	**parser(int fd)
{
	struct s_parser	*map_info;
	char	*buffer;
	char	**map;

	map_info = ft_calloc(sizeof(struct s_parser), 1);
	if (!map_info)
		exit(1); /*Error handling [TODO]*/
	buffer = read_file(fd);
	if (!buffer)
	{
		free(map_info);
		exit(1); /*Error handling [TODO]*/
	}
	map = ft_split(buffer, '\n');
	free(buffer);
	if (!map)
	{
		exit(1); /*Error handling [TODO]*/
		free(map_info);
	}
	is_map_valid(map, &map_info);
	return (map);
}
