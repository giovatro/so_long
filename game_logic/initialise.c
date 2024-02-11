/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:16:56 by gtroiano          #+#    #+#             */
/*   Updated: 2024/02/08 18:17:01 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_init_two(t_data *data)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./textures/player_right.xpm";
	data->img->player_right = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./textures/background.xpm";
	data->img->background = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
}

void	ft_init(t_data *data, t_map *map)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	t_img	*img;

	data->map = map;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		perror("Error\nmalloc failed\n");
		exit(EXIT_FAILURE);
	}
	data->img = img;
	relative_path = "textures/player_up.xpm";
	data->img->player_up = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./textures/player_left.xpm";
	data->img->player_left = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./textures/player_down.xpm";
	data->img->player_down = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	ft_init_two(data);
	data->counter = 0;
	data->collected = 0;
}
