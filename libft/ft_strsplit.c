/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:56:20 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/11 12:27:23 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length(char const *str, char c, int i)
{
	int j;

	j = 0;
	while (str[i + j] != c && str[i + j] != '\0')
		j++;
	return (j);
}

static int		ft_count_word(char const *str, char c)
{
	int nbr_word;
	int i;

	i = 0;
	nbr_word = 0;
	while (str[i])
	{
		if ((str[i] != c) && (str[i + 1] == c || str[i + 1] == '\0'))
			nbr_word++;
		i++;
	}
	return (nbr_word);
}

static char		*ft_copy_word(char *dest, char const *s, char c, int *i)
{
	int j;

	j = 0;
	while (s[*i] == c)
		*i += 1;
	dest = (char*)malloc(sizeof(char) * (ft_length(s, c, *i) + 1));
	if (dest == NULL)
		return (NULL);
	while (s[*i] != c && s[*i] != '\0')
	{
		dest[j] = s[*i];
		*i += 1;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		nbr_word;
	int		word;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	word = 0;
	nbr_word = ft_count_word(s, c);
	dest = (char**)malloc(sizeof(char*) * (nbr_word + 1));
	if (dest == NULL)
		return (NULL);
	while (word < nbr_word)
	{
		dest[word] = ft_copy_word(dest[word], s, c, &i);
		word++;
	}
	dest[nbr_word] = 0;
	return (dest);
}
