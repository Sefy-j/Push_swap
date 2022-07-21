/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallalgo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:09:01 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/03/28 22:49:13 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_threealgo(t_list **a)
{
	if ((*a)->num < (*a)->next->num && (*a)->num < (*a)->next->next->num)
	{	
		if ((*a)->next->num > (*a)->next->next->num)
		{
			ft_s(*a, 'a');
			ft_r(a, 'a');
		}
	}
	else if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num)
	{
		if ((*a)->next->num > (*a)->next->next->num)
		{
			ft_s(*a, 'a');
			ft_ir(a, 'a');
		}
		else
			ft_r(a, 'a');
	}
	else
	{
		if ((*a)->next->num > (*a)->next->next->num)
			ft_ir(a, 'a');
		else
			ft_s(*a, 'a');
	}
}

static void	ft_fivealgo(t_list **a, t_list **b)
{
	int	min;
	int	pos;

	min = (*a)->num;
	pos = ft_min(*a, &min);
	ft_movetofirst(a, pos, 5);
	ft_p(b, a, 'b');
	min = (*a)->num;
	pos = ft_min(*a, &min);
	ft_movetofirst(a, pos, 4);
	ft_p(b, a, 'b');
	ft_threealgo(a);
	ft_p(a, b, 'a');
	ft_p(a, b, 'a');
}

static void	ft_fouralgo(t_list **a, t_list **b)
{
	int	min;
	int	pos;

	min = (*a)->num;
	pos = ft_min(*a, &min);
	ft_movetofirst(a, pos, 4);
	ft_p(b, a, 'b');
	ft_threealgo(a);
	ft_p(a, b, 'a');
}

void	ft_smallalgo(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
	{
		if ((*a)->num > (*a)->next->num)
			ft_s(*a, 'a');
	}
	else if (size == 3)
		ft_threealgo(a);
	else if (size == 4)
		ft_fouralgo(a, b);
	else if (size == 5)
		ft_fivealgo(a, b);
}
