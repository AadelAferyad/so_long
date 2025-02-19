/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:29:49 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/19 15:37:03 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_error_and_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	print_error_free_exit(char *str, char **buffer, struct s_parser *map)
{
	int	i;

	i = 0;
	while (buffer && buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	if (buffer)
		free(buffer);
	free(map);
	print_error_and_exit(str);
}
