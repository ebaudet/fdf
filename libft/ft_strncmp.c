/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 20:12:36 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/22 20:12:36 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		ret;

	ret = 0;
	while (!(ret = *(unsigned char *) s1 - *(unsigned char *) s2) && *s2 && n--)
	{
		++s1;
		++s2;
	}
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1 ;
	return (ret);
}
