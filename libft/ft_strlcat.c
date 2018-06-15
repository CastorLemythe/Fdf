/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:51:26 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/11 15:37:21 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t i;
	size_t a;

	i = 0;
	if (count == 0)
		return (ft_strlen(src));
	while (dest[i] != '\0' && i < count)
		i++;
	a = i;
	while (src[i - a] != '\0' && i < count - 1)
	{
		dest[i] = src[i - a];
		i++;
	}
	if (a < count)
		dest[i] = '\0';
	return (a + ft_strlen(src));
}
