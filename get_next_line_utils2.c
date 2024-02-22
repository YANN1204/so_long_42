/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:09:33 by yrio              #+#    #+#             */
/*   Updated: 2024/01/25 17:01:32 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exception_readfile(int isread, char **stat, char *buffer)
{
	if (isread == 0 && *stat)
	{
		free(buffer);
		return (1);
	}
	else if (isread == 0 && !(*stat))
	{
		*stat = ptr_null(*stat);
		free(buffer);
		return (1);
	}
	return (0);
}

void	fill_line(int lenchar, char *stat, char *line)
{
	while (stat[lenchar] != '\n' && stat[lenchar] != '\0')
	{
		line[lenchar] = stat[lenchar];
		lenchar++;
	}
	if (stat[lenchar] == '\n')
	{
		line[lenchar] = '\n';
		lenchar++;
	}
	line[lenchar] = '\0';
}

void	fill_new_stat(int i, int lenchar, char *stat, char *new_stat)
{
	lenchar++;
	while (stat[lenchar] != '\0')
		new_stat[i++] = stat[lenchar++];
	new_stat[i] = '\0';
	free(stat);
}
