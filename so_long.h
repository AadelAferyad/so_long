/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:01:25 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/22 10:18:23 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "parser/parser.h"
# include "minilibx/mlx.h"

typedef struct mlx_struct
{
	void	*mlx;
	void	*win;
} t_mlx;

typedef struct game_map
{
	int	y;
	int	x;
	char	**map;
} t_game;
#endif
