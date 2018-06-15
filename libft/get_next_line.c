/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:19:42 by lufranco          #+#    #+#             */
/*   Updated: 2018/01/08 12:05:19 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_len(char *test)
{
	unsigned long	i;

	i = 0;
	while (test[i] != '\n' && test[i] != '\0')
		i++;
	return (i);
}

char			*ft_stock_before(char **str)
{
	char	*tmp;
	char	*cpy;

	cpy = ft_strdup(*str);
	ft_strdel(str);
	tmp = ft_strsub(ft_strchr(cpy, '\n'), 1, ft_strlen(cpy) - 1);
	*str = ft_strsub(cpy, 0, ft_len(cpy));
	ft_strdel(&cpy);
	return (tmp);
}

char			*ft_stock_after(char **str, char *buff, int i)
{
	char	*stock;
	char	*tmp;

	if (i == 0 && *str[0] == '\0')
	{
		ft_strdel(str);
		return (NULL);
	}
	buff[i] = '\0';
	tmp = ft_strsub(buff, 0, ft_len(buff));
	stock = ft_strjoin(*str, tmp);
	ft_strdel(str);
	ft_strdel(&tmp);
	*str = ft_strdup(stock);
	ft_strdel(&stock);
	stock = ft_strsub(ft_strchr(buff, '\n'), 1, ft_strlen(buff) - 1);
	return (stock);
}

char			*ft_core(char *tmp, int fd, char *buff, int i)
{
	static char *stock[OPEN_MAX];

	if (stock[fd])
	{
		tmp = ft_strdup(stock[fd]);
		ft_strdel(&stock[fd]);
		if (ft_strchr(tmp, '\n') != NULL)
		{
			stock[fd] = ft_stock_before(&tmp);
			return (tmp);
		}
	}
	else
		tmp = ft_strnew(0);
	while ((i = read(fd, buff, BUFF_SIZE)) && ft_strchr(buff, '\n') == NULL)
	{
		buff[i] = '\0';
		stock[fd] = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
		tmp = ft_strdup(stock[fd]);
		ft_strdel(&stock[fd]);
	}
	stock[fd] = ft_stock_after(&tmp, buff, i);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	int		i;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	tmp = NULL;
	i = 0;
	if (line == NULL || fd < 0 || fd > OPEN_MAX || read(fd, buff, 0) == -1)
		return (-1);
	*line = ft_core(tmp, fd, buff, i);
	if (*line == NULL)
	{
		*line = ft_strnew(0);
		return (0);
	}
	return (1);
}
