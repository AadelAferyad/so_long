/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:22:46 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/22 10:37:01 by aaferyad         ###   ########.fr       */
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
# include "map_checker.h"

# define MAP_CHAR "01CEP"

struct	s_parser
{
	int	player;
	int	collectible;
	int	exit;
	int	x;
	int	y;
};

char	**parser(int ac, char **av);

void	print_error_free_exit(char *str, char **buffer, struct s_parser *map);
void	print_error_and_exit(char *str);
int		check_map_requirements(char c, struct s_parser **map);
int		check_is_map_rectangle(char **map, struct s_parser **map_info);
int		check_walls(char **map, struct s_parser **map_info);
int		check_upper_bottom_walls(char *buffer);
#endif
