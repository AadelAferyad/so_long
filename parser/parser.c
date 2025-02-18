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

void	is_map_valid(char *sub_buffer, char **buffer, struct s_parser **map)
{
	static int	y;
	static int	x;
	int	i;

	i = 0;
	if (!y)
	{
		check_valid_wall(sub_buffer);
		y++;
		x = ft_strlen(sub_buffer);
	}
	while (sub_buffer[i])
	{
	}
}

char	**parser(int fd)
{
	struct s_parser	*map;
	char	*sub_buffer;
	char	*buffer;

	map = ft_calloc(sizeof(struct s_parser), 1);
	if (!map)
		exit(1); /*Print error then exit [TODO]*/
	sub_buffer = get_next_line(fd);
	while (sub_buffer)
	{
		is_map_valid(sub_buffer, &buffer, &map);
		buffer = ft_strjoin_gnl(buffer, sub_buffer);
		free(sub_buffer);
		sub_buffer = get_next_line(fd);
	}

	return (NULL);
}
