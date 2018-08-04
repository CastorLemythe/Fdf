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

void	z_para_iso(t_case *stk)
{
	stk->h = 15;
	stk->w = 30;
	z_para_max(stk);
	stk->h = 25;
	stk->w = 50;
}

void	other_point_para_2(t_case *stk, int y, int x)
{
    if (x + 1 < stk->width)
    {
        stk->x1 = stk->x1 + stk->w;
        stk->y1 = stk->y + stk->h + stk->h * x +
			stk->h * y - stk->w * stk->map[y][x + 1];
    }
	else if (y + 1 < stk->height)
    {
        stk->x1 = stk->x - stk->w * (y + 1);
        stk->y1 = stk->y + stk->h * (y + 1) -
			stk->w * stk->map[y + 1][0];
    }
}

void    other_point_para(t_case *stk, int y, int x)
{
    if (x + 1 < stk->width)
    {
        stk->x2 = stk->x1 + stk->w;
        stk->y2 = stk->y + stk->h + stk->h * x + stk->h * y
			- stk->w * stk->map[y][x + 1];
        draw_hub(stk, stk->map[y][x], stk->map[y][x + 1]);
	if (stk->x1 > stk->x2)
	{
		stk->x1 = stk->x2;
		stk->y1 = stk->y2;
	}
    }
    if (y + 1 < stk->height)
    {
        stk->x2 = stk->x1 - stk->w;
        stk->y2 = stk->y + stk->h + stk->h * x + stk->h * y
			- stk->w * stk->map[y + 1][x];
        draw_hub(stk, stk->map[y][x], stk->map[y + 1][x]);
	if (stk->x1 < stk->x2)
		stk->x1 = stk->x2;
    }
    other_point_para_2(stk, y, x);
}

void    first_point_para(t_case *stk)
{
    stk->x = stk->w + stk->w * (stk->height - 1) + stk->move_x;
    stk->y = stk->w + stk->z_para + stk->move_y;
	stk->x1 = stk->x;
	stk->y1 = stk->y - stk->map[0][0] * stk->w;
}

void	ft_display_para(t_case *stk, int x, int y)
{
	first_point_para(stk);

	while (y < stk->height)
	{
		while (x < stk->width)
		{
			other_point_para(stk, y, x);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(stk, stk->win, stk->ptr_ima, 0, 0);
}
