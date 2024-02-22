/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:16:49 by yrio              #+#    #+#             */
/*   Updated: 2024/01/25 15:58:24 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *namefile)
{
	int	fd;

	fd = open(namefile, O_RDONLY);
	if (fd == -1)
	{
		perror("File do not open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char	**ft_free(char **char_tab)
{
	int	tmp;

	tmp = 0;
	while (char_tab[tmp])
		free(char_tab[tmp++]);
	free(char_tab);
	return (NULL);
}

void	show_map(int lines, int size_line, char **map)
{
	int	tmp;
	int	tmp2;

	tmp = 0;
	while (tmp < lines)
	{
		tmp2 = 0;
		while (tmp2 < size_line)
		{
			ft_printf("%c", map[tmp][tmp2]);
			tmp2++;
		}
		ft_printf("\n");
		tmp++;
	}
}

char	**copy_map(int lines, int size_line, char **map)
{
	char	**map_cpy;
	char	*line;
	int		tmp[2];

	map_cpy = init_mapcpy(&tmp[0], lines);
	if (!map_cpy)
		return (NULL);
	while (tmp[0] < lines)
	{
		tmp[1] = 0;
		line = malloc(size_line * sizeof(char));
		if (!line)
		{
			ft_free(map_cpy);
			return (NULL);
		}
		while (tmp[1] < size_line)
		{
			line[tmp[1]] = map[tmp[0]][tmp[1]];
			map_cpy[tmp[0]] = line;
			tmp[1]++;
		}
		tmp[0]++;
	}
	return (map_cpy);
}

int	find_item(int lines, int size_line, char c, char **map)
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
