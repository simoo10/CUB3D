#include"cub3d.h"

void arg_check(char *v,int c)
{
    char *s = ".cub";
    int i =0;
    int j =0;
    if(c!=2)
    {
        printf("INVALID NUMBER OF ARGUMENT!\n");
        exit(1);
    }
    i = ft_strlen(v) -4;
    while(s[j] && v[i])
    {
        if(s[j]!=v[i])
           (printf("INVALID MAP NAME\n"),exit(1));
        j++;
        i++;
    }
}

void empty_file(char *v)
{
	int i =0;
	
    if(v==NULL)
        (printf("Error\nOops!Empty File!\n"),exit(1));
	while(v[i])
	{
		if(v[i]!=' '&& v[i]!='	' && v[i]!='\n')
			return;
		i++;
	}
	(printf("Error\nOops!Empty File!\n"),exit(1));
}
void	empty_line(char v)
{
	if (v == '\n')
	{
		printf("Error\n---MAP HAVE EMPTY LINE IN THE LAST LINE---\n");
		exit(1);
	}
}
int check_NO(char *v)
{
	int i =0;
	while(v[i] &&(v[i]==' '||v[i]=='	'))
		i++;
	if(v[i]!=' '&& v[i]!='	')
	{
		if(v[i]=='N'&&v[i+1]=='O'&& v[i+2]==' ')
			return(i+3);
	}
	return(0);
}
int check_SO(char *v)
{
	int i =0;
	while(v[i] &&(v[i]==' '||v[i]=='	'))
		i++;
	if(v[i]!=' '&& v[i]!='	')
		if(v[i]=='S'&&v[i+1]=='O'&& v[i+2]==' ')
			return(i+3);
	return(0);
}
int check_WE(char *v)
{
	int i =0;
	while(v[i] &&(v[i]==' '||v[i]=='	'))
		i++;
	if(v[i]!=' '&& v[i]!='	')
		if(v[i]=='W'&&v[i+1]=='E'&& v[i+2]==' ')
			return(i+3);
	return(0);
}
int check_EA(char *v)
{
	int i =0;
	while(v[i] &&(v[i]==' '||v[i]=='	'))
		i++;
	if(v[i]!=' '&& v[i]!='	')
		if(v[i]=='E'&&v[i+1]=='A'&& v[i+2]==' ')
			return(i+3);
	return(0);
}
int check_F(char *v)
{
	int i =0;
	while(v[i] &&(v[i]==' '||v[i]=='	'))
		i++;
	if(v[i]!=' '&& v[i]!='	')
		if(v[i]=='F'&&v[i+1]==' ')
			return(i+2);
	return(0);
}
int check_C(char *v)
{
	int i =0;
	while(v[i] &&(v[i]==' '||v[i]=='	'))
		i++;
	if(v[i]!=' '&& v[i]!='	')
		if(v[i]=='C'&&v[i+1]==' ')
			return(i+2);
	return(0);
}
int check_empty_space(char *v)
{
	int i=0;
	
	while(v[i] && (v[i]==' '||v[i]=='	'||v[i]=='\n'))
		i++;
	if(i==ft_strlen(v))
		return(1);
	
	return(0);
}
int skip_space(char *v)
{
	int i=0;
	
	while(v[i] && (v[i]==' '||v[i]=='	'))
		i++;
	return(i);
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		i++;
	}
	write(fd, s, i);
}

void error_msg(char *msg)
{
	ft_putstr_fd("Error\n",2);
	ft_putstr_fd(msg,2);
	exit(1);
}
void fill_textures(t_cub *cub,char *v)
{
	int i = 0;
	if(check_NO(v))
	{
		i=check_NO(v);
		if(cub->no)
			error_msg("Oops!Something Happens!\n");
		cub->no=ft_substr(v,i,ft_strlen(v));
		//free(v);
		cub->count++;
	}
	else if(check_SO(v))
	{
		i=check_SO(v);
		if(cub->so)
			error_msg("Oops!Something Happens!\n");
		cub->so = ft_substr(v,i,ft_strlen(v));
		//free(v);
		cub->count++;
	}
	else if(check_EA(v))
	{
		i=check_EA(v);

		if(cub->ea)
			error_msg("Oops!Something Happens!\n");
		cub->ea = ft_substr(v,i,ft_strlen(v));
		//free(v);
		cub->count++;
	}
	else if(check_WE(v))
	{
		i=check_WE(v);
		if(cub->we)
			error_msg("Oops!Something Happens!\n");
		cub->we = ft_substr(v,i,ft_strlen(v));
		//free(v);
		cub->count++;
	}
	else if(check_C(v))
	{
		i=check_C(v);
		if(cub->c)
			error_msg("Oops!Something Happens!\n");
		cub->c = ft_substr(v,i,ft_strlen(v));
		//free(v);
		cub->count++;
	}
	else if(check_F(v))
	{
		i=check_F(v);
		if(cub->f)
			error_msg("Oops!Something Happens!\n");
		cub->f = ft_substr(v,i,ft_strlen(v));
		//free(v);
		cub->count++;
	}
	else
		error_msg("Oops!Something Happens!\n");
	
}
void file_existance(int fd,char *s)
{
	if(fd==-1)
	{
		free(s);
		close(fd);
		error_msg("Oops!This Path Not Found!\n");
	}
}
char	**read_map(char *map,t_cub *cub)
{
	int		fd;
	char	*line;
	char	*v;
	char	**split;
	int		i;
	int e = 0;

	split = NULL;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	v = NULL;
	i = 0;
	//TAKE TEXTURES;
	while (line)
	{
		if(check_empty_space(line))
		{	
			free(line);
			line = get_next_line(fd);
			continue;
		}
		fill_textures(cub,line);
		//free(line);
		if(cub->count==6)
			break;
		line = get_next_line(fd);
	}
	//TAKE MAP;
	line = get_next_line(fd);
	while(line)
	{
		if(check_empty_space(line))
		{	
			free(line);
			line = get_next_line(fd);
			continue;
		}
		break;
	}
	while(line)
	{
		e = 0;
		e = skip_space(line);
		if(line[e]=='\n')
			error_msg("Oops!Empty Line in Map!\n");
		if(line[e]!='1')
			error_msg("Oops!Map Has An Error!\n");
		v = ft_strjoin(v,line);
		free(line);
		line = get_next_line(fd);
	}
	empty_file(v);
	i = ft_strlen(v);
	empty_line(v[i - 1]);
	split = ft_split(v, '\n');
	free(v);
	close (fd);
	return (split);
}
void check_path(char *path)
{
	int i = 0;

	char *s = ".xpm";

	i = skip_space(path);
	if(path[i]!='.')
		(error_msg("Oops!Invalid Path!\n"));
	else
		i++;
	if(path[i]!='/')
		error_msg("Oops!Invalid Path!\n");
	else
		i++;
	while(path[i])
	{
		if(path[i] ==' ' || path[i]=='	')
			error_msg("Oops!Invalid Path!\n");
		i++;
	}
	i = i-5;
	int j = 0;
	while(s[j] && path[i])
	{
		if(s[j]!=path[i])
			error_msg("Oops!Invalid Path!\n");
		i++;
		j++;
	}
}

