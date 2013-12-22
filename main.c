/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:21:51 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/22 22:00:45 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		key_hook(int keycode, t_env *e)
{
	int		i;

	if (e)
		i = 0;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		expose_hook(t_param *t)
{
	ft_draw(t->e, t->tab);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		new;
	t_param		t;

	t.tab = ft_get_data(argc, argv);
	new.mlx = mlx_init();
	new.win = mlx_new_window(new.mlx, WIDTH, HEIGHT, "42");
	t.e = &new;
	mlx_key_hook(new.win, key_hook, &new);
	mlx_expose_hook(new.win, expose_hook, &t);
	mlx_loop(new.mlx);
	return (0);
}
