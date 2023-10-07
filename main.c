#include"cub3d.h"
#include"minilibx-linux/mlx.h"

void init_data(t_data *data)
{
    data->img = NULL;
    data->addr = NULL;
    data->bits_per_pixel = 0;
    data->line_length = 0;
    data->endian = 0;
}

void init_pl(t_player *pl)
{
    pl->x = 0;
    pl->y = 0;
}

void init_cub(t_cub *cub)
{
    cub->map = NULL;
    cub->c=NULL;
    cub->f=NULL;
    cub->ea=NULL;
    cub->we=NULL;
    cub->so=NULL;
    cub->no=NULL;
    cub->count=0;
    cub->mlx=NULL;
    cub->window=NULL;
    cub->height=0;
    cub->width=0;
    cub->x=0;
    cub->y=0;
    cub->pos_x=0;
    cub->pos_y=0;
    cub->img = NULL;
    cub->f_rgb=0;
    cub->c_rgb=0;
    cub->addr = NULL;
    cub->bits_per_pixel = 0;
    cub->line_length = 0;
    cub->endian = 0;
    cub->orientation = 0;
}

void calculateNewPosition(float *x, float *y, float ort, float dist) {
    float radians = ort * PI / 180.0;

    *x += dist * cos(radians);
    *y += dist * sin(radians);
}
int move(int keycode,t_cub *cub)
{
    printf("=========\n");
    printf("-------keycode = %d------\n",keycode);
    if(keycode == 65307)
        exit(0);
    if(keycode == 65361)
    {
        cub->orientation -= 15;
        printf("orientation = %f\n",cub->orientation);
        usleep(1000000);
       // calculateNewPosition(&cub->player.x,&cub->player.y,cub->orientation,1);
    }
    if(keycode == 65363)
    {
        cub->orientation += 15;
        printf("orientation = %f\n",cub->orientation);
        usleep(1000000);
        //calculateNewPosition(&cub->player.x,&cub->player.y,cub->orientation,1);
    }
    if(keycode == 119)
    {
        calculateNewPosition(&cub->player.x,&cub->player.y,cub->orientation,-1);
    }
    if(keycode == 115)
    {
        calculateNewPosition(&cub->player.x,&cub->player.y,cub->orientation,1);
    }
    if(keycode == 97)
    {
        calculateNewPosition(&cub->player.x,&cub->player.y,cub->orientation + 90,1);
    }
    if(keycode == 100 && cub->player.x < 360)
    {
        calculateNewPosition(&cub->player.x,&cub->player.y,cub->orientation - 90,1);
    }

    return(0);
}
void fill_orientation(char c,t_cub *cub)
{
    if(c=='N')
        cub->orientation = 90;
    if(c=='S')
        cub->orientation = 270;
    if(c=='W')
        cub->orientation = 180;
    if(c=='E')
        cub->orientation = 0;
}
void init_player(t_cub *cub)
{
    int i = 0;
    int j = 0;

    while(cub->map[i])
    {
        j = 0;
        while(cub->map[i][j])
        {
            if(cub->map[i][j]=='N' || cub->map[i][j]=='S' || cub->map[i][j]=='W' || cub->map[i][j]=='E')
            {
                cub->player.x = (j*SIZE);
                printf("x = %f\n",cub->player.x);
                cub->player.y = (i*SIZE);
                printf("y = %f\n",cub->player.y);
                fill_orientation(cub->map[i][j],cub);
                return;
            }
            j++;
        }
        i++;
    }
}

int main(int c,char **v)
{
    t_cub cub;
    t_player player;
    t_data data;
    
    init_data(&data);
    init_cub(&cub);
    init_pl(&player);
    cub.player = player;
    arg_check(v[1],c);
    cub.map=read_map(v[1],&cub);
   // check_textures_path(&cub);
    map_checking(cub.map);
    int i = 0;
    while(cub.map[i])
    {
        printf("%s\n",cub.map[i]);
        i++;
    }
    check_RGB(cub.c,&cub);
    check_RGB(cub.f, &cub);
    //printf("f = %d\n",cub.f_rgb);
    cub.mlx = mlx_init();
    cub.window = mlx_new_window(cub.mlx, 360, 360, "CUb3D");
    
    cub.img = mlx_new_image(cub.mlx, 360, 360);
    cub.addr = mlx_get_data_addr(cub.img, &cub.bits_per_pixel, &cub.line_length,
                                 &cub.endian);
    printf("--------\n");
    init_player(&cub);
    // draw_map(&cub);
    mlx_hook(cub.window, 17, 0, (void *)exit, &cub);
    mlx_hook(cub.window, 2, 1L << 0, &move, &cub);
    mlx_loop_hook(cub.mlx, rendring_minimap, &cub);
    mlx_loop(cub.mlx);
}
