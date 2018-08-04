/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:36:06 by lufranco          #+#    #+#             */
/*   Updated: 2018/03/12 17:25:18 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	other_point(int x, int y, t_case *stk)
{
	x = x - x / 2;
	y = y - y / 2;
	stk->x1 = (stk->x + (stk->w * x)) - (y * stk->w);
	stk->y1 = (stk->y + (stk->h * y)) + (x * stk->h);
}

void	first_point(t_case *stk)
{
	stk->x = stk->w + (stk->height / 2 * stk->w) + stk->move_x;
	stk->y = stk->w + stk->z_iso + stk->move_y;
	stk->x1 = stk->x;
	stk->y1 = stk->y;
}

void	ft_z(int z, int tmp_x, int tmp_y, t_case *stk)
{
	stk->y2 = stk->y1;
	stk->x2 = stk->x1;
	stk->y1 = stk->y1 - z;
	draw_hub(stk, 0, z / stk->w);
	tmp_x = stk->x1;
	tmp_y = stk->y1;
	ft_draw_square(stk, z / stk->w);
	stk->x1 = tmp_x;
	stk->y1 = tmp_y;
	stk->x1 = stk->x1 + stk->w;
	stk->x2 = stk->x1;
	stk->y1 += stk->h;
	stk->y2 = stk->y1 + z;
	draw_hub(stk, 0, z / stk->w);
	stk->x1 = stk->x1 - stk->w;
	stk->x2 = stk->x1;
	stk->y1 += stk->h;
	stk->y2 += stk->h;
	draw_hub(stk, 0, z / stk->w);
	stk->x1 = stk->x1 - stk->w;
	stk->x2 = stk->x1;
	stk->y1 -= stk->h;
	stk->y2 -= stk->h;
	draw_hub(stk, 0, z / stk->w);
}

void	ft_draw_square(t_case *stk, int alt)
{
	stk->x2 = stk->x1 + stk->w;
	stk->y2 = stk->y1 + stk->h;
	draw_hub(stk, alt, alt);
	stk->x2 = stk->x1 - stk->w;
	stk->y2 = stk->y1 + stk->h;
	draw_hub(stk, alt, alt);
	stk->x2 = stk->x1 + stk->w;
	stk->y2 = stk->y1 + stk->h;
	draw_hub(stk, alt, alt);
	stk->x1 = stk->x2 + stk->w;
	stk->y1 = stk->y2 - stk->h;
	draw_hub(stk, alt, alt);
}

void	ft_display_iso(t_case *stk, int x, int y)
{
	int		tmp_x;
	int		tmp_y;

	first_point(stk);
	while (y < stk->height)
	{
		x = 0;
		while (x < stk->width)
		{
			if (x || y)
				other_point(x, y, stk);
			if (stk->map[y][x] != 0)
			{
				tmp_x = stk->x1;
				tmp_y = stk->y1;
				ft_z(stk->map[y][x] * stk->w, 0, 0, stk);
				stk->x1 = tmp_x;
				stk->y1 = tmp_y;
			}
			ft_draw_square(stk, 0);
			x += 2;
		}
		y += 2;
	}
	mlx_put_image_to_window(stk, stk->win, stk->ptr_ima, 0, 0);
}
