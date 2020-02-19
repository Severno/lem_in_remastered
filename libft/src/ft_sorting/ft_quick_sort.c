/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:30:00 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 16:30:37 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int				partition(int arr[], int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void			ft_quick_sort(int arr[], int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		ft_quick_sort(arr, low, pi - 1);
		ft_quick_sort(arr, pi + 1, high);
	}
}
