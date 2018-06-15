/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:01:27 by lufranco          #+#    #+#             */
/*   Updated: 2018/02/13 09:08:35 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_print_commands(t_case *stock)
{
	mlx_string_put(stock->mlx, stock->win, 0, 0, 0x00ff00,
	"S : switch project.\n");
	mlx_string_put(stock->mlx, stock->win, 0, 14, 0x00ff00,
	"< : moove left.\n");
	mlx_string_put(stock->mlx, stock->win, 0, 28, 0x00ff00,
	"> : moove right.\n");
	mlx_string_put(stock->mlx, stock->win, 0, 42, 0x00ff00,
	"^ : moove up.\n");
	mlx_string_put(stock->mlx, stock->win, 0, 56, 0x00ff00,
	"v : moove down.\n");
	mlx_string_put(stock->mlx, stock->win, 0, 70, 0x00ff00,
	"+ : zoom.\n");
	mlx_string_put(stock->mlx, stock->win, 0, 84, 0x00ff00,
	"- : dezoom.\n");
	mlx_string_put(stock->mlx, stock->win, 0, 112, 0x00ff00,
	"Space : start/reset.\n");
	mlx_string_put(stock->mlx, stock->win, 0, 127, 0x00ff00,
	"Esc : quit.\n");
}
