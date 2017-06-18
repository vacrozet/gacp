#include "../includes/gacp.h"

static void		ft_init(t_gacp	*gacp)
{

	// gacp->length_time[0] --> jour
	// gacp->length_time[1] --> mois
	// gacp->length_time[2] --> annee
	// gacp->length_time[3] --> heure
	// gacp->length_time[4] --> minute
	// gacp->length_time[5] --> seconde

	gacp->first = "git commit -m";
	gacp->length_time[0] = ft_strlen(gacp->time[0]);
	gacp->length_time[1] = ft_strlen(gacp->time[1]);
	gacp->length_time[2] = ft_strlen(gacp->time[2]);
	gacp->length_time[3] = ft_strlen(gacp->time[3]);
	gacp->length_time[4] = ft_strlen(gacp->time[4]);
	gacp->length_time[5] = ft_strlen(gacp->time[5]);

	// gacp->length_jour = ft_strlen(gacp->jour);
	// gacp->length_mois = ft_strlen(gacp->mois);
	// gacp->length_annee = ft_strlen(gacp->annee);
	// gacp->length_heure = ft_strlen(gacp->heure);
	// gacp->length_minute = ft_strlen(gacp->minute);
	// gacp->length_seconde = ft_strlen(gacp->seconde);

	gacp->length = gacp->length_time[0];
	gacp->length += gacp->length_time[1];
	gacp->length += gacp->length_time[2];
	gacp->length += gacp->length_time[3];
	gacp->length += gacp->length_time[4];
	gacp->length += gacp->length_time[5];
	gacp->length += 6;

	// gacp->length = gacp->length_jour;
	// gacp->length += gacp->length_mois;
	// gacp->length += gacp->length_annee;
	// gacp->length += gacp->length_heure;
	// gacp->length += gacp->length_minute;
	// gacp->length += gacp->length_seconde;
	// gacp->length += 6;

	gacp->i = 0;
	gacp->j = 0;
	gacp->str = ft_strnew(sizeof(char) * ( gacp->length));
	if (gacp->str == NULL)
		exit(0);
}

char			*ft_strjoin(t_gacp	*gacp)
{
	int 	k;

	k = 0;
	ft_init(gacp);
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














	// while (gacp->i < gacp->length_jour)
	// 	gacp->str[gacp->j++] = gacp->jour[gacp->i++];
	// gacp->str[gacp->j++] = '/';
	// gacp->i = 0;
	// while (gacp->i < gacp->length_mois)
	// 	gacp->str[gacp->j++] = gacp->mois[gacp->i++];
	// gacp->str[gacp->j++] = '/';
	// gacp->i = 0;
	// while (gacp->i < gacp->length_annee)
	// 	gacp->str[gacp->j++] = gacp->annee[gacp->i++];
	// gacp->str[gacp->j++] = '-';
	// gacp->i = 0;
	// while (gacp->i < gacp->length_heure)
	// 	gacp->str[gacp->j++] = gacp->heure[gacp->i++];
	// gacp->str[gacp->j++] = ':';
	// gacp->i = 0;
	// while (gacp->i < gacp->length_minute)
	// 	gacp->str[gacp->j++] = gacp->minute[gacp->i++];
	// gacp->str[gacp->j++] = ':';
	// gacp->i = 0;	
	// while (gacp->i < gacp->length_seconde)
	// 	gacp->str[gacp->j++] = gacp->seconde[gacp->i++];
	// gacp->str[gacp->j++] = '\0';	
	// return (gacp->str);



}
