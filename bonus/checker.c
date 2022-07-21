/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:15:27 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/21 15:02:29 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_initlist(t_list **a, int argc, char **argv)
{
	int	*nums;
	int	total;

	total = 0;
	nums = ft_checkargv(argc, argv, &total);
	nums = ft_copylist(a, nums, total);
	free(nums);
}

static int	ft_ordered(t_list *a, t_list *b)
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
	if (a->num > num && !b)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*move;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	ft_initlist(&a, argc, argv);
	move = get_next_line(0);
	while (move)
	{
		ft_checkmove(move, &a, &b);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	if (ft_ordered(a, b))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	ft_lstclear(&a);
	ft_lstclear(&b);
}
