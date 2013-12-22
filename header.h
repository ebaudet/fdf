/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:24:36 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/22 19:59:00 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/includes/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define WIDTH		720
# define HEIGHT		720

# define GRID_SIZE	20

# define OFFSET_X	350
# define OFFSET_Y	-20

# define RAT_Z		10
# define RAT_Y		2

# define WHITE 0xFFFFFF
# define GREY 0x555555
# define VIOLET 0xB545AE
# define BLUE 0x6692CC
# define GREEN 0x81CC66
# define ORANGE 0xED6205

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_point
{
	int				x;
	int				y;
	int				x2;
	int				y2;
}					t_point;

typedef struct		s_delta
{
	int				dx;
	int				dy;
	int				dp;
	int				deltaE;
	int				deltaNE;
	int				x;
	int				y;
}					t_delta;

typedef union		u_union
{
	int				i;
	float			x;
}					t_union;

typedef struct		s_draw_all
{
	float			fi;
	float			fj;
	float			fz;
	int				i;
	int				j;
	t_point			*point1;
	t_point			*point2;
	int				trace_ok;
}					t_draw_all;

typedef struct		s_param
{
	t_env			*e;
	int				**tab;
}					t_param;

/*
** get_data.c
*/
void	print_tab(int **tab);
int		**ft_get_data(int argc, char **argv);
int		ft_tablen(char **tab);
int		ft_data_size(char *file);
int		*ft_put_data(char *str);

/*
** draw.c
*/
void	ft_draw(t_env *e, int **tab);
void	ft_draw_while(t_draw_all *draw, int **tab, t_point *point1, t_env *e);
void	ft_draw_while2(t_draw_all *draw, int **tab, t_point *point1, t_env *e);
void	ft_trace(t_point *pt1, t_env *new, int color, int height);

/*
** calc.c
*/
int		ft_calc_ay(float i, float j, float z);
int		ft_calc_ax(float i, float j, float z);
float	my_pow(float x);
int		ft_abs(int value);
float	ft_sqrt(const float x);

/*
** main.c
*/
int		key_hook(int keycode, t_env *e);
int		expose_hook(t_param *t);

#endif /* HEADER_H */
