/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:13:27 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/10 17:28:35 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	if (src[0] == '\0')
		return ((char*)dest);
	while (dest[i] != '\0')
	{
		j = 0;
		while (src[j] == dest[i + j])
		{
			if (src[j + 1] == '\0')
				return ((char*)dest + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
