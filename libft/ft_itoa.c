/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:03:03 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/11 11:02:53 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void		ft_neg_itoa(char *dest, int index, unsigned int n)
{
	n = -n;
	while (index > 0)
	{
		dest[index - 1] = n % 10 + '0';
		n = n / 10;
		index--;
	}
	dest[0] = '-';
}

char			*ft_itoa(int n)
{
	char	*dest;
	int		index;

	index = ft_nbrlen(n);
	dest = (char *)malloc(sizeof(*dest) * (index + 1));
	if (dest == NULL)
		return (NULL);
	dest[index] = '\0';
	if (n < 0)
		ft_neg_itoa(dest, index, n);
	else
	{
		while (index > 0)
		{
			dest[index - 1] = n % 10 + '0';
			n = n / 10;
			index--;
		}
	}
	return (dest);
}
