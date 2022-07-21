/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:04:08 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/21 14:56:21 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strncmp(const char *sr1, const char *sr2, size_t n)
{
	size_t			c;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)sr1;
	s2 = (unsigned char *)sr2;
	c = 0;
	if (n == 0)
		return (0);
	while ((s1[c] != '\0') && (s2[c] != '\0') \
			&& (s1[c] == s2[c]) && (c < (n - 1)))
		c++;
	return (s1[c] - s2[c]);
}

static void	ft_checkmove2(char *move, t_list **a, t_list **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
	free(move);
	ft_putstr_fd("Error. Invalid instruction\n", 2);
	exit(ERRGENERAL);
}

void	ft_checkmove(char *move, t_list **a, t_list **b)
{
	if (!ft_strncmp(move, "sa\n", 4))
		ft_s(*a, 0);
	else if (!ft_strncmp(move, "sb\n", 4))
		ft_s(*b, 0);
	else if (!ft_strncmp(move, "ss\n", 4))
		ft_ss(*a, *b, 0);
	else if (!ft_strncmp(move, "pa\n", 4))
		ft_p(a, b, 0);
	else if (!ft_strncmp(move, "pb\n", 4))
		ft_p(b, a, 0);
	else if (!ft_strncmp(move, "ra\n", 4))
		ft_r(a, 0);
	else if (!ft_strncmp(move, "rb\n", 4))
		ft_r(b, 0);
	else if (!ft_strncmp(move, "rr\n", 4))
		ft_rr(a, b, 0);
	else if (!ft_strncmp(move, "rra\n", 4))
		ft_ir(a, 0);
	else if (!ft_strncmp(move, "rrb\n", 4))
		ft_ir(b, 0);
	else if (!ft_strncmp(move, "rrr\n", 4))
		ft_irr(a, b, 0);
	else
		ft_checkmove2(move, a, b);
}
