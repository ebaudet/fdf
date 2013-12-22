/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 20:12:36 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/22 20:12:36 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c && s[i] != 0)
		i++;
	if (s[i] == 0 && s[i] != (char)c)
		return (NULL);
	else if (s[i] == (char)c)
		return ((char *)&s[i]);
	return ((char *)&s[i]);
}
