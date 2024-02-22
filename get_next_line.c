/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:28:51 by yrio              #+#    #+#             */
/*   Updated: 2024/01/25 17:00:22 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*readfile(int fd, char *stat)
{
	char	*buffer;
	int		isread;

	isread = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (ft_strchr(buffer, '\n') == NULL && isread != 0)
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		buffer[isread] = '\0';
		if (exception_readfile(isread, &stat, buffer))
			return (stat);
		else if (isread == -1)
			return (NULL);
		stat = ft_strjoin(stat, buffer);
		if (!stat)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (stat);
}

char	*putline(char *stat, char *line)
{
	char	*error_msg;
	int		lenchar;

	if (stat[0] == '\0')
		return (NULL);
	lenchar = 0;
	while (stat[lenchar] != '\n' && stat[lenchar] != '\0')
		lenchar++;
	if (stat[lenchar] == '\n')
		lenchar++;
	line = malloc((lenchar + 1) * sizeof(char));
	if (!line)
	{
		error_msg = malloc(6 * sizeof(char));
		error_msg = "Error";
		return (error_msg);
	}
	lenchar = 0;
	fill_line(lenchar, stat, line);
	return (line);
}

char	*putstat(char *stat)
{
	int		lenchar;
	int		i;
	char	*new_stat;
	char	*error_msg;

	if (stat == NULL)
		return (NULL);
	if (stat[0] == '\0' || ft_strchr(stat, '\n') == NULL)
	{
		free(stat);
		return (NULL);
	}
	lenchar = 0;
	while (stat[lenchar] != '\n' && stat[lenchar] != '\0')
		lenchar++;
	new_stat = malloc((ft_strlen(stat) - lenchar + 1) * sizeof(char));
	if (!new_stat)
	{
		error_msg = malloc(6 * sizeof(char));
		error_msg = "Error";
		return (error_msg);
	}
	i = 0;
	fill_new_stat(i, lenchar, stat, new_stat);
	return (new_stat);
}

void	error_alloc(char *stat, char *line, char **map)
{
	free(stat);
	free(line);
	ft_free(map);
	ft_putstr_fd("Error\nAllocation memory map\n", 2);
	exit(EXIT_FAILURE);
}

char	*get_next_line(int fd, char **map)
{
	static char	*stat;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	stat = readfile(fd, stat);
	if (!stat)
	{
		ft_free(map);
		ft_putstr_fd("Error\nAllocation memory map\n", 2);
		exit(EXIT_FAILURE);
	}
	line = putline(stat, line);
	if (line)
		if (!ft_strncmp(line, "Error", 5))
			error_alloc(stat, line, map);
	stat = putstat(stat);
	if (stat)
		if (!ft_strncmp(stat, "Error", 5))
			error_alloc(stat, line, map);
	return (line);
}

/*
int	main(void)
{
	char		*namefile;
	char		*line;
	char		*line2;
	//char		*line3;
	int			fd;

	namefile = "numbers.dict";
	fd = open(namefile, O_RDONLY);
	if (fd == -1)
	{
		perror("Le fichier n'a pas pu etre ouvert");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	printf("%s", line);
	line2 = get_next_line(fd);
	printf("%s", line2);
	//line3 = get_next_line(fd);
	//printf("%s", line3);
	if (line != NULL)
	{
		free(line);
		//printf("bien malloc line\n");
	}
	if (line2 != NULL)
	{
		//free(line2);
		//printf("bien malloc line2\n");
	}
	if (line3 != NULL)
	{
		free(line3);
		printf("bien malloc line3\n");
	}
	return (0);
}
*/
