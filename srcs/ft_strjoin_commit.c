#include "../includes/gacp.h"

static void		option_1(t_gacp *gacp)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;	
	gacp->finish = ft_strnew(sizeof(char) * (gacp->length_date + 17));
	while (i < ft_strlen(gacp->first))
		gacp->finish[i++] = gacp->first[j++];
	j = 0;
	gacp->finish[i++] = ' ';
	gacp->finish[i++] = '"';
	while (j < ft_strlen(gacp->date))
		gacp->finish[i++] = gacp->date[j++];
	gacp->finish[i++] = '"';
	gacp->finish[i++] = '\0';
}

static void		option_2(t_gacp *gacp)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	gacp->finish = ft_strnew(sizeof(char) * (gacp->length));
	while (i < ft_strlen(gacp->first))
		gacp->finish[i++] = gacp->first[j++];
	gacp->finish[i++] = ' ';
	gacp->finish[i++] = '"';
	j = 0;
	while(j < ft_strlen(gacp->expand) - 1)
		gacp->finish[i++] = gacp->expand[j++];
	gacp->finish[i++] = ' ';
	j = 0;
	while (j < ft_strlen(gacp->date))
		gacp->finish[i++] = gacp->date[j++];
	gacp->finish[i++] = '"';
	gacp->finish[i++] = '\0';
}

void	ft_strjoin_commit(t_gacp *gacp)
{
	if (ft_strlen(gacp->expand) == 1)
		option_1(gacp);
	else
		option_2(gacp);
}