/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/24 18:53:35 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 10:28:37 by davfelix    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE		1
# define WINDOW_LARGE	1860
# define WINDOW_HIGHT	1280
# define SCALE			40
# define RED			0xFF0000
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# include "../libft/libft.h"
# include "../Ressource/minilibx_macos/mlx.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_line
{
	char			**line;
	struct s_line	*next;
}					t_line;

typedef struct		s_map
{
	float			**tab;
	int				sizex;
	int				sizey;
	float			df_gapx;
	float			df_gapy;
	int				move_x;
	int				move_y;
	float			move_z;
	int				save_view;
	int				save_key;
}					t_map;

typedef struct		s_node
{
	float			x;
	float			y;
	float			z;
}					t_node;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img;
	int				bpp;
	int				s_l;
	int				endian;
	long long int	max;
	long long int	min;
}					t_env;

typedef struct		s_win_map
{
	int				df_sizex_map;
	int				df_sizey_map;
	float			df_y_min;
	float			df_y_max;
	float			df_x_min;
	float			df_x_max;
	double			df_hight_map;
	float			df_large_map;
	int				df_start_posx;
	int				df_start_posy;

}					t_win_map;

typedef struct		s_bresenham
{
	int				x[2];
	int				y[2];
	int				ex;
	int				ey;
	int				dx[2];
	int				dy[2];
	int				x_incr;
	int				y_incr;
}					t_bresenham;

typedef struct		s_ma
{
	t_map			*tmap;
	t_node			**tnode;
	t_env			*tenv;
	t_win_map		*twinmap;
}					t_ma;

/*
**	Parsing
*/

int					get_next_line(const int fd, char **line);
int					ft_parsing(char *file, t_map *map, int len);
int					a_to_i(int *len, char **tmp, t_map *map);
void				free_tmp(char **str);
void				free_list(t_line *list);
int					usage(int bolean);
void				push_back_list(t_line **begin_list, char *str);

/*
**			HUD
*/

void				inithud(t_ma *master);
void				trace_frame(int x, int y, int **img);

/*
**	Windows map
*/

void				map_iso(t_map *map, t_win_map *win_map, t_ma *master,
		int marge);
void				map_cav(t_map *map, t_win_map *win_map, t_ma *master,
		int marge);
void				zoom(t_map *map);

/*
**	Resolv
*/

void				bresenham(t_node node1, t_node node2, t_map *map,
		int **img);
int					key_event(int key, t_ma *master);
int					close_event(t_ma *master);
void				scale(t_ma *master);
void				free_exit(t_ma *master);
void				clean_new(t_ma *master);
t_node				**isometrie(t_map *map, t_node **node, t_ma *master);
t_node				**cavaliere(t_map *map, t_node **node, t_ma *master);
void				tracer(t_map *map, t_node **node, char *img, int i);
void				fill_pixel(int **img, int x, int y, int color);

#endif
