#include"cub3d.h"

void            my_mlx_pixel_put(t_cub *data, int x, int y, int color)
{
  char    *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}
void draw_line_orientation(t_cub *cub,int x,int y)
{
    int i =0;
    int j =0;

    while(i<40)
    {
        j=0;
        while(j<2)
        {
            my_mlx_pixel_put(cub,(x*SIZE) + i,j + (y *SIZE),0x00000);
            j++;
        }
        i++;
    }
}
void mlx_line_put(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx, sy;

    if (x0 < x1) {
        sx = 1;
    } else {
        sx = -1;
    }

    if (y0 < y1) {
        sy = 1;
    } else {
        sy = -1;
    }

    int err = dx - dy;
    int current_x = x0;
    int current_y = y0;

    while (current_x != x1 || current_y != y1) {
        // Set the pixel at the current position to the specified color
        mlx_pixel_put(mlx_ptr, win_ptr, current_x, current_y, color);

        int err2 = 2 * err;

        if (err2 > -dy) {
            err -= dy;
            current_x += sx;
        }

        if (err2 < dx) {
            err += dx;
            current_y += sy;
        }
    }
}
void drawRay(t_cub *cub, float playerX, float playerY, float orientationAngle) {
    float rayX = playerX + cos(orientationAngle * PI / 180.0) * 100.0; 
    float rayY = playerY + sin(orientationAngle * PI / 180.0) * 100.0; 

    // Draw the ray
   // mlx_line_put(mlx_ptr, win_ptr, playerX, playerY, rayX, rayY, 0xFFFFFF);
    mlx_line_put(cub->mlx, cub->window, playerX, playerY, rayX, rayY, 0x00000);
     // White color
}
int rendring_minimap(t_cub *cub)
{
    mlx_clear_window(cub->mlx, cub->window);
    draw_map(cub);drawRay(cub,cub->player.x,cub->player.y,cub->orientation);
    draw_player_position(cub,cub->player.x,cub->player.y);
    mlx_put_image_to_window(cub->mlx, cub->window, cub->img, 0, 0);
    return(0);
}
void draw_wall(t_cub *cub,int x,int y)
{
    int i =0;
    int j =0;

    while(i<40)
    {
        j=0;
        while(j<40)
        {
            my_mlx_pixel_put(cub,(x*SIZE) + i,j + (y *SIZE),0xFC3939);
            j++;
        }
        i++;
    }
}
void draw_colone(t_cub *cub,int x,int y)
{
    int i =0;
    int j =0;

    while(i<2)
    {
        j=0;
        while(j<40)
        {
            my_mlx_pixel_put(cub,(x*SIZE) + i,j + (y *SIZE),0X0000);
            j++;
        }
        i++;
    }
}
void draw_line(t_cub *cub,int x,int y)
{
    int i =0;
    int j =0;

    while(i<40)
    {
        j=0;
        while(j<2)
        {
            my_mlx_pixel_put(cub,(x*SIZE) + i,j + (y *SIZE),0X0000);
            j++;
        }
        i++;
    }
}
void draw_empty(t_cub *cub,int x,int y)
{
    int i =0;
    int j =0;

    while(i<40)
    {
        j=0;
        while(j<40)
        {
            my_mlx_pixel_put(cub,(x*SIZE) + i,j + (y *SIZE),0x007DA8);
            j++;
        }
        i++;
    }
}

void draw_player_position(t_cub *cub,int x,int y)
{
    int i =15;
    int j =0;
  //  printf("x = %d\n",cub->x);
  //  printf("y = %d\n",cub->y);

  printf("x = %f\n",cub->player.x);
    printf("y = %f\n",cub->player.y);
   // exit(0);
    while(i<25)
    {
        j=15;
        while(j<25)
        {
            my_mlx_pixel_put(cub,cub->player.x +i,j + cub->player.y,0XFBFF00);
            j++;
        }
        
        i++;
    }
}
void draw_map(t_cub *cub)
{
    int i = 0;
    int j = 0;

    while(cub->map[i])
    {
        j = 0;
        while(cub->map[i][j])
        {
            if(cub->map[i][j]=='1')
            {
                draw_wall(cub,j,i);
                draw_colone(cub,j,i);
                draw_line(cub,j,i);
            }
            if(cub->map[i][j] == '0')
            {
                draw_empty(cub,j,i);
                draw_colone(cub,j,i);
                draw_line(cub,j,i);
            }
            if(cub->map[i][j]=='N' || cub->map[i][j]=='S' || cub->map[i][j]=='W' || cub->map[i][j]=='E')
            {
                draw_empty(cub,j,i);
                draw_colone(cub,j,i);
                draw_line(cub,j,i);
            }
            j++;
        }
        i++;
    }
}

//void fill_ort_move()
// void draw_angle(t_cub *cub)
// {
    
// }
