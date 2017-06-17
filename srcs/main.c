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

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

void	ft_init(t_gacp	*gacp)
{
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
}

char	*ft_strjoin(t_gacp	*gacp)
{
	char	*str;

	ft_init(gacp);
	str = ft_strnew(sizeof(char) * ( gacp->length));
	if (str == NULL)
		exit(0);
	while (gacp->i < gacp->length_jour)
		str[gacp->j++] = gacp->jour[gacp->i++];
	str[gacp->j++] = '/';
	gacp->i = 0;
	while (gacp->i < gacp->length_mois)
		str[gacp->j++] = gacp->mois[gacp->i++];
	str[gacp->j++] = '/';
	gacp->i = 0;
	while (gacp->i < gacp->length_annee)
		str[gacp->j++] = gacp->annee[gacp->i++];
	str[gacp->j++] = '-';
	gacp->i = 0;
	while (gacp->i < gacp->length_heure)
		str[gacp->j++] = gacp->heure[gacp->i++];
	str[gacp->j++] = ':';
	gacp->i = 0;
	while (gacp->i < gacp->length_minute)
		str[gacp->j++] = gacp->minute[gacp->i++];
	str[gacp->j++] = ':';
	gacp->i = 0;	
	while (gacp->i < gacp->length_seconde)
		str[gacp->j++] = gacp->seconde[gacp->i++];
	str[gacp->j++] = '\0';	
	return (str);
}

char	*ft_date(t_gacp *gacp)
{
	time_t temps;
	struct tm date;
	char *date_bon_format;

	time(&temps);
	date=*gmtime(&temps);

	gacp->jour = ft_itoa(date.tm_mday);
	gacp->mois = ft_itoa(date.tm_mon + 1);
	gacp->annee = ft_itoa(date.tm_year - 100);
	gacp->heure = ft_itoa(date.tm_hour + 2);
	gacp->minute = ft_itoa(date.tm_min);
	gacp->seconde = ft_itoa(date.tm_sec);
	date_bon_format = ft_strjoin(gacp);
	return date_bon_format;
}

int 	main(int argc, char **argv)
{
	t_gacp		*gacp;
	// char	chaine[10000];
	char	*date;
	char	*debut;
	(void)argc;

	if (!(gacp = (t_gacp *)malloc(sizeof(t_gacp))))
		exit(0);
	debut ="git commit -m";
	date = ft_date(gacp);
	// system("git status");
	// printf("Please Enter To be Continue");
	// fgets(chaine, sizeof chaine, stdin);
	// system("git add -A");
	ft_expand_str(argv[1], gacp);
	printf("%s", gacp->expand);



	return 0;
}