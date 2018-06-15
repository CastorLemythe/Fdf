#include "../includes/fdf.h"

void	image(t_case *stock, int x, int y)
{
	int bpp;
	int s_l;
	int endian;

	stock->ptr_ima = mlx_new_image(stock->mlx, x, y);
	stock->str_ima = mlx_get_data_addr(stock->ptr_ima, &(bpp), &(s_l), &(endian));
	stock->x_ima = x;
	stock->y_ima = y;
}

void	fill_pixel(t_case *stock, int x, int y, int color)
{
	unsigned int	blue;
	unsigned int	green;
	unsigned int	red;
	int		coord;

	blue = (color & 0xff);
	green = (color & 0xff00) >> 8;
	red = (color & 0xff0000) >> 16;
	if (x >= 0 && x <= stock->x_ima && y >= 0 && y <= stock->y_ima)
	{
		coord = (4 * stock->x_ima * y) + 4 * x;
		stock->str_ima[coord] = blue;
		coord++;
		stock->str_ima[coord] = green;
		coord++;
		stock->str_ima[coord] = red;
	}
}
