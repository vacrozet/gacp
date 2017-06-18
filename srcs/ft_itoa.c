/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 16:39:44 by vacrozet          #+#    #+#             */
/*   Updated: 2017/06/18 16:40:09 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gacp.h"

int				ft_absolut(int nb)
{
	int	res;

	if (nb < 0)
		res = -nb;
	else
		res = nb;
	return (res);
}

static int		ft_len_nb(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		nlen;

	nlen = ft_len_nb(n);
	sign = n < 0 ? 1 : 0;
	if (!(str = (char *)malloc(sizeof(char) * nlen + sign + 1)))
		return (NULL);
	str = str + nlen + sign;
	*str = '\0';
	if (!n)
		*--str = '0';
	while (n != 0)
	{
		*--str = ft_absolut(n % 10) + '0';
		n /= 10;
	}
	if (sign == 1)
		*--str = '-';
	return (str);
}
