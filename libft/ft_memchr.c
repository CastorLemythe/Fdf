/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:14:08 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/10 16:23:36 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s1;
	size_t	i;

	i = 0;
	s1 = (char *)s;
	c = (char)c;
	while (n--)
	{
		if (s1[i] == c)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
