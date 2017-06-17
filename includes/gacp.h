/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gacp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:04:18 by vacrozet          #+#    #+#             */
/*   Updated: 2017/06/17 16:04:25 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GACP_H
# define GACP_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct		s_gacp
{
	int				i;
	int				j;
	char			*jour;
	char			*mois;
	char			*annee;
	char			*heure;
	char			*minute;
	char			*seconde;

	int				length;
	int 			length_jour;
	int 			length_mois;
	int 			length_annee;
	int 			length_heure;
	int 			length_minute;
	int 			length_seconde;
}					t_gacp;

int				ft_absolut(int nb);
char			*ft_itoa(int n);



#endif