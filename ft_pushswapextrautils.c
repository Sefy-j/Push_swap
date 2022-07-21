/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswapextrautils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:38:42 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/21 13:43:45 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_list *lst, int *min)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (lst)
	{
		if (lst->num < *min)
		{
			*min = lst->num;
			pos = i;
		}
		lst = lst->next;
		i++;
	}
	return (pos);
}
