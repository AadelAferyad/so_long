/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:19:28 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/19 19:26:46 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHACHER_H
# define MAP_CHACHER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct map_info
{
	int	coins;
	int	*player;
	int	*exit;
	int	height;
	int	width;
	int	x;
	int	y;
} t_map;

void	map_checker(char **map);

#endif
