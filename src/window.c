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

int	z_iso_max(t_case *stk)
{
	int x;
	int y;
	int tmp1;
	int tmp2;

	y = 0;
	tmp1 = 0;
	while (y < stk->height)
	{
		x = 0;
		while (x < stk->width)
		{
			tmp2 = 50 + 25 * (x / 2) + 25 * (y / 2);
			if (tmp2 - stk->map[y][x] * 50 < 50)
				tmp2 = 50 - (tmp2 - stk->map[y][x] * 50);
			else
				tmp2 = 0;
			if (tmp1 < tmp2)
				tmp1 = tmp2;
			x += 2;
		}
		y += 2;
	}
	stk->z_iso = tmp1;
	return (tmp1);
}

int	z_iso(t_case *stk)
{
	int x;
	int y;
	int tmp1;
	int tmp2;
	int point;

	y = stk->height;
	tmp1 = 0;
	point = 50 + 25 * (stk->height / 2) + 25 * (stk->width / 2);
	while (y > 0)
	{
		x = stk->width;
		while (x > 0)
		{
			tmp2 = 50 + 25 * (y / 2)  + 25 * (x / 2) - 50 *
				stk->map[y - 1][x - 1];
			if (tmp1 < tmp2 - point)
				tmp1 = tmp2 - point;
			x -= 2;
		}
		y -= 2;
	}
	return (tmp1 + z_iso_max(stk));
}

int     z_para_max(t_case *stk)
{
	int x;
	int y;
	int tmp1;
	int tmp2;

	y = -1;
	tmp1 = 0;
	while (++y < stk->height)
	{
		x = 0;
		while (x < stk->width)
		{
			tmp2 = 30 + 15 * y + 15 * x;
			if (tmp2 - stk->map[y][x] * 30 < 30)
				tmp2 = 30 - (tmp2 - stk->map[y][x] * 30);
			else
				tmp2 = 0;
			if (tmp1 < tmp2)
				tmp1 = tmp2;
			x++;
		}
	}
	stk->z_para = tmp1;
	return (tmp1);
}

int	z_para(t_case *stk)
{
	int x;
	int y;
	int tmp1;
	int tmp2;
	int point;

	y = stk->height;
	tmp1 = 0;
	point = 30 + 15 * stk->height + 15 * stk->width;
	while (y > 0)
	{
		x = stk->width;
		while (x > 0)
		{
			tmp2 = 30 + 15 * y + 15 * x - 30 *
				stk->map[y - 1][x - 1];
			if (tmp1 < tmp2 - point)
				tmp1 = tmp2 - point;
			x--;
		}
		y--;
	}
	return (tmp1 + z_para_max(stk));
}

void	ft_create_window(t_case *stk)
{
	int		x;
	int		y;
	int		z;

	if (stk->iso == 1)
	{
		x = stk->width / 2 * 50 + 100 + 50 * (stk->height / 2);
		y = stk->height / 2 * 25 + 100 + ((stk->width / 2) * 25);
		z = z_iso(stk);
		z_para_iso(stk);
	}
	else
	{
		x = 60 + (stk->width - 1) * 30 + 30 * (stk->height - 1);
		y = 60 + (stk->height - 1) * 15 + 15 * (stk->width - 1);
		z = z_para(stk);
	}
	if (((stk->mlx = mlx_init()) == NULL) || ((stk->win =
	mlx_new_window(stk->mlx, x, y + z, "Fdf")) == NULL))
	{
		ft_putstr("Error : create new window.\n");
		exit(0);
	}
	image(stk, x, y + z);
}
