/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:37:39 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/03 02:41:29 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_selectpartsize(t_list **a)
{
	int	size;
	int	partsize;

	size = ft_lstsize(*a);
	if (size < 100)
		partsize = 2;
	else if (size >= 100 && size < 300)
		partsize = 4;
	else
		partsize = 8;
	partsize = size / partsize;
	return (partsize);
}

void	ft_startpos(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	partsize;

	i = 0;
	j = 1;
	partsize = ft_selectpartsize(a);
	while (*a)
	{
		if ((*a)->num < partsize * j)
		{	
			ft_p(b, a, 'b');
			if (*b && (*b)->num < (partsize * j) - (partsize / 2))
				ft_r(b, 'b');
			i++;
		}
		else
			ft_r(a, 'a');
		if (i == partsize * j)
			j++;
	}
}

static int	*ft_initmax(t_list **b, int *max)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *b;
	max[MAXIM] = temp->num;
	max[OLDMAXIM] = max[MAXIM];
	max[SIZE] = ft_lstsize(temp);
	while (i < max[SIZE])
	{
		if (temp->num > max[MAXIM])
		{
			max[MAXIM] = temp->num;
			max[POS] = i;
		}
		temp = temp->next;
		i++;
	}
	if (max[MAXIM] == max[OLDMAXIM])
		max[POS] = 0;
	if (max[POS] > max[SIZE] / 2)
		max[POS] = max[POS] - max[SIZE];
	return (max);
}

void	ft_singlemove(t_list **b, int *pos)
{
	if ((*pos) > 0)
	{
		ft_r(b, 'b');
		(*pos)--;
	}
	else if ((*pos) < 0)
	{
		ft_ir(b, 'b');
		(*pos)++;
	}
}

void	ft_solve(t_list **a, t_list **b, int *toswap)
{
	int		*max;

	max = malloc(sizeof(int) * 4);
	max = ft_initmax(b, max);
	while (max[POS] != 0)
	{
		if ((*b)->num == max[MAXIM] - 1 && *toswap == 0)
		{
			ft_p(a, b, 'a');
			*toswap = 1;
			free(max);
			return ;
		}
		ft_singlemove(b, &max[POS]);
	}
	ft_p(a, b, 'a');
	if (*toswap == 1)
	{
		ft_s(*a, 'a');
		*toswap = 0;
	}
	free(max);
}
