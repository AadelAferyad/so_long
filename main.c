/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:16:21 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/22 10:16:56 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	void	*mlx_con;
	void	*win;

	map = parser(ac, av);
	mlx_con = mlx_init();
	win = mlx_new_window(mlx_con, 1200, 900, "so_long");
	mlx_destroy_window(mlx_con, win);
	free(map);
	return (0);
}
