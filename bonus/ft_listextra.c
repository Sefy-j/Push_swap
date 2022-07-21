/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listextra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:51:30 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/21 14:29:23 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ir(t_list **a, char c)
{
	t_list	*temp;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	temp = ft_lstlast(temp);
	temp->next = *a;
	while ((*a)->next != temp)
		*a = (*a)->next;
	(*a)->next = NULL;
	*a = temp;
	if (c == 0)
		return ;
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_irr(t_list **a, t_list **b, char c)
{
	ft_ir(a, 0);
	ft_ir(b, 0);
	if (c == 0)
		return ;
	ft_putstr_fd("rrr\n", 1);
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmplist;

	if (!lst)
		return ;
	while (*lst)
	{
		tmplist = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmplist;
	}
	*lst = NULL;
}

void	ft_lstclearone(t_list **lst)
{
	t_list	*tmplist;

	tmplist = (*lst)->next;
	ft_lstdelone(*lst);
	*lst = tmplist;
}
