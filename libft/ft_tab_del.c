#include "libft.h"

void	ft_tab_del(int **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
}
