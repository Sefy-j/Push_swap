/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:33:59 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/02 23:47:10 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_findmax(int *nums, int total, int *min)
{
	int	i;

	i = 0;
	min[MAX] = nums[0];
	while (i < total)
	{
		if (nums[i] > min[MAX])
		{
			min[MAX] = nums[i];
			min[MAXPOS] = i;
		}
		i++;
	}
	return (min);
}

int	*ft_findnewmin(int *nums, int total, int *min)
{
	int	i;

	i = 0;
	min[MIN] = min[MAX];
	while (i < total)
	{
		if (nums[i] < min[MIN] && nums[i] > min[OLDMIN])
		{	
			min[MIN] = nums[i];
			min[MINPOS] = i;
		}
		i++;
	}
	i = 0;
	if (min[MIN] == min[MAX])
			min[MINPOS] = min[MAXPOS];
	min[OLDMIN] = min[MIN];
	return (min);
}

int	*ft_findmin(int *nums, int total, int *min)
{
	int	i;

	i = 0;
	min[MIN] = nums[0];
	min[COPYNUM] = 0;
	while (i < total)
	{
		if (nums[i] < min[MIN])
		{	
			min[MIN] = nums[i];
			min[MINPOS] = i;
		}
		i++;
	}
	min[OLDMIN] = min[MIN];
	min = ft_findmax(nums, total, min);
	return (min);
}

int	*ft_initmin(int *min)
{
	min[MIN] = 0;
	min[MINPOS] = 0;
	min[OLDMIN] = 0;
	min[COPYNUM] = 0;
	min[MAX] = 0;
	min[MAXPOS] = 0;
	return (min);
}

int	*ft_normalize(int *nums, int total)
{
	int	*min;
	int	*newnum;

	newnum = malloc(sizeof(int) * total);
	min = malloc(sizeof(int) * 6);
	min = ft_initmin(min);
	min = ft_findmin(nums, total, min);
	newnum[min[MINPOS]] = min[COPYNUM];
	min[COPYNUM]++;
	while (min[COPYNUM] < total)
	{
		min = ft_findnewmin(nums, total, min);
		newnum[min[MINPOS]] = min[COPYNUM];
		min[COPYNUM]++;
	}
	newnum[min[MINPOS]] = min[COPYNUM] - 1;
	free(min);
	free(nums);
	return (newnum);
}
