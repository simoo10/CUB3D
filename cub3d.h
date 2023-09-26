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
    int height;
    int width;
    int x;
    int y;
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
void check_RGB(char *rgb);
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
#endif
