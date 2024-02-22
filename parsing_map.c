/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:13:41 by yrio              #+#    #+#             */
/*   Updated: 2024/01/26 14:41:13 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(int fd, int *lines, int *size_line)
{
	char	character;
	int		tmp;

	tmp = 0;
	while (read(fd, &character, 1) > 0)
	{
		if (character != '0' && character != '1' && character != 'P' \
		&& character != 'E' && character != 'C' && character != '\n')
			return (0);
		if (character == '\n')
		{
			if (tmp != 0 && tmp != *size_line)
				return (0);
			tmp = *size_line;
			*size_line = 0;
			*lines = *lines + 1;
		}
		else
			*size_line = *size_line + 1;
	}
	if (tmp != *size_line)
		return (0);
	if (lines != 0)
		*lines = *lines + 1;
	return (1);
}

int	check_edges(int lines, int size_line, char **map)
{
	int	tmp;

	tmp = 0;
	while (tmp < size_line)
	{
		if (map[0][tmp] != '1' || map[lines - 1][tmp] != '1')
			return (0);
		tmp++;
	}
	tmp = 0;
	while (tmp < lines)
	{
		if (map[tmp][0] != '1' || map[tmp][size_line - 1] != '1')
			return (0);
		tmp++;
	}
	return (1);
}

int	char_map(int lines, int size_line, char **map, char c)
{
	int	tmp;
	int	tmp2;

	tmp = 0;
	while (tmp < lines)
	{
		tmp2 = 0;
		while (tmp2 < size_line)
		{
			if (map[tmp][tmp2] == c)
				return (1);
			tmp2++;
		}
		tmp++;
	}
	return (0);
}

int	check_duplicate(int lines, int size_line, char **map, char c)
{
	int	tmp;
	int	tmp2;
	int	first;

	tmp = 0;
	first = 0;
	while (tmp < lines)
	{
		tmp2 = 0;
		while (tmp2 < size_line)
		{
			if (first == 1 && map[tmp][tmp2] == c)
				return (1);
			if (map[tmp][tmp2] == c)
				first = 1;
			tmp2++;
		}
		tmp++;
	}
	return (0);
}

int	check_way(int lines, int size_line, char **map)
{
	char	**map_cpy;
	char	**map_cpy2;
	int		pos_y;
	int		pos_x;

	pos_y = 0;
	pos_x = 0;
	map_cpy = copy_map(lines, size_line, map);
	map_cpy2 = copy_map(lines, size_line, map);
	if (!map_cpy || !map_cpy2)
		return (2);
	find_position(&pos_y, &pos_x, size_line, map_cpy);
	flood_fill_collectible(pos_y, pos_x, map_cpy);
	flood_fill_exit(pos_y, pos_x, map_cpy2);
	if (find_item(lines, size_line, 'C', map_cpy) \
		|| find_item(lines, size_line, 'E', map_cpy2))
	{
		ft_free(map_cpy);
		ft_free(map_cpy2);
		return (0);
	}
	ft_free(map_cpy);
	ft_free(map_cpy2);
	return (1);
}
