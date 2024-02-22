/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:48:41 by yrio              #+#    #+#             */
/*   Updated: 2024/01/17 09:29:01 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_position(int *pos_y, int *pos_x, int size_line, char **map)
{
	int	tmp;
	int	tmp2;

	tmp = 0;
	while (map[tmp])
	{
		tmp2 = 0;
		while (tmp2 < size_line)
		{
			if (map[tmp][tmp2] == 'P')
			{
				*pos_y = tmp;
				*pos_x = tmp2;
				return ;
			}
			tmp2++;
		}
		tmp++;
	}
}

int	flood_fill_collectible(int pos_y, int pos_x, char **map)
{
	map[pos_y][pos_x] = '1';
	if (map[pos_y + 1][pos_x] != '1' && map[pos_y + 1][pos_x] != 'E')
		flood_fill_collectible(pos_y + 1, pos_x, map);
	if (map[pos_y][pos_x - 1] != '1' && map[pos_y][pos_x - 1] != 'E')
		flood_fill_collectible(pos_y, pos_x - 1, map);
	if (map[pos_y][pos_x + 1] != '1' && map[pos_y][pos_x + 1] != 'E')
		flood_fill_collectible(pos_y, pos_x + 1, map);
	if (map[pos_y - 1][pos_x] != '1' && map[pos_y - 1][pos_x] != 'E')
		flood_fill_collectible(pos_y - 1, pos_x, map);
	return (1);
}

int	flood_fill_exit(int pos_y, int pos_x, char **map)
{
	map[pos_y][pos_x] = '1';
	if (map[pos_y + 1][pos_x] != '1')
		flood_fill_exit(pos_y + 1, pos_x, map);
	if (map[pos_y][pos_x - 1] != '1')
		flood_fill_exit(pos_y, pos_x - 1, map);
	if (map[pos_y][pos_x + 1] != '1')
		flood_fill_exit(pos_y, pos_x + 1, map);
	if (map[pos_y - 1][pos_x] != '1')
		flood_fill_exit(pos_y - 1, pos_x, map);
	return (1);
}
