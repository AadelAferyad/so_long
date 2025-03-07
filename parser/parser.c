/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:24:05 by aaferyad          #+#    #+#             */
/*   Updated: 2025/03/07 03:08:06 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_map_content(char **map, struct s_parser **map_info, int enemy)
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
			if (enemy && map[i][j] == 'N')
				enemy++;
			else if (check_map_requirements(map[i][j], map_info))
				return (1);
			if (enemy > 2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	is_map_valid(char **map, struct s_parser **info, int enemy)
{
	if (check_is_map_rectangle(map, info) || check_walls(map, info))
		print_error_free_exit(INVALID, map, *info);
	if (check_map_content(map, info, enemy))
		print_error_free_exit(INVALID, map, *info);
	if (!(*info)->player || !(*info)->exit || !(*info)->collectible)
		print_error_free_exit(INVALID, map, *info);
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

void	check_file_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			break ;
		i++;
	}
	if (i < 2)
		print_error_and_exit("Error\n[Wrong file]: worng file type\n");
	if (!str[i] || ft_strncmp(&str[i], ".ber", 10))
		print_error_and_exit("Error\n[Wrong file]: worng file type\n");
}

char	**parser(int ac, char **av, int enemy)
{
	struct s_parser	*map_info;
	char			*buffer;
	char			**map;
	int				fd;

	if (ac != 2)
		exit (0);
	check_file_name(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		print_error_and_exit("Error\n[Open failed]: Can't open file\n");
	map_info = ft_calloc(sizeof(struct s_parser), 1);
	if (!map_info)
		print_error_and_exit(MALLOC);
	buffer = read_file(fd);
	if (!buffer)
		print_error_free_exit(READ, NULL, map_info);
	map = ft_split(buffer, '\n');
	free(buffer);
	if (!map)
		print_error_free_exit(SPLIT, NULL, map_info);
	is_map_valid(map, &map_info, enemy);
	free(map_info);
	map_checker(map);
	return (map);
}
