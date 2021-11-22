/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:42:23 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:42:49 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_qsort_swap2i(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	ft_quick_sort_partition(int *nums, int begin, int end)
{
	int	pivot;

	pivot = begin++;
	while (begin != end)
	{
		if (nums[pivot] > nums[begin])
		{
			ft_qsort_swap2i(&nums[pivot], &nums[begin]);
			pivot++;
			if (pivot != begin)
				ft_qsort_swap2i(&nums[pivot], &nums[begin]);
		}
		begin++;
	}
	return (pivot);
}

static void	ft_quick_sort_rec(int *nums, int begin, int end)
{
	int	pivot;

	if (end - begin <= 1)
		return ;
	pivot = ft_quick_sort_partition(nums, begin, end);
	ft_quick_sort_rec(nums, begin, pivot);
	ft_quick_sort_rec(nums, pivot + 1, end);
}

void	ft_quick_sort(int *nums, int nums_size)
{
	ft_quick_sort_rec(nums, 0, nums_size);
}
