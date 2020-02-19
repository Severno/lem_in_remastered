/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_of_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:05:14 by sapril            #+#    #+#             */
/*   Updated: 2019/10/30 14:03:58 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int		ft_num_of_digits(long long int num)
{
	int	count;

	count = 1;
	while ((num = num / 10))
		count++;
	return (count);
}
