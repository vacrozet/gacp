#include "../includes/gacp.h"

int		ft_count_word(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 33 && str[i] <= 126) && (str[i + 1] == ' '
					|| str[i + 1] == '\n' || str[i + 1] == '\t'
					|| str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

int 	ft_count_alnum(char *str)
{
	int		i;
	int		count;

	count = 0 ;
	i = 0;

	while(str[i] != '\0')
	{
		if (str[i] < 127 && str[i] >= 33)
			count++;
		i++;
	}
	return count;
}

void ft_expand_str(char *str, t_gacp *gacp)
{
	int 	i;
	int		nb_space;
	int		nb_caract;
	int		j;

	j = 0;
	i = -1;
	nb_space =  ft_count_word(str) - 1;
	nb_caract = ft_count_alnum(str);
	gacp->expand = ft_strnew(sizeof(char) * (nb_space + nb_caract + 1));
	while (*str != '\0')
	{
		while (*str == '\t' || *str == ' ')
			str++;
		if (i != -1 && *str != '\0')
			gacp->expand[j++] = ' ';
		i = 0;
		while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
			gacp->expand[j++] = str[i++];
		str += i;
	}
	gacp->expand[j++] = '\0';
	gacp->length = ft_strlen(gacp->expand) + gacp->length_date + 17;
}
