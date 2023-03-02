
#include "../include/libft.h"

int	ft_instr(char const *str, char c, int l)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	if (l)
		return (i);
	return (0);
}

