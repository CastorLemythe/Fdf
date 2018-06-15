#include "../includes/fdf.h"

void	color_up(int alt, int alt_to, double evo, t_case *stock)
{
	if (alt >= 0)
	{
		evo *= alt_to * stock->max - alt * stock->max;
		stock->color = 0xffffff - 0x000101 * (alt * stock->max + (int)evo);
	}
	else if (alt_to <= 0)
	{
		evo *= alt_to * stock->min - alt * stock->min;
		stock->color = 0xffffff - 0x010100 * (-alt * stock->min - (int)evo);
	}
	else
	{
		if (evo * (alt_to - alt) + alt < 0)
		{
			evo = (alt_to - alt) * evo / -alt * stock->min;
			stock->color = 0xffffff - 0x010100 * (-alt * stock->min
			- (int)evo);
		}
		else
		{
			evo = ((alt_to - alt) * evo + alt) * stock->max;
			stock->color = 0xffffff - 0x000101 * (int)evo;
		}
	}
}

void	color_down(int alt, int alt_to, double evo, t_case *stock)
{
	if (alt <= 0)
	{
		evo *= alt * stock->min - alt_to * stock->min;
		stock->color = 0xffffff - 0x010100 * (-alt * stock->min + (int)evo);
	}
	else if (alt_to >= 0)
	{
		evo *= alt * stock->max - alt_to * stock->max;
		stock->color = 0xffffff - 0x000101 * (alt * stock->max - (int)evo);
	}
	else
	{
		if (alt - evo * (alt - alt_to) > 0)
		{
			evo = (alt - alt_to) * evo * stock->max;
			stock->color = 0xffffff - 0x000101 * (alt * stock->max
			- (int)evo);
		}
		else
		{
			evo = -(alt - (alt - alt_to) * evo) * stock->min;
			stock->color = 0xffffff - 0x010100 * (int)evo;
		}
	}
}

void	color_hub(int alt, int alt_to, double evo, t_case *stock)
{
	if (alt == alt_to)
	{
		if (alt >= 0)
			stock->color = 0xffffff - 0x000101 * (alt * stock->max);
		else
			stock->color = 0xffffff - 0x010100 * (-alt * stock->min);
	}
	else if (alt < alt_to)
		color_up(alt, alt_to, evo, stock);
	else if (alt > alt_to)
		color_down(alt, alt_to, evo, stock);
}

void	min_max(t_case *stock)
{
	int x;
	int y;

	stock->min = 0;
	stock->max = 0;
	stock->color = 0xffffff;
	y = 0;
	while (y < stock->height)
	{
		x = 0;
		while (x < stock->width)
		{
			if (stock->map[y][x] < stock->min)
				stock->min = stock->map[y][x];
			if (stock->map[y][x] > stock->max)
				stock->max = stock->map[y][x];
			x++;
		}
		y++;
	}
	stock->min = -(stock->min);
	if (stock->max != 0)
		stock->max = 255 / stock->max;
	if (stock->min != 0)
		stock->min = 255 / stock->min;
}
