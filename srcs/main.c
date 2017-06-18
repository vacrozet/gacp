/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:02:36 by vacrozet          #+#    #+#             */
/*   Updated: 2017/06/17 16:02:39 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gacp.h"

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

void	ft_init(t_gacp	*gacp)
{
	gacp->first = "git commit -m";
	gacp->length_jour = ft_strlen(gacp->jour);
	gacp->length_mois = ft_strlen(gacp->mois);
	gacp->length_annee = ft_strlen(gacp->annee);
	gacp->length_heure = ft_strlen(gacp->heure);
	gacp->length_minute = ft_strlen(gacp->minute);
	gacp->length_seconde = ft_strlen(gacp->seconde);

	gacp->length = gacp->length_jour;
	gacp->length += gacp->length_mois;
	gacp->length += gacp->length_annee;
	gacp->length += gacp->length_heure;
	gacp->length += gacp->length_minute;
	gacp->length += gacp->length_seconde;
	gacp->length += 6;

	gacp->i = 0;
	gacp->j = 0;
	gacp->str = ft_strnew(sizeof(char) * ( gacp->length));
	if (gacp->str == NULL)
		exit(0);
}

char	*ft_strjoin(t_gacp	*gacp)
{
	ft_init(gacp);
	while (gacp->i < gacp->length_jour)
		gacp->str[gacp->j++] = gacp->jour[gacp->i++];
	gacp->str[gacp->j++] = '/';
	gacp->i = 0;
	while (gacp->i < gacp->length_mois)
		gacp->str[gacp->j++] = gacp->mois[gacp->i++];
	gacp->str[gacp->j++] = '/';
	gacp->i = 0;
	while (gacp->i < gacp->length_annee)
		gacp->str[gacp->j++] = gacp->annee[gacp->i++];
	gacp->str[gacp->j++] = '-';
	gacp->i = 0;
	while (gacp->i < gacp->length_heure)
		gacp->str[gacp->j++] = gacp->heure[gacp->i++];
	gacp->str[gacp->j++] = ':';
	gacp->i = 0;
	while (gacp->i < gacp->length_minute)
		gacp->str[gacp->j++] = gacp->minute[gacp->i++];
	gacp->str[gacp->j++] = ':';
	gacp->i = 0;	
	while (gacp->i < gacp->length_seconde)
		gacp->str[gacp->j++] = gacp->seconde[gacp->i++];
	gacp->str[gacp->j++] = '\0';	
	return (gacp->str);
}

void	ft_date(t_gacp *gacp)
{
	time_t temps;
	struct tm date;

	time(&temps);
	date=*gmtime(&temps);

	gacp->jour = ft_itoa(date.tm_mday);
	gacp->mois = ft_itoa(date.tm_mon + 1);
	gacp->annee = ft_itoa(date.tm_year - 100);
	gacp->heure = ft_itoa(date.tm_hour + 2);
	gacp->minute = ft_itoa(date.tm_min);
	gacp->seconde = ft_itoa(date.tm_sec);
	gacp->date = ft_strjoin(gacp);
	gacp->length_date = ft_strlen(gacp->date);
}
void	free_leaks(t_gacp *gacp)
{

	free(gacp->jour);
	free(gacp->mois);
	free(gacp->annee);
	free(gacp->heure);
	free(gacp->minute);
	free(gacp->seconde);
	free(gacp->date);
	free(gacp->expand);
	free(gacp->finish);
	free(gacp);	
}

int 	main(void)
{
	t_gacp		*gacp;
	char		chaine[1000000];
	char		fake[1000000];
	char		fake_1[1000000];

	if (!(gacp = (t_gacp *)malloc(sizeof(t_gacp))))
		return (0);
	ft_date(gacp);
	system("git status");
	ft_putstr("Please Press ENTER To Be Continue !");
	fgets(fake, sizeof fake, stdin);
	system("git add -A");
	ft_putstr("Commit : ");
	fgets(chaine, sizeof chaine, stdin);
	ft_expand_str(chaine, gacp);
	ft_strjoin_commit(gacp);
	system(gacp->finish);
	ft_putstr("Please Press ENTER For Push !");
	fgets(fake_1, sizeof fake_1, stdin);
	system("git push");
	ft_putstr("ENJOY Your Job is Push");
	free_leaks(gacp);
	return 0;
}