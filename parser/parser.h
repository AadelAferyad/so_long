/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:22:46 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/19 15:37:11 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# define MAP_CHAR "01CEP"

struct	s_parser
{
	int	player;
	int	collectible;
	int	exit;
	int	x;
	int	y;
};

char	**parser(int fd);

void	print_error_free_exit(char *str, char **buffer, struct s_parser *map);
void	print_error_and_exit(char *str);
#endif
