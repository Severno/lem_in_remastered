/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unnum_of_fields.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:21:08 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 17:21:08 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unnum_of_fields(unsigned long long int num)
{
	int	count;

	count = 1;
	while ((num = num / 10))
		count++;
	return (count);
}
