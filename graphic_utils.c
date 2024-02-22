/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:24 by yrio              #+#    #+#             */
/*   Updated: 2024/01/25 10:29:34 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(int lines, int size_line, t_game *game, char **map)
{
	game->map.array = map;
	game->map.lines = lines;
	game->map.columns = size_line;
	game->map.nb_collectible = count_item('C', game);
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_free(map);
		exit(EXIT_FAILURE);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, size_line * 50, \
		lines * 50, "so long");
	if (game->win_ptr == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	find_position(&game->player.pos_y, &game->player.pos_x, \
	game->map.columns, game->map.array);
	game->player.collectibles_collected = 0;
	game->player.nb_movement = 0;
}

void	init_imgs(t_game *game)
{
	void	*mlx;
	int		img_width;
	int		img_height;

	img_width = 10;
	img_height = 10;
	mlx = game->mlx_ptr;
	game->character.xpm_ptr = mlx_xpm_file_to_image(mlx, \
		"./imgs/perso.xpm", &img_width, &img_height);
	game->sand.xpm_ptr = mlx_xpm_file_to_image(mlx, \
		"./imgs/sable.xpm", &img_width, &img_height);
	game->edge.xpm_ptr = mlx_xpm_file_to_image(mlx, \
		"./imgs/brique.xpm", &img_width, &img_height);
	game->exit.xpm_ptr = mlx_xpm_file_to_image(mlx, \
		"./imgs/porte.xpm", &img_width, &img_height);
	game->coin.xpm_ptr = mlx_xpm_file_to_image(mlx, \
		"./imgs/coin.xpm", &img_width, &img_height);
	if (!game->character.xpm_ptr || !game->sand.xpm_ptr \
		|| !game->edge.xpm_ptr || !game->exit.xpm_ptr \
		|| !game->coin.xpm_ptr)
		ft_close(game);
}

void	push_img(int tmp, int tmp2, t_game *game)
{
	if (game->map.array[tmp][tmp2] == '0')
		mlx_put_image_to_window(game->mlx_ptr, \
			game->win_ptr, game->sand.xpm_ptr, tmp2 * 50, tmp * 50);
	if (game->map.array[tmp][tmp2] == '1')
		mlx_put_image_to_window(game->mlx_ptr, \
			game->win_ptr, game->edge.xpm_ptr, tmp2 * 50, tmp * 50);
	if (game->map.array[tmp][tmp2] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->character.xpm_ptr, tmp2 * 50, tmp * 50);
	if (game->map.array[tmp][tmp2] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, \
			game->win_ptr, game->exit.xpm_ptr, tmp2 * 50, tmp * 50);
	if (game->map.array[tmp][tmp2] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, \
			game->win_ptr, game->coin.xpm_ptr, tmp2 * 50, tmp * 50);
}

int	display_map(t_game *game)
{
	int	tmp;
	int	tmp2;

	tmp = 0;
	while (tmp < game->map.lines)
	{
		tmp2 = 0;
		while (tmp2 < game->map.columns)
		{
			push_img(tmp, tmp2, game);
			tmp2++;
		}
		tmp++;
	}
	return (0);
}
