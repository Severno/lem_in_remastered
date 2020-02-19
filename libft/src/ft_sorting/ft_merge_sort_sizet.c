/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort_sizet.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:31:42 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 16:31:42 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort_algs.h"

static void		copy_left_arr_to_tmp(size_t low, size_t middle,
		size_t *left_arr, size_t *arr)
{
	size_t left_i;

	left_i = 0;
	while (left_i < middle - low + 1)
	{
		left_arr[left_i] = arr[low + left_i];
		left_i++;
	}
}

static void		copy_right_arr_to_tmp(size_t high, size_t middle,
		size_t right_arr[], size_t arr[])
{
	size_t right_i;

	right_i = 0;
	while (right_i < high - middle)
	{
		right_arr[right_i] = arr[middle + right_i + 1];
		right_i++;
	}
}

static void		merge(size_t *arr, size_t low, size_t middle, size_t high)
{
	size_t left_i;
	size_t right_i;
	size_t arr_i;
	size_t left_arr[middle - low + 1];
	size_t right_arr[high - middle];

	left_i = 0;
	right_i = 0;
	arr_i = low;
	copy_left_arr_to_tmp(low, middle, left_arr, arr);
	copy_right_arr_to_tmp(high, middle, right_arr, arr);
	while (left_i < middle - low + 1 && right_i < high - middle)
	{
		if (left_arr[left_i] < right_arr[right_i])
			arr[arr_i] = left_arr[left_i++];
		else
			arr[arr_i] = right_arr[right_i++];
		arr_i++;
	}
	while (left_i < middle - low + 1)
		arr[arr_i++] = left_arr[left_i++];
	while (right_i < high - middle)
		arr[arr_i++] = right_arr[right_i++];
}

size_t			*ft_merge_sort_sizet(size_t *arr, size_t low, size_t high)
{
	size_t middle;

	middle = low + (high - low) / 2;
	if (low < high)
	{
		ft_merge_sort_sizet(arr, low, middle);
		ft_merge_sort_sizet(arr, middle + 1, high);
		merge(arr, low, middle, high);
	}
	return (arr);
}
