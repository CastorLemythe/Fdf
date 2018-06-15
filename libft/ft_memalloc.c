/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:51:19 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/11 16:13:58 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		*tab;

	tab = (int *)malloc(sizeof(*tab) * size);
	if (tab == NULL)
		return (NULL);
	while (size > 0)
	{
		tab[size - 1] = 0;
		size--;
	}
	return (tab);
}
