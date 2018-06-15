/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 18:27:29 by lufranco          #+#    #+#             */
/*   Updated: 2018/03/12 18:49:12 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_my_atoi(char *tab, int *i)
{
	int nb;
	int n;

	n = 0;
	nb = 0;
	if (tab[*i] == '-')
	{
		*i = *i + 1;
		n++;
	}
	while (tab[*i] > 47 && tab[*i] < 58)
	{
		nb = nb * 10 + (tab[*i] - '0');
		*i = *i + 1;
	}
	if (n == 1)
		return (-nb);
	return (nb);
}

int		**ft_tab_atoi(char **dest, int **map)
{
	int x1;
	int	y1;
	int x2;
	int	y2;

	y1 = -1;
	y2 = 0;
	while (dest[++y1])
	{
		x1 = 0;
		x2 = 0;
		while (dest[y1][x1] != '\0')
		{
			if ((dest[y1][x1] >= '0' && dest[y1][x1] <= '9')
					|| (dest[y1][x1] == '-'))
			{
				map[y2][x2] = ft_my_atoi(dest[y1], &x1);
				x2++;
			}
			x1++;
		}
		y2++;
	}
	return (map);
}
