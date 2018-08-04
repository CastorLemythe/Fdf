#include "../includes/fdf.h"

void	image(t_case *stk, int x, int y)
{
	int bpp;
	int s_l;
	int endian;

	stk->ptr_ima = mlx_new_image(stk->mlx, x, y);
	stk->str_ima = mlx_get_data_addr(stk->ptr_ima, &(bpp), &(s_l), &(endian));
	stk->x_ima = x;
	stk->y_ima = y;
}

void	fill_pixel(t_case *stk, int x, int y, int color)
{
	unsigned int	blue;
	unsigned int	green;
	unsigned int	red;
	int				coord;

	blue = (color & 0xff);
	green = (color & 0xff00) >> 8;
	red = (color & 0xff0000) >> 16;
	if (x >= 0 && x <= stk->x_ima && y >= 0 && y <= stk->y_ima)
	{
		coord = (4 * stk->x_ima * y) + 4 * x;
		stk->str_ima[coord] = blue;
		coord++;
		stk->str_ima[coord] = green;
		coord++;
		stk->str_ima[coord] = red;
	}
}
