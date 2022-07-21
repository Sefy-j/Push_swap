/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsparse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:24:03 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/21 14:29:47 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

static int	ft_nbcount(long int nb)
{
	int	i;

	i = 0;
	if (nb == 0 || nb < 0)
		i++;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*num;
	int			i;
	int			k;
	long int	nb;

	k = 0;
	nb = n;
	i = ft_nbcount(nb);
	num = (char *)malloc(sizeof(char) * (i + 1));
	if (!num)
		return (NULL);
	if (n < 0)
	{
		nb = -nb;
		num[0] = '-';
		k++;
	}
	num[i] = '\0';
	while (i > k)
	{
		num[i - 1] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (num);
}

static unsigned long long int	ft_checknb(unsigned long long int nb, int s)
{
	unsigned long long int	nl;

	nl = INT_MAX;
	if (nb > nl && s > 0)
		return (nl + 1);
	if (nb > nl + 1 && s < 0)
		return (-nl - 1);
	return (nb);
}

long long int	ft_atoipushswap(const char *str)
{
	int						i;
	int						s;
	unsigned long long int	r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' \
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{	
		if (str[i] == '-')
			s *= (-1);
		i++;
	}	
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	r = ft_checknb(r, s);
	return ((long long int)r * s);
}
