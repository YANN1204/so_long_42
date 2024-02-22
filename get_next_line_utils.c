/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:28:54 by yrio              #+#    #+#             */
/*   Updated: 2024/01/25 17:06:01 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0' || s[i] == (char)c)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ptr_null(char *s1)
{
	s1 = malloc(1 * sizeof(char));
	if (s1 != NULL)
		s1[0] = '\0';
	else
		return (NULL);
	return (s1);
}

void	apply_join(char *str, char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	str[ft_strlen(s1) + i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		s1 = ptr_null(s1);
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	apply_join(str, s1, s2);
	free(s1);
	return (str);
}

/*
int 	main(void)
{
	static char 	*s1;
	char			*s2;
	char 			*str;

	s1 = malloc(6 * sizeof(char));
	s1 = "salut";
	s2 = malloc(29 * sizeof(char));
	s2[0] = '\0';
	str = ft_strjoin(s1, s2);
	printf("%s\n", str);
	if (str != NULL)
	{
		free(str);
		printf("bien malloc\n");
	}
	return (0);
}
*/

/*
int main(void)
{
	static char	*str;
	int			count;

	str = ft_strdup("");
	count = ft_strlen(str);
	printf("%d", count);
	return (0);
}
*/
