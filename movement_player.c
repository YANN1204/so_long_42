/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:25:24 by yrio              #+#    #+#             */
/*   Updated: 2024/01/17 10:15:12 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_movement(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->sand.xpm_ptr, game->player.pos_x * 50, game->player.pos_y * 50);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->character.xpm_ptr, (game->player.pos_x * 50) + 50, \
		game->player.pos_y * 50);
	game->player.pos_x++;
	game->player.nb_movement++;
	ft_printf("Number of movements : %d\n", game->player.nb_movement);
}

void	left_movement(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->sand.xpm_ptr, game->player.pos_x * 50, game->player.pos_y * 50);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->character.xpm_ptr, (game->player.pos_x * 50) - 50, \
		game->player.pos_y * 50);
	game->player.pos_x--;
	game->player.nb_movement++;
	ft_printf("Number of movements : %d\n", game->player.nb_movement);
}

void	up_movement(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->sand.xpm_ptr, game->player.pos_x * 50, game->player.pos_y * 50);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->character.xpm_ptr, (game->player.pos_x * 50), \
		(game->player.pos_y * 50) - 50);
	game->player.pos_y--;
	game->player.nb_movement++;
	ft_printf("Number of movements : %d\n", game->player.nb_movement);
}

void	down_movement(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->sand.xpm_ptr, game->player.pos_x * 50, game->player.pos_y * 50);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->character.xpm_ptr, (game->player.pos_x * 50), \
		(game->player.pos_y * 50) + 50);
	game->player.pos_y++;
	game->player.nb_movement++;
	ft_printf("Number of movements : %d\n", game->player.nb_movement);
}
