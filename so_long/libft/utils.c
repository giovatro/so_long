/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:39:40 by gtroiano          #+#    #+#             */
/*   Updated: 2024/02/08 17:39:47 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_count_c(char *s, char c)
/* will count appearances of c inside s and return them as integer */
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!s)
		return (-1);
	while (s && s[i])
	{
		if (s[i++] == c)
			x++;
	}
	return (x);
}

void	exit_error(void)
{
	printf("Error\nwrong map dimensions\n");
	exit(EXIT_FAILURE);
}

int	ft_count_lines(int fd, int x, int img_w)
/* returns how many lines the file of fd contains */
{
	char	*line;
	int		linecount;
	int		i;

	i = 0;
	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_strlen(line) < x / img_w
			|| (ft_strlen(line) == 1 && *line != '\n'))
		{
			free(line);
			exit_error();
		}
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}

int	ft_line_length(int fd)
/* this function will find the length of the first line in a file */
{
	char	buffer[1];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}
