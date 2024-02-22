/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:11:02 by yrio              #+#    #+#             */
/*   Updated: 2024/02/20 15:28:38 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map(int fd, int lines, int size_line, char **map)
{
	char	*line;
	int		tmp;

	map = malloc((lines + 1) * sizeof(char *));
	if (!map)
	{
		ft_putstr_fd("Error\nAllocation memory map\n", 2);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd, map);
	tmp = 0;
	while (tmp < lines)
	{
		map[tmp] = line;
		if (map[tmp])
			map[tmp][size_line] = '\0';
		tmp++;
		line = get_next_line(fd, map);
	}
	map[lines] = 0;
	return (map);
}

void	check_map(int lines, int size_line, t_game *game)
{
	check_error_edges(lines, size_line, game);
	check_error_items(lines, size_line, game);
	check_error_duplicate(lines, size_line, game);
	check_error_way(lines, size_line, game);
}

void	play(int fd, int lines, int size_line)
{
	t_game	*game;	
	char	**map;

	map = NULL;
	map = create_map(fd, lines, size_line, map);
	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_free(map);
		ft_putstr_fd("Error\nAllocation memory map\n", 2);
		exit(EXIT_FAILURE);
	}
	game->map.array = map;
	check_map(lines, size_line, game);
	init_game(lines, size_line, game, map);
	init_imgs(game);
	display_map(game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, ft_close, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, handle_key_input, game);
	mlx_hook(game->win_ptr, Expose, ExposureMask, display_map, game);
	mlx_loop(game->mlx_ptr);
	ft_free(map);
}

int	main(int argc, char **argv)
{
	int			fd;
	int			lines;
	int			size_line;

	if (argc == 2)
	{
		lines = 0;
		size_line = 0;
		fd = open_file(argv[1]);
		if (!count_lines(fd, &lines, &size_line) || size_line == 0)
		{
			ft_putstr_fd("Error\nMap not valid\n", 2);
			close(fd);
			exit(EXIT_FAILURE);
		}
		close(fd);
		fd = open_file(argv[1]);
		play(fd, lines, size_line);
		close(fd);
	}
	return (0);
}
