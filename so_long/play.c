#include <stdlib.h>
#include <stdio.h>
#include "minilibx/mlx.h"

typedef struct s_mlx_data
{
    void    *mlx_ptr; //it's the connection to the X server
    void    *win_ptr; //it's the window. Each window has its own unique identifier (a window pointer)
}   t_mlx_data;


int deal_key(int key, t_mlx_data *data)
{
    if (key == 53)
    {
        printf("The %d key (ESC) has been pressed\n", key);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        free(data->mlx_ptr);
        exit(1);    
    }
    printf("The %d key has been pressed\n", key);
    return (0);
}

int main()
{
    t_mlx_data  data;
    void    *img;
    char    *relative_path = "angel_idle_anim_f0.xpm";
    int     img_width;
    int     img_height;

    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr) //I may also type if (NULL == data.mlx_init())
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "my first window");
    if (!data.win_ptr)
        return (free(data.mlx_ptr), 1);
    img = mlx_xpm_file_to_image(data.mlx_ptr,relative_path, &img_width, &img_height);
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 80, 40);
    //mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
    //mlx_string_put(mlx_ptr, win_ptr, 200, 200, 0xFFFFFF, "testing");
    mlx_key_hook(data.win_ptr, deal_key, &data);
    mlx_loop(data.mlx_ptr);
}

/*
create the first window with the following prototype:
void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

to load textures into the MLX we use mlx_xpm_file_to_image
void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

You can now start rendering textures and see something on the screen. 
For this, there is the MLX function mlx_put_image_to_window
int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
The image pointer argument is the void * returned from mlx_xpm_file_to_image, 
and x & y correspond to the position of the screen from the top left-most pixel of the texture.

*/