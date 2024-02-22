/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:19:58 by yrio              #+#    #+#             */
/*   Updated: 2024/01/25 16:58:52 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MLX_ERROR 1

# include <string.h>
# include <stdio.h>
# include <bsd/string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

typedef struct s_image {
	void	*xpm_ptr;
	int		x;
	int		y;
}				t_image;

typedef struct s_map {
	char	**array;
	int		lines;
	int		columns;
	int		nb_collectible;
}				t_map;

typedef struct s_player{
	int	pos_x;
	int	pos_y;
	int	collectibles_collected;
	int	nb_movement;
}				t_player;

typedef struct s_game {
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	player;
	t_map		map;
	t_image		character;
	t_image		exit;
	t_image		coin;
	t_image		sand;
	t_image		edge;
}				t_game;

size_t	ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*get_next_line(int fd, char **map);
int		exception_readfile(int isread, char **stat, char *buffer);
void	fill_line(int lenchar, char *stat, char *line);
void	fill_new_stat(int i, int lenchar, char *stat, char *new_stat);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ptr_null(char *s1);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putunsignednbr(unsigned int n);
int		ft_print_ptr(void *ptr, char c);
int		ft_print_hexa(void *ptr, char c);
void	ft_putstr_fd(char const *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);

int		open_file(char *namefile);
void	show_map(int lines, int size_line, char **map);
char	**copy_map(int lines, int size_line, char **map);
char	**ft_free(char **char_tab);
int		find_item(int lines, int size_line, char c, char **map);
int		count_item(char c, t_game *game);
void	ft_charzero(char **map, int size);
char	**init_mapcpy(int *tmp, int lines);

int		count_lines(int fd, int *lines, int *size_line);
int		check_edges(int lines, int size_line, char **map);
int		char_map(int lines, int size_line, char **map, char c);
int		check_duplicate(int lines, int size_line, char **map, char c);
int		check_way(int lines, int size_line, char **map);

void	check_error_edges(int lines, int size_line, t_game *game);
void	check_error_items(int lines, int size_line, t_game *game);
void	check_error_duplicate(int lines, int size_line, t_game *game);
void	check_error_way(int lines, int size_line, t_game *game);

void	find_position(int *pos_y, int *pos_x, int size_line, char **map);
int		flood_fill_collectible(int pos_x, int pos_y, char **map);
int		flood_fill_exit(int pos_x, int pos_y, char **map);

int		ft_close(t_game *game);
int		handle_key_input(int keycode, t_game *game);

void	init_game(int lines, int size_line, t_game *game, char **map);
void	init_imgs(t_game *game);
int		display_map(t_game *game);

void	right_movement(t_game *game);
void	left_movement(t_game *game);
void	up_movement(t_game *game);
void	down_movement(t_game *game);

#endif
