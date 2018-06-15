/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:36:06 by lufranco          #+#    #+#             */
/*   Updated: 2018/03/12 17:stock->h:18 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	other_point(int x, int y, t_case *stock)
{
	x = x - x / 2;
	y = y - y / 2;
	stock->x1 = (stock->x + (stock->w * x)) - (y * stock->w);
	stock->y1 = (stock->y + (stock->h * y)) + (x * stock->h);
}

void	first_point(t_case *stock)
{
	stock->x = stock->w + (stock->height / 2 * stock->w) + stock->move_x;
	stock->y = stock->w + stock->z_iso + stock->move_y;
	stock->x1 = stock->x;
	stock->y1 = stock->y;
}

void	ft_z(int z, int tmp_x, int tmp_y, t_case *stock)
{
	stock->y2 = stock->y1;
	stock->x2 = stock->x1;
	stock->y1 = stock->y1 - z;
	draw_hub(stock, 0, z / stock->w);
	tmp_x = stock->x1;
	tmp_y = stock->y1;
	ft_draw_square(stock, z / stock->w);
	stock->x1 = tmp_x;
	stock->y1 = tmp_y;
	stock->x1 = stock->x1 + stock->w;
	stock->x2 = stock->x1;
	stock->y1 += stock->h;
	stock->y2 = stock->y1 + z;
	draw_hub(stock, 0, z / stock->w);
	stock->x1 = stock->x1 - stock->w;
	stock->x2 = stock->x1;
	stock->y1 += stock->h;
	stock->y2 += stock->h;
	draw_hub(stock, 0, z / stock->w);
	stock->x1 = stock->x1 - stock->w;
	stock->x2 = stock->x1;
	stock->y1 -= stock->h;
	stock->y2 -= stock->h;
	draw_hub(stock, 0, z / stock->w);
}

void	ft_draw_square(t_case *stock, int alt)
{
	stock->x2 = stock->x1 + stock->w;
	stock->y2 = stock->y1 + stock->h;
	draw_hub(stock, alt, alt);
	stock->x2 = stock->x1 - stock->w;
	stock->y2 = stock->y1 + stock->h;
	draw_hub(stock, alt, alt);
	stock->x2 = stock->x1 + stock->w;
	stock->y2 = stock->y1 + stock->h;
	draw_hub(stock, alt, alt);
	stock->x1 = stock->x2 + stock->w;
	stock->y1 = stock->y2 - stock->h;
	draw_hub(stock, alt, alt);
}

void	ft_display_iso(t_case *stock, int x, int y)
{
	int		tmp_x;
	int		tmp_y;

	first_point(stock);
	while (y < stock->height)
	{
		x = 0;
		while (x < stock->width)
		{
			if (x || y)
				other_point(x, y, stock);
			if (stock->map[y][x] != 0)
			{
				tmp_x = stock->x1;
				tmp_y = stock->y1;
				ft_z(stock->map[y][x] * stock->w, 0, 0, stock);
				stock->x1 = tmp_x;
				stock->y1 = tmp_y;
			}
			ft_draw_square(stock, 0);
			x += 2;
		}
		y += 2;
	}
	mlx_put_image_to_window(stock, stock->win, stock->ptr_ima, 0, 0);
}
