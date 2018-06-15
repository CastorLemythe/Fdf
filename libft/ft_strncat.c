/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:45:22 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/14 10:44:40 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t a;

	i = 0;
	a = 0;
	while (dest[i] != '\0')
		i++;
	while (src[a] != '\0' && a < n)
	{
		dest[i + a] = src[a];
		a++;
	}
	dest[i + a] = '\0';
	return (dest);
}
