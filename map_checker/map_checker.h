/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:19:28 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/21 21:56:45 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHACHER_H
# define MAP_CHACHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define PLAYER 'P'
# define EXIT 'E'
# define COIN 'C'
# define WALL '1'
# define EMPTY '0'

typedef struct map_info
{
	int	coins_exit;
	int	height;
	int	width;
} t_map;

void	map_checker(char **buffer);
void	print_exit(char *str);
void	cleanup_map_checker(char *str, char **buffer, t_map *map);
#endif
