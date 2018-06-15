/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:48:36 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/11 15:09:42 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dest;

	dest = (char *)malloc(sizeof(*dest) * size + 1);
	if (dest == NULL)
		return (NULL);
	while (size > 0)
	{
		dest[size] = '\0';
		size--;
	}
	dest[size] = '\0';
	return (dest);
}
