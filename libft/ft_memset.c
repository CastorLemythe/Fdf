/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:53:43 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/09 17:07:02 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;

	if (len == 0)
		return (b);
	str = (unsigned char*)b;
	while (len--)
	{
		*str = (unsigned char)c;
		if (len)
			str++;
	}
	return (b);
}
