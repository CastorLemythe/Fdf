/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:42:21 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/11 10:55:54 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_rec_putnbr(unsigned int nb)
{
	if (nb / 10 != 0)
		ft_rec_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void			ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_rec_putnbr(-nb);
	}
	else
		ft_rec_putnbr(nb);
}
