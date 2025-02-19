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
		else if (map[i][0] != '1' || map[i][(*map_info)->x - 2] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_is_map_rectangel(char **map, struct s_parser **map_info)
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

int	check_map_content(char **map, struct s_parser **map_info)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[i][j])
	{
		if (!map[i][j + 1])
		{
			i++;
			j = 0;
		}
		if (!ft_strchr("01CEP", ))
		if (!(i + 1 < (*map_info)->y))
			break ;
		j++;
	}
}

void	is_map_valid(char **map, struct s_parser **map_info)
{
	int	i;

	i = 0;
	if (check_is_map_rectangel(map, map_info) || check_walls(map, map_info))
	{
		/*free() Error handling [TODO] */
		exit(1);
	}
	if (check_map_content(map, map_info))
	{
		/*free() Error handling [TODO] */
		exit(1);
	}

	while (map[i])
	{
		if (ft_strlen(map[i]) != (*map_info)->x)
		{
			/*free() Error handling [TODO] */
			exit(1);
		}
	}
}

char	*read_file(int fd)
{
	char	*sub_buffer;
	char	*buffer;

	sub_buffer = get_next_line(fd);
	while (sub_buffer)
	{
		buffer = ft_strjoin_gnl(buffer, sub_buffer);
		free(sub_buffer);
		if (!buffer)
			exit(1); /*Error handling [TODO]*/
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
	map = ft_split(buffer, '\n');
	free(buffer);
	if (!map)
	{
		exit(1); /*Error handling [TODO]*/
		free(map_info);
	}
	is_map_valid(map, &map_info);
	return (NULL);
}
