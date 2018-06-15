/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:47:53 by lufranco          #+#    #+#             */
/*   Updated: 2018/03/12 18:01:00 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pixel(int x, int y, double evo, t_case *stock)
{
	int alt;
	int alt_to;

	alt = stock->alt;
	alt_to = stock->alt_to;
	color_hub(alt, alt_to, evo, stock);
	fill_pixel(stock, x, y, stock->color);
}

void	draw_v(t_case *stock)
{
	int		tmp;
	double		tmp_d;

	tmp_d = 0;
	if (stock->y1 < stock->y2)
	{
		tmp = stock->y1;
		while (tmp != stock->y2)
		{
			pixel(stock->x1, tmp, 1 - tmp_d, stock);
			tmp++;
			tmp_d = tmp - stock->y1;
			tmp_d /= stock->y2 - stock->y1;
		}
	}
	else
	{
		tmp = stock->y1;
		while (tmp != stock->y2)
		{
			pixel(stock->x1, tmp, 1 - tmp_d, stock);
			tmp--;
			tmp_d = stock->y1 - tmp;
			tmp_d /= stock->y1 - stock->y2;
		}
	}
}

void	draw1(t_case *stock)
{
	double	tmp_d;
	int		tmp_x;

	if (stock->x1 > stock->x2)
	{
		tmp_x = stock->x1;
		stock->x1 = stock->x2;
		stock->x2 = tmp_x;
		tmp_x = stock->y1;
		stock->y1 = stock->y2;
		stock->y2 = tmp_x;
		tmp_x = stock->alt;
		stock->alt = stock->alt_to;
		stock->alt_to = tmp_x;
	}
	tmp_d = 0;
	tmp_x = stock->x1;
	while (tmp_x <= stock->x2)
	{
		pixel(tmp_x, stock->y1 + tmp_d * (stock->y2 - stock->y1), tmp_d, stock);
		tmp_x++;
		tmp_d = tmp_x - stock->x1;
		tmp_d /= stock->x2 - stock->x1;
	}
}

void	draw2(t_case *stock)
{
	double	tmp_d;
	int		tmp_y;

	if (stock->y1 > stock->y2)
	{
		tmp_y = stock->x1;
		stock->x1 = stock->x2;
		stock->x2 = tmp_y;
		tmp_y = stock->y1;
		stock->y1 = stock->y2;
		stock->y2 = tmp_y;
		tmp_y = stock->alt;
		stock->alt = stock->alt_to;
		stock->alt_to = tmp_y;
	}
	tmp_d = 0;
	tmp_y = stock->y1;
	while (tmp_y <= stock->y2)
	{
		pixel(stock->x1 + tmp_d * (stock->x2 - stock->x1), tmp_y, tmp_d, stock);
		tmp_y++;
		tmp_d = tmp_y - stock->y1;
		tmp_d /= stock->y2 - stock->y1;
	}
}

void	draw_hub(t_case *stock, int alt, int alt_to)
{
	int diff_x;
	int diff_y;

	stock->alt = alt;
	stock->alt_to = alt_to;
	diff_x = stock->x2 - stock->x1;
	if (diff_x < 0)
		diff_x = -diff_x;
	diff_y = stock->y2 - stock->y1;
	if (diff_y < 0)
		diff_y = -diff_y;
	if (stock->x1 == stock->x2)
		draw_v(stock);
	else if (diff_x > diff_y)
		draw1(stock);
	else
		draw2(stock);
}
