#include"cub3d.h"
#include"minilibx-linux/mlx.h"

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
}
int move(int keycode,t_cub *cub)
{
    printf("-------keycode = %d------\n",keycode);
    if(keycode == 53)
        exit(0);
    return(0);
}

int main(int c,char **v)
{
    t_cub cub;
    
    init_cub(&cub);
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
    check_RGB(cub.c);
    check_RGB(cub.f);
    cub.mlx = mlx_init();
    cub.window = mlx_new_window(cub.mlx, 1400, 720, "CUb3D");
    mlx_hook(cub.window, 17, 0, (void *)exit, &cub);
    mlx_hook(cub.window, 2, 0, move, &cub);
    draw_map(&cub);
    mlx_loop(cub.mlx);
    
}
