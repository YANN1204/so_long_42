/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:55:29 by yrio              #+#    #+#             */
/*   Updated: 2024/01/25 11:36:19 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error_edges(int lines, int size_line, t_game *game)
{
	if (!check_edges(lines, size_line, game->map.array))
	{
		ft_putstr_fd("Error\nMap is not enclose by edges", 2);
		ft_free(game->map.array);
		free(game);
		exit(EXIT_FAILURE);
	}
}

void	check_error_items(int lines, int size_line, t_game *game)
{
	if (!char_map(lines, size_line, game->map.array, 'P') || \
		!char_map(lines, size_line, game->map.array, 'E') || \
		!char_map(lines, size_line, game->map.array, 'C'))
	{
		ft_putstr_fd("Error\nPlayer position, exit place \
or collectibles not declared on the map", 2);
		ft_free(game->map.array);
		free(game);
		exit(EXIT_FAILURE);
	}
}

void	check_error_duplicate(int lines, int size_line, t_game *game)
{
	if (check_duplicate(lines, size_line, game->map.array, 'P') || \
		check_duplicate(lines, size_line, game->map.array, 'E'))
	{
		ft_putstr_fd("Error\nPlayer position or exit place are duplicate", 2);
		ft_free(game->map.array);
		free(game);
		exit(EXIT_FAILURE);
	}
}

void	check_error_way(int lines, int size_line, t_game *game)
{
	int	result;

	result = check_way(lines, size_line, game->map.array);
	if (!result)
	{
		ft_putstr_fd("Error\nA collectible or exit is not \
accessible from the player's initial position", 2);
		ft_free(game->map.array);
		free(game);
		exit(EXIT_FAILURE);
	}
	if (result == 2)
	{
		ft_putstr_fd("Error\nAllocation memory map\n", 2);
		exit(EXIT_FAILURE);
	}
}
