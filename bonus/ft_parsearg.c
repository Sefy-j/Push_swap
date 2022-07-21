/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsearg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:01:54 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/21 14:29:31 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checkrepeat(int *nums, int total)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (i < total)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (nums[j] == nums[i])
			{
				str = ft_itoa(nums[j]);
				free(nums);
				ft_errors(ERRNUMREPEAT, str);
			}
			j--;
		}
		i++;
	}
}

static void	ft_copycheck(long long int aux, int *nums, char **numstr)
{
	if (aux > INT_MAX || aux < INT_MIN)
	{
		free(nums);
		ft_freematrix(numstr);
		ft_errors(ERRTOOBIG, NULL);
	}
}

int	*ft_copynums(int argc, char **argv, int total)
{
	int					i[3];
	long long int		aux;
	int					*nums;
	char				**numstr;

	i[0] = 1;
	i[1] = 0;
	i[2] = 0;
	nums = malloc(sizeof(int) * total);
	while (i[0] < argc)
	{
		numstr = ft_split(argv[i[0]], ' ');
		while (numstr[i[2]])
		{
			aux = ft_atoipushswap(numstr[i[2]]);
			ft_copycheck(aux, nums, numstr);
			nums[i[1]] = aux;
			i[1]++;
			i[2]++;
		}
		i[2] = 0;
		i[0]++;
		ft_freematrix(numstr);
	}
	return (nums);
}

int	ft_checkdigit(char **nms)
{
	int		i[2];
	int		len;
	char	*str;

	i[0] = 0;
	i[1] = 0;
	while (nms[i[0]])
	{
		len = ft_strlen(nms[i[0]]);
		while (i[1] < len)
		{
			if ((nms[i[0]][i[1]] == '-' || nms[i[0]][i[1]] == '+') && i[1] == 0)
				i[1]++;
			if (!ft_isdigit(nms[i[0]][i[1]]))
			{
				str = ft_strdup(nms[i[0]]);
				ft_freematrix(nms);
				ft_errors(ERRNOTNUM, str);
			}
			i[1]++;
		}
		i[1] = 0;
		i[0]++;
	}
	return (i[0]);
}

int	*ft_checkargv(int argc, char **argv, int *total)
{
	int		i;
	int		*nums;
	char	**numstr;

	i = 1;
	nums = NULL;
	if (!(*argv[i]))
		exit (0);
	while (i < argc)
	{
		numstr = ft_split(argv[i], ' ');
		if (numstr[0] == NULL)
			ft_errors(ERREMPTARG, NULL);
		*total += ft_checkdigit(numstr);
		ft_freematrix(numstr);
		i++;
	}
	if (*total)
		nums = ft_copynums(argc, argv, *total);
	ft_checkrepeat(nums, *total);
	return (nums);
}
