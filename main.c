#include"cub3d.h"

int main(int c,char **v)
{
    t_cub cub;
    
    cub.map = NULL;
    cub.c=NULL;
    cub.f=NULL;
    cub.ea=NULL;
    cub.we=NULL;
    cub.so=NULL;
    cub.no=NULL;
    cub.count=0;
    arg_check(v[1],c);
    cub.map=read_map(v[1],&cub);
    // int i = 0;
    // while(cub.map[i])
    // {
    //     printf("%s\n",cub.map[i]);
    //     i++;
    // }
   // check_textures_path(&cub);
    map_checking(cub.map);
    check_RGB(cub.c);
   
}
