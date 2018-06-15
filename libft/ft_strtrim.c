/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:26:56 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/11 15:08:29 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
		j--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		j--;
	if (j < 0)
		j = 0;
	str = (char*)malloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (NULL);
	s += i;
	i = -1;
	while (++i < j)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
