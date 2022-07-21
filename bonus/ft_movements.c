/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:52:42 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/21 14:44:32 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_s(t_list *a, char c)
{
	int	temp;

	if (!a || !a->next)
		return ;
	temp = a->num;
	a->num = a->next->num;
	a->next->num = temp;
	if (c == 0)
		return ;
	ft_putchar_fd('s', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_ss(t_list *a, t_list *b, char c)
{
	ft_s(a, 0);
	ft_s(b, 0);
	if (c == 0)
		return ;
	ft_putstr_fd("ss\n", 1);
}

void	ft_p(t_list **listto, t_list **listfrom, char c)
{
	if (!*listfrom)
		return ;
	ft_lstadd_front(listto, ft_lstnew((*listfrom)->num));
	ft_lstclearone(listfrom);
	if (c == 0)
		return ;
	ft_putchar_fd('p', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_r(t_list **a, char c)
{
	t_list	*temp;

	if (!*a || !(*a)->next)
		return ;
	temp = (*a)->next;
	(*a)->next = NULL;
	(ft_lstlast(temp))->next = *a;
	*a = temp;
	if (c == 0)
		return ;
	ft_putchar_fd('r', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_rr(t_list **a, t_list **b, char c)
{
	ft_r(a, 0);
	ft_r(b, 0);
	if (c == 0)
		return ;
	ft_putstr_fd("rr\n", 1);
}
