/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:50:45 by lufranco          #+#    #+#             */
/*   Updated: 2017/12/11 15:17:19 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	dest = (char *)malloc(sizeof(*dest) * j + 1);
	i = 0;
	if (dest != NULL)
	{
		while (*s1)
			dest[i++] = *s1++;
		while (*s2)
			dest[i++] = *s2++;
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
