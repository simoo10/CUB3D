#ifndef CUB3D_H
#define CUB3D_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
# include <string.h>
#include<stdlib.h>
# include <math.h>
#include"mlx.h"
#define WIDTH 360
#define HEIGHT 360
#define SIZE 40
#define PI 3.14
#define ANGLE 30


typedef struct s_player{
    float x;
    float y;

} t_player;

typedef struct  s_data {
  void        *img;
  char        *addr;
  int         bits_per_pixel;
  int         line_length;
  int         endian;
}               t_data;

typedef struct s_cub
{
    char **map;
    char *no;
    char *so;
    char *we;
    char *ea;
    char *f;
    char *c;
    int count;
    void *mlx;
    void *window;
    void *img;
    int height;
    int width;
    int x;
    int y;
    int pos_x;
    int pos_y;
    int f_rgb;
    int c_rgb;
    t_player player;
  char        *addr;
  int         bits_per_pixel;
  int         line_length;
  int         endian;
  t_data data;
  float orientation;
}   t_cub;




char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	**read_map(char *map,t_cub *cub);
void arg_check(char *v,int c);
size_t	ft_strlen(char *c);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_reste(char *s);
char	*ft_get_line(char *s);
char	*ft_strdup(char *src);
char	*ft_strcpy(char *dest, char *src);
char	*ft_substr(char *s, int start, int len);
char **join_all(char *s,char c);
void check_textures_path(t_cub *cub);
int	ft_atoi(char *str);
void error_msg(char *msg);
void check_RGB(char *rgb,t_cub *cub);
void check_nb_rgb(char *s);
void map_checking(char **map);
int check_WE(char *s);
int check_NO(char *s);
int check_SO(char *s);
int check_EA(char *s);
int check_F(char *s);
int check_C(char *s);
int skip_space(char *s);
void fill_textures(t_cub *cub,char *v);
void check_path(char *s);
void file_existance(int fd,char *s);
void empty_line(char s);
int check_empty_space(char *s);
void empty_file(char *s);
void ft_putstr_fd(char *s,int fd);
void draw_angle(t_cub *cub,int x,int y);
void draw_player_angle(t_cub *cub,int x,int y);
void draw_twoline_represent_angle(t_cub *cub, int x, int y);
void draw_lines(t_cub *cub, int x, int y);
void draw_30_degree_angle(t_cub *cub, int x, int y);
int rendring_minimap(t_cub *cub);
void draw_wall(t_cub *cub,int x,int y);
void draw_colone(t_cub *cub,int x,int y);
void draw_line(t_cub *cub,int x,int y);
void draw_empty(t_cub *cub,int x,int y);
void draw_player_position(t_cub *cub,int x,int y);
void draw_map(t_cub *cub);
#endif
