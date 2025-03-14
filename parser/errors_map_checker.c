/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:14:28 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/22 10:14:32 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

void	print_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	cleanup_map_checker(char *str, char **buffer, t_map *map)
{
	int	i;

	i = 0;
	while (buffer && buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
	free(map);
	print_exit(str);
}
