/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:47:05 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 16:25:55 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		swap(int *arr, int i, int j)
{
	int tmp;

	if (i != j)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}

static int		partition(int *arr, int left, int right)
{
	int i;
	int j;
	int pivot_value;

	i = left;
	j = left;
	pivot_value = arr[right];
	while (j < right)
	{
		if (arr[j] <= pivot_value)
		{
			swap(arr, i, j);
			i++;
		}
		j++;
	}
	swap(arr, i, j);
	return (i);
}

int				quick_select(int *arr, int left, int right, int k)
{
	int pivot_position;

	if (k > 0 && k <= right - left + 1)
	{
		pivot_position = partition(arr, left, right);
		if (pivot_position - left == k - 1)
			return (arr[pivot_position]);
		if (pivot_position - left > k - 1)
			return (quick_select(arr, left, pivot_position - 1, k));
		return (quick_select(arr, pivot_position + 1, right,
				k - pivot_position + left - 1));
	}
	return (MAX_INTEGER);
}