void check_textures_path(t_cub *cub)
{
	int fd;
	if(cub->no)
	{
		check_path(cub->no);
		fd = open(cub->no,O_RDONLY);
		file_existance(fd,cub->no);
	}
	else
		error_msg("Oops!NO Texture Not Found!\n");
	if(cub->so)
	{
		check_path(cub->so);
		fd = open(cub->so,O_RDONLY);
		file_existance(fd,cub->so);
	}
	else
		error_msg("Oops!SO Texture Not Found!\n");
	if(cub->ea)
	{
		check_path(cub->ea);
		fd = open(cub->ea,O_RDONLY);
		file_existance(fd,cub->ea);
	}
	else
		error_msg("Oops!EA Texture Not Found!\n");
	if(cub->we)
	{
		check_path(cub->we);
		fd = open(cub->we,O_RDONLY);
		file_existance(fd,cub->we);
	}
	else
		error_msg("Oops!WE Texture Not Found!\n");
}
void check_RGB(char *rgb)
{
	int i = 0;
	int count = 0;
	int j = 0;
	int k = 0;
	int nb = 0;
	i = skip_space(rgb);	
	while(rgb[i])
	{
		if(rgb[i]==',')
			count++;
		i++;
	}
	if(count!=2)
		error_msg("Oops!Invalid RGB!\n");
	i = skip_space(rgb);
	char **n = ft_split(rgb + i,',');
	//printf
	i =0;
	while(n[i])
		i++;
	if(i!=3)
		error_msg("Oops!Invalid RGB!\n");
	i = 0;
	while(n[i])
	{
		printf("%s\n",n[i]);
		j = 0;
		while(n[i][j])
		{
			if(n[i][j]<'0' || n[i][j]>'9')
			{
				
				if(i==2 && j==ft_strlen(n[i])-1)
				{
					if(n[i][j]=='\n')
						break;
				}
				error_msg("Oops!Invalid RGB!\n");
			}
			j++;
		}
		i++;
	}
	i =-1;
	while(n[++i])
		check_nb_rgb(n[i]);
}
void check_nb_rgb(char *s)
{
	int nb = 0;

	nb = ft_atoi(s);
	if(nb<0 || nb>255)
		error_msg("---Oops!Invalid RGB!---\n");
}

void check_around_zero(char **map,int i,int j,int k)
{
	if(map[i][j+1]==' ' || map[i][j-1]==' ' || map[i+1][j]==' ' || map[i-1][j]!=' ')
		error_msg("Oops!Map Has An Error!\n");
	
}
void map_checking(char **map)
{
	int i = 0;
	int j = 0;
	int count = 0;
	int count2 = 0;
	int k =0;
	while(map[count2])
		count2++;
	j = skip_space(map[i]);
	//printf("*****%s\n",map[i]);
	while(map[i][j])
	{
		if(map[i][j]!='1')
			error_msg("@@@@Oops!Map Should surrounded by wall!\n");
		j++;
	}
	j = 0;
	i = 0;
	while(map[i])
	{
		j = 0;
		j = skip_space(map[i]);
		k = j;
		printf("++%s\n",map[i]);
		while(map[i][j])
		{
			if(map[i][k] != '1' || map[i][ft_strlen(map[i])-1]!='1')
			{
				printf("-----%c\n",map[i][j]);
				error_msg("------Oops!Map Should surrounded by wall!\n");
			}
			if(map[i][j]=='S' || map[i][j]=='N' || map[i][j]=='W' || map[i][j]=='E')
				count++;
			if(map[i][j] != '1' && map[i][j]!='0' && map[i][j] !=' ' && map[i][j]!='S' && map[i][j]!='N' && map[i][j]!='W' && map[i][j]!='E')
				error_msg("Oops!Invalid Character in Map!\n");
			if(map[i][j]=='0')
			{
				printf("-----%c\n",map[i][j-4]);
				//printf("dddddd\n");
				check_around_zero(map,i,j,k);
			}
			j++;
		}
		if(i==count2-1)
		{
			j = 0;
			while(map[i][j])
			{
				if(map[i][j]!='1' && map[i][j]!=' ')
					error_msg("====Oops!Map Should surrounded by wall!\n");
				j++;
			}
		}
		i++;
	}
}