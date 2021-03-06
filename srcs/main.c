/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:02:36 by vacrozet          #+#    #+#             */
/*   Updated: 2017/06/18 17:33:59 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gacp.h"

void		ft_date(t_gacp *gacp)
{
	time_t	temps;
	t_tm	date;

	time(&temps);
	date = *gmtime(&temps);
	gacp->time[0] = ft_itoa(date.tm_mday);
	gacp->time[1] = ft_itoa(date.tm_mon + 1);
	gacp->time[2] = ft_itoa(date.tm_year - 100);
	gacp->time[3] = ft_itoa(date.tm_hour + 2);
	gacp->time[4] = ft_itoa(date.tm_min);
	gacp->time[5] = ft_itoa(date.tm_sec);
	gacp->date = ft_strjoin(gacp);
	gacp->length_date = ft_strlen(gacp->date);
}

void		free_leaks(t_gacp *gacp)
{
	int		k;

	k = 0;
	while (k < 6)
		free(gacp->time[k++]);
	free(gacp->date);
	free(gacp->expand);
	free(gacp->finish);
	free(gacp);
}

int			main(void)
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
	fgets(fake, sizeof(fake), stdin);
	system("git add -A");
	ft_putstr("Commit : ");
	fgets(chaine, sizeof(chaine), stdin);
	ft_expand_str(chaine, gacp);
	ft_strjoin_commit(gacp);
	system(gacp->finish);
	ft_putstr("Please Press ENTER For Push !");
	fgets(fake_1, sizeof(fake_1), stdin);
	system("git push");
	ft_putstr("ENJOY Your Job is Push\n");
	free_leaks(gacp);
	return (0);
}
