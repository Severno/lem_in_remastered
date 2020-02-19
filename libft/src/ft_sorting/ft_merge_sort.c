/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 08:08:28 by sapril            #+#    #+#             */
/*   Updated: 2019/12/11 12:25:30 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		copy_left_arr_to_tmp(int low, int middle,
		int left_arr[], int arr[])
{
	int left_i;

	left_i = 0;
	while (left_i < middle - low + 1)
	{
		left_arr[left_i] = arr[low + left_i];
		left_i++;
	}
}

static void		copy_right_arr_to_tmp(int high, int middle,
		int right_arr[], int arr[])
{
	int right_i;

	right_i = 0;
	while (right_i < high - middle)
	{
		right_arr[right_i] = arr[middle + right_i + 1];
		right_i++;
	}
}

static void		merge(int arr[], int low, int middle, int high)
{
	int left_i;
	int right_i;
	int arr_i;
	int left_arr[middle - low + 1];
	int right_arr[high - middle];

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

int				*ft_merge_sort(int *arr, int low, int high)
{
	int middle;

	middle = low + (high - low) / 2;
	if (low < high)
	{
		ft_merge_sort(arr, low, middle);
		ft_merge_sort(arr, middle + 1, high);
		merge(arr, low, middle, high);
	}
	return (arr);
}
