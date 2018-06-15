/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_para.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:37:38 by lufranco          #+#    #+#             */
/*   Updated: 2018/03/12 18:45:01 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	z_para_iso(t_case *stock)
{
	stock->h = 15;
	stock->w = 30;
	z_para_max(stock);
	stock->h = 25;
	stock->w = 50;
}

void	other_point_para_2(t_case *stock, int y, int x)
{
    if (x + 1 < stock->width)
    {
        stock->x1 = stock->x1 + stock->w;
        stock->y1 = stock->y + stock->h + stock->h * x +
	stock->h * y - stock->w * stock->map[y][x + 1];
    }
	else if (y + 1 < stock->height)
    {
        stock->x1 = stock->x - stock->w * (y + 1);
        stock->y1 = stock->y + stock->h * (y + 1) -
	stock->w * stock->map[y + 1][0];
    }
}

void    other_point_para(t_case *stock, int y, int x)
{
    if (x + 1 < stock->width)
    {
        stock->x2 = stock->x1 + stock->w;
        stock->y2 = stock->y + stock->h + stock->h * x + stock->h * y
	- stock->w * stock->map[y][x + 1];
        draw_hub(stock, stock->map[y][x], stock->map[y][x + 1]);
	if (stock->x1 > stock->x2)
	{
		stock->x1 = stock->x2;
		stock->y1 = stock->y2;
	}
    }
    if (y + 1 < stock->height)
    {
        stock->x2 = stock->x1 - stock->w;
        stock->y2 = stock->y + stock->h + stock->h * x + stock->h * y
	- stock->w * stock->map[y + 1][x];
        draw_hub(stock, stock->map[y][x], stock->map[y + 1][x]);
	if (stock->x1 < stock->x2)
		stock->x1 = stock->x2;
    }
    other_point_para_2(stock, y, x);
}

void    first_point_para(t_case *stock)
{
    stock->x = stock->w + stock->w * (stock->height - 1) + stock->move_x;
    stock->y = stock->w + stock->z_para + stock->move_y;
	stock->x1 = stock->x;
	stock->y1 = stock->y - stock->map[0][0] * stock->w;
}

void	ft_display_para(t_case *stock, int x, int y)
{
	first_point_para(stock);

	while (y < stock->height)
	{
		while (x < stock->width)
		{
			other_point_para(stock, y, x);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(stock, stock->win, stock->ptr_ima, 0, 0);
}
