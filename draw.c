/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:26:32 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/22 22:00:41 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		max_width(int **tab)
{
	int		max;
	int		i;

	i = -1;
	while (tab[++i])
	{
		if (tab[i][0] > max)
			max = tab[i][0];
	}
	return (max);
}

void	ft_draw(t_env *e, int **tab)
{
	t_point	point1;
	t_draw_all	draw;

	draw.max = max_width(tab);
	draw.trace_ok = 1;
	draw.i = 0;
	draw.j = 1;
	point1.x = 300;
	point1.y = 20;
	while (tab[draw.i] != '\0')
	{
		while (draw.j <= tab[draw.i][0])
			ft_draw_while(&draw, tab, &point1, e);
		draw.j = 1;
		draw.i++;
	}
	draw.i = 0;
	draw.j = 1;
	while (draw.j <= draw.max)
	{
		while (tab[draw.i] != '\0')
			ft_draw_while2(&draw, tab, &point1, e);
		draw.i = 0;
		draw.j++;
	}
}

void	ft_draw_while(t_draw_all *draw, int **tab, t_point *point1, t_env *e)
{
	draw->fi = draw->i;
	draw->fj = draw->j;
	draw->fz = tab[draw->i][draw->j];
	point1->x2 = ft_calc_ax(draw->fi, draw->fj, draw->fz);
	point1->y2 = ft_calc_ay(draw->fi, draw->fj, draw->fz);
	if (draw->j != 1)
		ft_trace(point1, e, WHITE, draw->fz);
	point1->x = point1->x2;
	point1->y = point1->y2;
	draw->j++;
}

void	ft_draw_while2(t_draw_all *draw, int **tab, t_point *point1, t_env *e)
{
	if (tab[draw->i][0] < draw->j)
	{
		draw->i++;
		draw->trace_ok = 0;
		return ;
	}
	draw->fi = draw->i;
	draw->fj = draw->j;
	draw->fz = tab[draw->i][draw->j];
	if (!draw->trace_ok)
	{
		point1->x = ft_calc_ax(draw->fi, draw->fj, draw->fz);
		point1->y = ft_calc_ay(draw->fi, draw->fj, draw->fz);
		draw->trace_ok = 1;
	}
	point1->x2 = ft_calc_ax(draw->fi, draw->fj, draw->fz);
	point1->y2 = ft_calc_ay(draw->fi, draw->fj, draw->fz);
	if (draw->i != 0 && draw->trace_ok)
		ft_trace(point1, e, WHITE, draw->fz);
	point1->x = point1->x2;
	point1->y = point1->y2;
	draw->i++;
}

void	ft_trace(t_point *pt1, t_env *new, int color, int height)
{
	t_delta	delta;

	delta.dx = ft_abs(pt1->x2 - pt1->x);
	delta.x = (pt1->x < pt1->x2) ? 1 : -1;
	delta.dy = ft_abs(pt1->y2 - pt1->y);
	delta.y = (pt1->y < pt1->y2) ? 1 : -1;
	delta.deltaE = (delta.dx > delta.dy) ? delta.dx : -delta.dy;
	delta.deltaE = delta.deltaE / 2;
	while (1)
	{
		mlx_pixel_put(new->mlx, new->win, pt1->x, pt1->y, color - height * BLUE);
		if (pt1->x == pt1->x2 && pt1->y == pt1->y2)
			break ;
		delta.deltaNE = delta.deltaE;
		if (delta.deltaNE > -delta.dx)
		{
			delta.deltaE -= delta.dy;
			pt1->x += delta.x;
		}
		if (delta.deltaNE < delta.dy)
		{
			delta.deltaE += delta.dx;
			pt1->y += delta.y;
		}
	}
}
