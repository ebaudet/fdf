/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 20:12:36 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/22 20:12:36 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	if (s)
	{
		i = 0;
		j = ft_strlen((char *) s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		tmp = (char *)malloc(sizeof(char) * (j - i + 1));
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		k = 0;
		while (i <= j)
		{
			tmp[k] = s[i];
			i++;
			k++;
		}
		tmp[k] = '\0';
		return (tmp);
	}
	return (NULL);
}
