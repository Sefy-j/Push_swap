/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswaputils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:29:22 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/02 19:50:32 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_errors(int error, char *name)
{
	if (error == ERRNOTNUM)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd(" is not a number\n", 2);
		free(name);
	}
	if (error == ERRNUMREPEAT)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd(" is repeated\n", 2);
	}
	if (error == ERREMPTARG)
		ft_putstr_fd("Error: Argument is empty or spaces\n", 2);
	if (error == ERRTOOBIG)
		ft_putstr_fd("Error: Number larger than int\n", 2);
	exit (ERRGENERAL);
}

void	ft_printlist(t_list *a)
{
	t_list	*templst;

	templst = a;
	while (templst)
	{
		ft_putnbr_fd(templst->num, 1);
		ft_putchar_fd('\n', 1);
		templst = templst->next;
	}
}

int	*ft_copylist(t_list **a, int *nums, int total)
{
	int		i;
	t_list	*new;

	i = 0;
	nums = ft_normalize(nums, total);
	while (i < total)
	{
		new = ft_lstnew(nums[i]);
		ft_lstadd_back(a, new);
		i++;
	}
	return (nums);
}

void	ft_freematrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_movetofirst(t_list **lst, int pos, int size)
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
