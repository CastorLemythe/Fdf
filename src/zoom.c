#include "../includes/fdf.h"

void	zoom_1(t_case *stk)
{
	stk->h = 15;
	stk->w = 30;
}

void	zoom_2(t_case *stk)
{
	stk->h = 25;
	stk->w = 50;
}

void	zoom_3(t_case *stk)
{
	stk->h = 35;
	stk->w = 70;
}

void	zoom_4(t_case *stk)
{
	stk->h = 45;
	stk->w = 90;
}

void	zoom(int key, t_case *stk)
{
	if (key == 45) // 69 == + 78 == -
	{
		if (stk->h == 25)
			zoom_3(stk);
		else if (stk->h == 35)
			zoom_4(stk);
		else if (stk->h == 15)
			zoom_2(stk);
	}
	else if (key == 46)
	{
		if (stk->h == 25)
			zoom_1(stk);
		else if (stk->h == 35)
			zoom_2(stk);
		else if (stk->h == 45)
			zoom_3(stk);
	}
	else if ((key == 1 || key == 49) && stk->projection == 0)
		zoom_1(stk);
	else
		zoom_2(stk);
}
