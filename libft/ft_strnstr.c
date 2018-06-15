/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:46:53 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/10 16:59:52 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (*dest != '\0' && i < len)
	{
		while (dest[j] == src[j] && src[j] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if (src[j] == '\0')
			return ((char *)dest);
		i = i - j;
		j = 0;
		dest++;
		i++;
	}
	return (NULL);
}
