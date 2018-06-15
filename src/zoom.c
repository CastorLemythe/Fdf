#include "../includes/fdf.h"

void	zoom_1(t_case *stock)
{
	stock->h = 15;
	stock->w = 30;
}

void	zoom_2(t_case *stock)
{
	stock->h = 25;
	stock->w = 50;
}

void	zoom_3(t_case *stock)
{
	stock->h = 35;
	stock->w = 70;
}

void	zoom_4(t_case *stock)
{
	stock->h = 45;
	stock->w = 90;
}

void	zoom(int key, t_case *stock)
{
	if (key == 45) // 69 == + 78 == -
	{
		if (stock->h == 25)
			zoom_3(stock);
		else if (stock->h == 35)
			zoom_4(stock);
		else if (stock->h == 15)
			zoom_2(stock);
	}
	else if (key == 46)
	{
		if (stock->h == 25)
			zoom_1(stock);
		else if (stock->h == 35)
			zoom_2(stock);
		else if (stock->h == 45)
			zoom_3(stock);
	}
	else if ((key == 1 || key == 49) && stock->projection == 0)
		zoom_1(stock);
	else
		zoom_2(stock);
}
