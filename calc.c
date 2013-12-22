/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:27:02 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/22 22:00:36 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_calc_ay(float i, float j, float z)
{
	int		y;
	float	ay;
	float	d;
	float	e;

	i = (i + 1) * GRID_SIZE;
	z = (z + 1) * GRID_SIZE / RAT_Z;
	j = (j + 1) * GRID_SIZE / RAT_Y;
	d = ft_sqrt((my_pow(i) + my_pow(i))) / 2;
	e = ft_sqrt((my_pow(j) + my_pow(j))) / 2;
	ay = d + e;
	return ((y = (int)ay) - (int)z);
}

int		ft_calc_ax(float i, float j, float z)
{
	int		x;
	float	ax;
	float	d;
	float	e;

	i = (i + 1) * GRID_SIZE;
	z = (z + 1) * GRID_SIZE;
	j = (j + 1) * GRID_SIZE;
	d = ft_sqrt((my_pow(i) + my_pow(i))) / 2;
	e = ft_sqrt((my_pow(j) + my_pow(j))) / 2;
	ax = (ft_sqrt(my_pow(j) - my_pow(e))) - (ft_sqrt(my_pow(i) - my_pow(d)));
	return ((x = (int)ax) + OFFSET_X);
}

float	my_pow(float x)
{
	return (x * x);
}

int		ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

float	ft_sqrt(const float x)
{
	int		i;
	float	d;
	float	p;
	float	a;

	i = 0;
	while ((i * i) <= x)
		i++;
	i--;
	d = x - i * i;
	p = d / (2 * i);
	a = i + p;
	return (a - (p * p) / ( 2 * a));
}
