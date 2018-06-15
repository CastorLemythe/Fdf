/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:16:23 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/11 10:51:28 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = f(s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
