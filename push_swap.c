/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:15:27 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/21 14:38:01 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_initlist(t_list **a, int argc, char **argv)
{
	int	*nums;
	int	total;

	total = 0;
	nums = ft_checkargv(argc, argv, &total);
	nums = ft_copylist(a, nums, total);
	free(nums);
}

static void	ft_lastmove(t_list **lst, int pos, int size)
{
	if (pos > size / 2)
		pos = pos - size;
	while (pos != 0)
	{
		if (pos > 0)
		{
			ft_r(lst, 'a');
			pos--;
		}
		else if (pos < 0)
		{
			ft_ir(lst, 'a');
			pos++;
		}
	}
}

static int	ft_ordered(t_list *a)
{
	int	num;

	num = a->num - 1;
	while (a->next)
	{
		if (a->num > num)
			num = a->num;
		else
			return (1);
		a = a->next;
	}
	if (a->num > num)
		return (0);
	return (1);
}

static int	ft_checkfinish(t_list **a, t_list *b)
{
	int	size;
	int	min;
	int	pos;

	if (b)
		return (1);
	else if (!b)
	{
		size = ft_lstsize(*a);
		min = (*a)->num;
		pos = ft_min(*a, &min);
		ft_lastmove(a, pos, size);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		toswap;

	a = NULL;
	b = NULL;
	toswap = 0;
	if (argc <= 1)
		return (0);
	ft_initlist(&a, argc, argv);
	if (ft_ordered(a))
	{
		if (ft_lstsize(a) <= 5)
			ft_smallalgo(&a, &b);
		else
		{
			ft_startpos(&a, &b);
			while (ft_checkfinish(&a, b))
				ft_solve(&a, &b, &toswap);
		}
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
}
