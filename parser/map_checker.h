/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:19:28 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/22 10:41:08 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKER_H
# define MAP_CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define PLAYER 'P'
# define EXIT 'E'
# define COIN 'C'
# define WALL '1'
# define EMPTY '0'

# define INVALID "Error\n[Invalid MAP]: Map is invalid\n" 
# define MALLOC "Error\n[malloc failed]: Could't malloc\n"
# define READ "Error\n[Read file fialed]: Could't read data from file\n"
# define SPLIT "Error\n[Split failed]: Could't split due the malloc fail\n"

typedef struct map_info
{
	int	exit;
	int	coins;
	int	height;
	int	width;
}	t_map;

void	map_checker(char **buffer);
int		map_height(char **buffer);
void	print_exit(char *str);
void	cleanup_map_checker(char *str, char **buffer, t_map *map);
void	player_position(char **map, int *x, int *y);
void	free_map(char **map);
char	**allocate_map(char **buffer, t_map *map_info);
#endif
