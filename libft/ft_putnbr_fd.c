/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:28:48 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/11 11:01:16 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rec_putnbr_fd(unsigned int nb, int fd)
{
	if (nb / 10 != 0)
		ft_rec_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		ft_rec_putnbr_fd(-nb, fd);
	}
	else
		ft_rec_putnbr_fd(nb, fd);
}
