#include "../includes/fdf.h"

void	color_up(int alt, int alt_to, double evo, t_case *stk)
{
	if (alt >= 0)
	{
		evo *= alt_to * stk->max - alt * stk->max;
		stk->color = 0xffffff - 0x000101 * (alt * stk->max + (int)evo);
	}
	else if (alt_to <= 0)
	{
		evo *= alt_to * stk->min - alt * stk->min;
		stk->color = 0xffffff - 0x010100 * (-alt * stk->min - (int)evo);
	}
	else
	{
		if (evo * (alt_to - alt) + alt < 0)
		{
			evo = (alt_to - alt) * evo / -alt * stk->min;
			stk->color = 0xffffff - 0x010100 * (-alt * stk->min
								- (int)evo);
		}
		else
		{
			evo = ((alt_to - alt) * evo + alt) * stk->max;
			stk->color = 0xffffff - 0x000101 * (int)evo;
		}
	}
}

void	color_down(int alt, int alt_to, double evo, t_case *stk)
{
	if (alt <= 0)
	{
		evo *= alt * stk->min - alt_to * stk->min;
		stk->color = 0xffffff - 0x010100 * (-alt * stk->min + (int)evo);
	}
	else if (alt_to >= 0)
	{
		evo *= alt * stk->max - alt_to * stk->max;
		stk->color = 0xffffff - 0x000101 * (alt * stk->max - (int)evo);
	}
	else
	{
		if (alt - evo * (alt - alt_to) > 0)
		{
			evo = (alt - alt_to) * evo * stk->max;
			stk->color = 0xffffff - 0x000101 * (alt * stk->max - (int)evo);
		}
		else
		{
			evo = -(alt - (alt - alt_to) * evo) * stk->min;
			stk->color = 0xffffff - 0x010100 * (int)evo;
		}
	}
}

void	color_hub(int alt, int alt_to, double evo, t_case *stk)
{
	if (alt == alt_to)
	{
		if (alt >= 0)
			stk->color = 0xffffff - 0x000101 * (alt * stk->max);
		else
			stk->color = 0xffffff - 0x010100 * (-alt * stk->min);
	}
	else if (alt < alt_to)
		color_up(alt, alt_to, evo, stk);
	else if (alt > alt_to)
		color_down(alt, alt_to, evo, stk);
}

void	min_max(t_case *stk)
{
	int x;
	int y;

	stk->min = 0;
	stk->max = 0;
	stk->color = 0xffffff;
	y = 0;
	while (y < stk->height)
	{
		x = 0;
		while (x < stk->width)
		{
			if (stk->map[y][x] < stk->min)
				stk->min = stk->map[y][x];
			if (stk->map[y][x] > stk->max)
				stk->max = stk->map[y][x];
			x++;
		}
		y++;
	}
	stk->min = -(stk->min);
	if (stk->max != 0)
		stk->max = 255 / stk->max;
	if (stk->min != 0)
		stk->min = 255 / stk->min;
}
