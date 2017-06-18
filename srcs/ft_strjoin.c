#include "../includes/gacp.h"

static void		ft_init(t_gacp	*gacp)
{
	int 	k;

	k = -1;
	gacp->length = 0;
	gacp->first = "git commit -m";
	while (++k < 6)
		gacp->length_time[k] = ft_strlen(gacp->time[k]);
	k = -1;
	while (++k < 6)
		gacp->length += gacp->length_time[k];
	gacp->length += 6;
	gacp->i = 0;
	gacp->j = 0;
}

char			*ft_strjoin(t_gacp	*gacp)
{
	int 	k;

	k = 0;
	ft_init(gacp);
	gacp->str = ft_strnew(sizeof(char) * ( gacp->length));
	if (gacp->str == NULL)
		exit(0);
	while (k < 6)
	{
		while (gacp->i < gacp->length_time[k])
			gacp->str[gacp->j++] = gacp->time[k][gacp->i++];
		if (k < 2)
			gacp->str[gacp->j++] = '/';
		else if (k == 2)
			gacp->str[gacp->j++] = '-';
		else if (k < 5)
			gacp->str[gacp->j++] = ':';
		else
			gacp->str[gacp->j++] = '\0';
		gacp->i = 0;
		k++;
	}
	return (gacp->str);
}
