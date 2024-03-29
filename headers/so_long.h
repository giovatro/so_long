/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:15:54 by gtroiano          #+#    #+#             */
/*   Updated: 2024/02/09 15:07:11 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "../minilibx/mlx.h"

/* defines */

# define IMG_W 32
# define IMG_H 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

/* storing player and background images */

typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
}				t_img;

/* create the map and keep track of the contents */

typedef struct s_map
{
	char	**map;
	char	**map_fill;
	void	*object;
	int		x;
	int		y;
	int		exit;
	int		coins;
}				t_map;

/* handling programs data between functions */

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	int		collectible_fill_counter;
	int		exit_fill_counter;
	t_map	*map;
	t_img	*img;
}				t_data;

/* functions */

void	ft_window_size(t_data *data, char **argv);
int		ft_key_hook(int keycode, t_data *data);
void	ft_create_map(t_data *data);
void	ft_put_object(t_data *data, char *relative_path);
void	ft_put_player(t_data *data);
void	ft_put_background(t_data *data);
void	ft_parse_input(t_data *data, t_map *map, char **argv, int argc);
int		ft_mouse_hook(int mousecode, t_data *data);
void	ft_move(t_data *data, char position, int direction);
int		ft_exit(t_data *data);
void	ft_init(t_data *data, t_map *map);
void	check_e_c_counter(t_data *data, t_map *map);
char	**ft_tabcpy(char **in, char **out);

#endif
