/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:43:46 by lufranco          #+#    #+#             */
/*   Updated: 2018/03/12 18:59:53 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	z_iso_max(t_case *stock)
{
	int x;
	int y;
	int tmp1;
	int tmp2;

	y = 0;
	tmp1 = 0;
	while (y < stock->height)
	{
		x = 0;
		while (x < stock->width)
		{
			tmp2 = 50 + 25 * (x / 2) + 25 * (y / 2);
			if (tmp2 - stock->map[y][x] * 50 < 50)
				tmp2 = 50 - (tmp2 - stock->map[y][x] * 50);
			else
				tmp2 = 0;
			if (tmp1 < tmp2)
				tmp1 = tmp2;
			x += 2;
		}
		y += 2;
	}
	stock->z_iso = tmp1;
	return (tmp1);
}

int	z_iso(t_case *stock)
{
	int x;
	int y;
	int tmp1;
	int tmp2;
	int point;

	y = stock->height;
	tmp1 = 0;
	point = 50 + 25 * (stock->height / 2) + 25 * (stock->width / 2);
	while (y > 0)
	{
		x = stock->width;
		while (x > 0)
		{
			tmp2 = 50 + 25 * (y / 2)  + 25 * (x / 2) - 50 *
			stock->map[y - 1][x - 1];
			if (tmp1 < tmp2 - point)
				tmp1 = tmp2 - point;
			x -= 2;
		}
		y -= 2;
	}
	return (tmp1 + z_iso_max(stock));
}

int     z_para_max(t_case *stock)
{
	int x;
	int y;
	int tmp1;
	int tmp2;

	y = -1;
	tmp1 = 0;
	while (++y < stock->height)
	{
		x = 0;
		while (x < stock->width)
		{
			tmp2 = 30 + 15 * y + 15 * x;
			if (tmp2 - stock->map[y][x] * 30 < 30)
				tmp2 = 30 - (tmp2 - stock->map[y][x] * 30);
			else
				tmp2 = 0;
			if (tmp1 < tmp2)
				tmp1 = tmp2;
			x++;
		}
	}
	stock->z_para = tmp1;
	return (tmp1);
}

int	z_para(t_case *stock)
{
	int x;
	int y;
	int tmp1;
	int tmp2;
	int point;

	y = stock->height;
	tmp1 = 0;
	point = 30 + 15 * stock->height + 15 * stock->width;
	while (y > 0)
	{
		x = stock->width;
		while (x > 0)
		{
			tmp2 = 30 + 15 * y + 15 * x - 30 *
			stock->map[y - 1][x - 1];
			if (tmp1 < tmp2 - point)
				tmp1 = tmp2 - point;
			x--;
		}
		y--;
	}
	return (tmp1 + z_para_max(stock));
}

void	ft_create_window(t_case *stock)
{
	int		x;
	int		y;
	int		z;

	if (stock->iso == 1)
	{
		x = stock->width / 2 * 50 + 100 + 50 * (stock->height / 2);
		y = stock->height / 2 * 25 + 100 + ((stock->width / 2) * 25);
		z = z_iso(stock);
		z_para_iso(stock);
	}
	else
	{
		x = 60 + (stock->width - 1) * 30 + 30 * (stock->height - 1);
		y = 60 + (stock->height - 1) * 15 + 15 * (stock->width - 1);
		z = z_para(stock);
	}
	if (((stock->mlx = mlx_init()) == NULL) || ((stock->win =
	mlx_new_window(stock->mlx, x, y + z, "Fdf")) == NULL))
	{
		ft_putstr("Error : create new window.\n");
		exit(0);
	}
	image(stock, x, y + z);
}
