/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:30 by yrio              #+#    #+#             */
/*   Updated: 2024/01/25 15:43:03 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	if (game->character.xpm_ptr)
		mlx_destroy_image(mlx, game->character.xpm_ptr);
	if (game->sand.xpm_ptr)
		mlx_destroy_image(mlx, game->sand.xpm_ptr);
	if (game->edge.xpm_ptr)
		mlx_destroy_image(mlx, game->edge.xpm_ptr);
	if (game->coin.xpm_ptr)
		mlx_destroy_image(mlx, game->coin.xpm_ptr);
	if (game->exit.xpm_ptr)
		mlx_destroy_image(mlx, game->exit.xpm_ptr);
	mlx_destroy_window(mlx, game->win_ptr);
	mlx_destroy_display(mlx);
	free(mlx);
	ft_free(game->map.array);
	free(game);
	exit (EXIT_FAILURE);
	return (0);
}

int	modify_map(int keycode, t_game *game)
{
	if (keycode == 97 && \
	game->map.array[game->player.pos_y][game->player.pos_x - 1] == 'E')
		return (ft_printf("Not all items have been collected yet\n"));
	if (keycode == 97 && \
	game->map.array[game->player.pos_y][game->player.pos_x - 1] != '1')
		left_movement(game);
	if (keycode == 119 && \
	game->map.array[game->player.pos_y - 1][game->player.pos_x] == 'E')
		return (ft_printf("Not all items have been collected yet\n"));
	if (keycode == 119 && \
	game->map.array[game->player.pos_y - 1][game->player.pos_x] != '1')
		up_movement(game);
	if (keycode == 100 && \
	game->map.array[game->player.pos_y][game->player.pos_x + 1] == 'E')
		return (ft_printf("Not all items have been collected yet\n"));
	if (keycode == 100 && \
	game->map.array[game->player.pos_y][game->player.pos_x + 1] != '1')
		right_movement(game);
	if (keycode == 115 && \
	game->map.array[game->player.pos_y + 1][game->player.pos_x] == 'E')
		return (ft_printf("Not all items have been collected yet\n"));
	if (keycode == 115 && \
	game->map.array[game->player.pos_y + 1][game->player.pos_x] != '1')
		down_movement(game);
	return (0);
}

void	maj_collectible(int keycode, t_game *game)
{
	if (keycode == 97 && \
	game->map.array[game->player.pos_y][game->player.pos_x - 1] == 'C')
	{
		game->player.collectibles_collected++;
		game->map.array[game->player.pos_y][game->player.pos_x - 1] = '0';
	}
	if (keycode == 119 && \
	game->map.array[game->player.pos_y - 1][game->player.pos_x] == 'C')
	{
		game->player.collectibles_collected++;
		game->map.array[game->player.pos_y - 1][game->player.pos_x] = '0';
	}
	if (keycode == 100 && \
	game->map.array[game->player.pos_y][game->player.pos_x + 1] == 'C')
	{
		game->player.collectibles_collected++;
		game->map.array[game->player.pos_y][game->player.pos_x + 1] = '0';
	}
	if (keycode == 115 && \
	game->map.array[game->player.pos_y + 1][game->player.pos_x] == 'C')
	{
		game->player.collectibles_collected++;
		game->map.array[game->player.pos_y + 1][game->player.pos_x] = '0';
	}
}

void	check_endgame(int keycode, t_game *game)
{
	if ((keycode == 97 && \
	game->map.array[game->player.pos_y][game->player.pos_x - 1] == 'E' \
		&& game->map.nb_collectible == game->player.collectibles_collected) \
		|| (keycode == 119 && \
		game->map.array[game->player.pos_y - 1][game->player.pos_x] == 'E' \
		&& game->map.nb_collectible == game->player.collectibles_collected) \
		|| (keycode == 100 && \
		game->map.array[game->player.pos_y][game->player.pos_x + 1] == 'E' \
		&& game->map.nb_collectible == game->player.collectibles_collected) \
		|| (keycode == 115 && \
		game->map.array[game->player.pos_y + 1][game->player.pos_x] == 'E' \
		&& game->map.nb_collectible == game->player.collectibles_collected))
	{
		ft_printf("You win ! Congratulation !");
		ft_close(game);
	}
}

int	handle_key_input(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_close(game);
	maj_collectible(keycode, game);
	check_endgame(keycode, game);
	modify_map(keycode, game);
	return (0);
}
