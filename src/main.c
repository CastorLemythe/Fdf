/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:31:05 by lufranco          #+#    #+#             */
/*   Updated: 2018/03/12 18:59:48 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	del_tab_char(char **tab, int h)
{
	int i;

	i = 0;
	while (i <= h)
	{
		ft_strdel(tab);
		i++;
	}
}

int		my_key_funct(int keycode, t_case *stk)
{
	if (keycode == 53)
	{
		ft_tab_del(stk->map, stk->height);
		exit(0);
	}
	if (keycode == 1 && stk->iso == 1)
	{
		stk->projection = (stk->projection == 0) ? 1 : 0;
		keycode = 49;
	}
	if (keycode == 45 || keycode == 46) // 69 == + 78 == -
		zoom(keycode, stk);
	if (keycode == 49)
	{
		stk->move_x = 0;
		stk->move_y = 0;
		zoom(keycode, stk);
	}
	if (keycode == 124 || keycode == 123)
		stk->move_x = (keycode == 124) ? stk->move_x + 4 : stk->move_x - 4;
	if (keycode == 125 || keycode == 126)
		stk->move_y = (keycode == 125) ? stk->move_y + 4 : stk->move_y - 4;
	mlx_clear_window(stk->mlx, stk->win);
	ft_choose_display(stk);
	return (0);
}

void	ft_choose_display(t_case *stk)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (stk->projection == 1)
		ft_display_iso(stk, x, y);
	if (stk->projection == 0)
		ft_display_para(stk, x, y);
	ft_bzero(stk->str_ima, stk->x_ima * stk->y_ima * 4);
}

void	ft_mlx_loop(t_case *stk)
{
	if (ft_check_iso(stk->map, stk->height, stk->width))
	{
		stk->iso = 0;
		stk->projection = 0;
	}
	min_max(stk);
	ft_create_window(stk);
	ft_print_commands(stk);
	stk->h = 25;
	stk->w = 50;
	stk->move_x = 0;
	stk->move_y = 0;
	mlx_key_hook(stk->win, my_key_funct, stk);
	mlx_loop(stk->mlx);
	free(stk->str_ima);
}

int		main(int argc, char **argv)
{
	int		i;
	char	**dest;
	t_case	stk;

	dest = NULL;
	i = -1;
	stk.iso = 1;
	stk.projection = 1;
	if (argc != 2 || (!(dest = ft_parsing(dest, argv[1], &stk))))
	{
		ft_putstr("Invalid file.\n");
		return (1);
	}
	stk.map = (int**)malloc(sizeof(stk.map) * (stk.height));
	while (++i < stk.height)
		stk.map[i] = (int*)malloc(sizeof(stk.map) * (stk.width));
	stk.map = ft_tab_atoi(dest, stk.map);
	del_tab_char(dest, stk.height);
	ft_mlx_loop(&stk);
	return (0);
}
