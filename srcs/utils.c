#include "../includes/gacp.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

char	*ft_strnew(size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	size++;
	if (!(tmp = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}