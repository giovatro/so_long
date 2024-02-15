/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:58:02 by gtroiano          #+#    #+#             */
/*   Updated: 2024/02/11 16:03:21 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_map_error(char *error_msg)
{
	ft_printf("%s", error_msg);
	exit(EXIT_FAILURE);
}

static void	ft_check_walls(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->size_y / IMG_H))
	{
		if ((int)ft_strlen(data->map->map[y]) != data->size_x / IMG_W)
			ft_map_error("Error\nmap has to be rectangular\n");
		x = 0;
		while (x < (data->size_x / IMG_W))
		{
			if (data->map->map[y][x] != '0' && data->map->map[y][x] != '1' &&
				data->map->map[y][x] != 'C' && data->map->map[y][x] != 'P' &&
				data->map->map[y][x] != 'E')
				ft_map_error("Error\nfor map '0','1','C','P','E' are valid\n");
			else if ((y == 0 || x == 0) && data->map->map[y][x] != '1')
				ft_map_error("Error\nmap has to be surrounded by walls\n");
			else if ((y == (data->size_y / IMG_H - 1)
					|| x == (data->size_x / IMG_W - 1))
				&& data->map->map[y][x] != '1')
				ft_map_error("Error\nmap has to be surrounded by walls\n");
			x++;
		}
		y++;
	}
}

static void	ft_check_content(t_data *data)
{
	int	y;
	int	player;

	player = 0;
	data->map->exit = 0;
	data->map->coins = 0;
	y = 0;
	while (data->map->map && data->map->map[y])
	{
		data->map->exit += ft_count_c(data->map->map[y], 'E');
		player += ft_count_c(data->map->map[y], 'P');
		data->map->coins += ft_count_c(data->map->map[y], 'C');
		y++;
	}
	if (player != 1)
		ft_map_error("Error\nno player found\n");
	if (data->map->exit != 1)
		ft_map_error("Error\nMap must have 1 exit\n");
	if (data->map->exit == 0)
		ft_map_error("Error\nno exit found\n");
	if (data->map->coins == 0)
		ft_map_error("Error\nno collectibles found\n");
}

static void	ft_input_error(int argc)
{
	if (argc != 2)
	{
		ft_map_error("Error\nUsage: './so_long mappath/mapname.ber'\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_parse_input(t_data *data, t_map *map, char **argv, int argc)
{
	int		fd;
	int		i;
	int		bytes;
	char	buffer[2];

	ft_input_error(argc);
	i = 0;
	bytes = 1;
	buffer[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
		{
			data->map->map[i] = ft_strjoin(data->map->map[i], buffer);
		}
		else
			i++;
	}
	ft_check_content(data);
	ft_check_walls(data);
	check_e_c_counter(data, map);
}
