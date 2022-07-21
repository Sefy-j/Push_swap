/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswaputils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:29:22 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/21 14:29:38 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
