/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:19:59 by sapril            #+#    #+#             */
/*   Updated: 2019/12/06 08:45:48 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		check_letter(unsigned long long num_arr[], int j)
{
	while (j > 0 || j == 0)
	{
		if (num_arr[j] > 9)
		{
			num_arr[j] == 10 ? ft_putchar('a') : 0;
			num_arr[j] == 11 ? ft_putchar('b') : 0;
			num_arr[j] == 12 ? ft_putchar('c') : 0;
			num_arr[j] == 13 ? ft_putchar('d') : 0;
			num_arr[j] == 14 ? ft_putchar('e') : 0;
			num_arr[j] == 15 ? ft_putchar('f') : 0;
			j--;
		}
		else
			ft_putchar((char)(num_arr[j--] + '0'));
	}
}

void			ft_putnbr_base(long long int n, int base)
{
	unsigned long long	num_arr[100];
	int					i;
	int					j;

	i = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	while (n != 0)
	{
		num_arr[i++] = n % base;
		n = n / base;
	}
	j = i - 1;
	check_letter(num_arr, j);
}

void			ft_putunbr_base(unsigned long long int n, int base)
{
	unsigned long long	num_arr[100];
	int					i;
	int					j;

	i = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (n != 0)
	{
		num_arr[i++] = n % base;
		n = n / base;
	}
	j = i - 1;
	check_letter(num_arr, j);
}
