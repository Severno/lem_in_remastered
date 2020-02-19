/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_of_fields.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:04:52 by sapril            #+#    #+#             */
/*   Updated: 2019/10/30 14:05:51 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_num_of_fields(long long int num)
{
	int	count;

	count = 1;
	if (num < 0)
	{
		count++;
		num *= -1;
	}
	while ((num = num / 10))
		count++;
	return (count);
}
