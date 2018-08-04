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

int		my_key_funct(int keycode, t_case *stock)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 1 && stock->iso == 1)
	{
		stock->projection = (stock->projection == 0) ? 1 : 0;
		keycode = 49;
	}
	if (keycode == 45 || keycode == 46) // 69 == + 78 == -
		zoom(keycode, stock);
	if (keycode == 49)
	{
		stock->move_x = 0;
		stock->move_y = 0;
		zoom(keycode, stock);
	}
	if (keycode == 124 || keycode == 123)
		stock->move_x = (keycode == 124) ?
		(stock->move_x + 4) : (stock->move_x - 4);
	if (keycode == 125 || keycode == 126)
		stock->move_y = (keycode == 125) ?
		(stock->move_y + 4) : (stock->move_y - 4);
	mlx_clear_window(stock->mlx, stock->win);
	ft_choose_display(stock);
	return (0);
}

void	ft_choose_display(t_case *stock)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (stock->projection == 1)
		ft_display_iso(stock, x, y);
	if (stock->projection == 0)
		ft_display_para(stock, x, y);
	ft_bzero(stock->str_ima, stock->x_ima * stock->y_ima * 4);
}

void	ft_mlx_loop(t_case *stock)
{
	if (ft_check_iso(stock->map, stock->height, stock->width))
	{
		stock->iso = 0;
		stock->projection = 0;
	}
	min_max(stock);
	ft_create_window(stock);
	ft_print_commands(stock);
	stock->h = 25;
	stock->w = 50;
	stock->move_x = 0;
	stock->move_y = 0;
	mlx_key_hook(stock->win, my_key_funct, stock);
	mlx_loop(stock->mlx);
	free(stock->map); // free x
	free(stock->str_ima);
}

int		main(int argc, char **argv)
{
	int		i;
	char	**dest;
	t_case	*stock;

	dest = NULL;
	i = -1;
	if (!(stock = (t_case *)malloc(sizeof(t_case))))
		return (-1);
	stock->iso = 1;
	stock->projection = 1;
	if (argc != 2 || (!(dest = ft_parsing(dest, argv[1], stock))))
	{
		ft_putstr("Invalid file.\n");
		return (1);
	}
	stock->map = (int**)malloc(sizeof(stock->map) * (stock->height));
	while (++i < stock->height)
		stock->map[i] = (int*)malloc(sizeof(stock->map) * (stock->width));
	stock->map = ft_tab_atoi(dest, stock->map);
	ft_strdel(dest); // free x
	ft_mlx_loop(stock);
	return (0);
}
