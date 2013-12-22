/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:28:33 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/22 19:58:46 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_tab(int **tab)
{
	int i = -1, j = 0;
	while (tab[++i])
	{
		j = 0;
		ft_putstr(" [ ");
		ft_putnbr(tab[i][0]);
		while (++j <= tab[i][0])
		{
			ft_putstr(" | ");
			ft_putnbr(tab[i][j]);
		}
		ft_putstr(" ]\n");
			
	}
}

int		**ft_get_data(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		**tab;

	i = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf [data_file]\n");
		exit(0);
	}
	i = ft_data_size(argv[1]);
	tab = (int**)malloc((i + 1) * (sizeof(*tab)));
	tab[i] = '\0';
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tab[i] = ft_put_data(line);
		i++;
		free(line);
	}
	print_tab(tab);
	return (tab);
}

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

int		ft_data_size(char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("usage: ./fdf [data_file]\n");
		exit(0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

int		*ft_put_data(char *str)
{
	char	**chartab;
	int		*tab;
	int		i;
	int		j;

	chartab = ft_strsplit(str, ' ');
	i = ft_tablen(chartab);
	tab = (int*)malloc((i + 1) * (sizeof(*tab)));
	tab[0] = i;
	j = 0;
	while (++j <= i)
		tab[j] = ft_atoi(chartab[j - 1]);
	return (tab);
}
