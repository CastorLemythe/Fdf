/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:46:52 by lufranco          #+#    #+#             */
/*   Updated: 2018/03/12 18:49:06 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_check_iso(int **map, int height, int width)
{
	int	x;
	int	y;

	if (height % 2 == 1 || width % 2 == 1)
		return (1);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] != map[y][x + 1] || map[y][x] !=
			map[y + 1][x] || map[y][x] != map[y + 1][x + 1])
				return (1);
			x += 2;
		}
		y += 2;
	}
	return (0);
}

int		ft_count(char **dest, t_case *stock)
{
	int		x;
	int		y;
	int		count;

	y = -1;
	while (dest[++y])
	{
		count = 0;
		x = 0;
		while (dest[y][x] != '\0')
		{
			if (dest[y][x] >= '0' && dest[y][x] <= '9')
				count++;
			while (dest[y][x] >= '0' && dest[y][x] <= '9'
					&& dest[y][x] != '\0')
				x++;
			if (dest[y][x] != '\0')
				x++;
		}
		if (y == 0)
			stock->width = count;
		if (count != stock->width)
			return (1);
	}
	return (0);
}

int		ft_check_char(char *dest)
{
	int x;

	x = 0;
	while (dest[x])
	{
		if (dest[x] < '0' || dest[x] > '9')
		{
			if (dest[x] == '-' || dest[x] == '+')
			{
				x++;
				if (dest[x] < '0' || dest[x] > '9')
					return (1);
			}
			else if (dest[x] != ' ' && dest[x] != '	')
				return (1);
		}
		x++;
	}
	return (0);
}

char	**ft_get_tab(char **dest, char *file, int fd, t_case *stock)
{
	char	*line;
	int		y;

	y = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_check_char(line))
		{
			free(line);
			return (NULL);
		}
		free(line);
		y++;
	}
	stock->height = y;
	if (!(dest = (char**)malloc(sizeof(*dest) * (y + 1))))
		return (NULL);
	close(fd);
	fd = open(file, O_RDONLY);
	dest[y] = 0;
	y = 0;
	while (get_next_line(fd, &line))
		dest[y++] = line;
	close(fd);
	return (dest);
}

char	**ft_parsing(char **dest, char *file, t_case *stock)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	if (!(dest = ft_get_tab(dest, file, fd, stock)))
		return (NULL);
	if (stock->height == 0)
		return (NULL);
	if (ft_count(dest, stock))
		return (NULL);
	if (stock->width == 0)
		return (NULL);
	return (dest);
}
