/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:59:30 by yrio              #+#    #+#             */
/*   Updated: 2024/01/25 17:07:26 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_item(char c, t_game *game)
{
	int	tmp;
	int	tmp2;
	int	count;

	tmp = 0;
	count = 0;
	while (tmp < game->map.lines)
	{
		tmp2 = 0;
		while (tmp2 < game->map.columns)
		{
			if (game->map.array[tmp][tmp2] == c)
				count++;
			tmp2++;
		}
		tmp++;
	}
	return (count);
}

void	ft_charzero(char **map, int size)
{
	int	tmp;

	tmp = 0;
	while (tmp < size)
	{
		map[tmp] = 0;
		tmp++;
	}
}

char	**init_mapcpy(int *tmp, int lines)
{
	char	**map_cpy;

	map_cpy = NULL;
	map_cpy = malloc((lines + 1) * sizeof(char *));
	if (!map_cpy)
		return (NULL);
	ft_charzero(map_cpy, lines + 1);
	tmp[0] = 0;
	return (map_cpy);
}
