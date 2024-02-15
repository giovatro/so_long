/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:13:13 by gtroiano          #+#    #+#             */
/*   Updated: 2024/02/15 15:28:51 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	flood_fill(int y, int x, t_map *map)
{
	if (map->map_fill[y][x + 1] == '0' || map->map_fill[y][x + 1] == 'C'
			|| map->map_fill[y][x + 1] == 'E')
	{
		map->map_fill[y][x + 1] = 'F';
		flood_fill(y, x + 1, map);
	}
	if (map->map_fill[y][x - 1] == '0' || map->map_fill[y][x - 1] == 'C'
			|| map->map_fill[y][x - 1] == 'E')
	{
		map->map_fill[y][x - 1] = 'F';
		flood_fill(y, x - 1, map);
	}
	if (map->map_fill[y + 1][x] == '0' || map->map_fill[y + 1][x] == 'C'
			|| map->map_fill[y + 1][x] == 'E')
	{
		map->map_fill[y + 1][x] = 'F';
		flood_fill(y + 1, x, map);
	}
	if (map->map_fill[y - 1][x] == '0' || map->map_fill[y - 1][x] == 'C'
			|| map->map_fill[y - 1][x] == 'E')
	{
		map->map_fill[y - 1][x] = 'F';
		flood_fill(y - 1, x, map);
	}
}

void	check_path(t_map *map)
{
	int	count;
	int	count2;

	count = 0;
	while (map->map_fill[count])
	{
		count2 = 0;
		while (map->map_fill[count][count2])
		{
			if (map->map_fill[count][count2] == 'C'
					|| map->map_fill[count][count2] == 'E')
			{
				ft_printf("No valid path\n");
				exit(EXIT_FAILURE);
			}
			count2++;
		}
		count++;
	}
}

void	check_e_c_counter(t_data *data, t_map *map)
{
	int	count;
	int	count2;

	count = 0;
	map->map_fill = ft_tabcpy(map->map, map->map_fill);
	while (map->map_fill[count])
	{
		count2 = 0;
		while (map->map_fill[count][count2])
		{
			if (map->map_fill[count][count2] == 'P')
			{
				data->p_y = count;
				data->p_x = count2;
			}
			count2++;
		}
		count++;
	}
	flood_fill(data->p_y, data->p_x, map);
	check_path(map);
}
