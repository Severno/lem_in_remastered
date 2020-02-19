/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dec_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:00:45 by sapril            #+#    #+#             */
/*   Updated: 2019/12/06 08:51:16 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char		get_value(long long num, char sign)
{
	char letter;

	if (sign == 'X')
		letter = 'A';
	else
		letter = 'a';
	if (num >= 0 && num <= 9)
		return ((char)(num + '0'));
	else
		return ((char)(num - 10 + letter));
}

static void		rev_result(char *str)
{
	int		len;
	int		i;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	temp = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

char			*ft_convert_dec_base_to_str(int base,
		long long input_num, char sign)
{
	size_t		index;
	long long	input_cpy;
	char		*res;

	res = ft_strnew(100);
	index = 0;
	input_cpy = input_num;
	input_num < 0 ? input_num *= -1 : 0;
	while (input_num > 0)
	{
		res[index++] = get_value(input_num % base, sign);
		input_num /= base;
	}
	if (input_cpy < 0)
	{
		res[index] = '-';
		res[index + 1] = '\0';
	}
	else
		res[index] = '\0';
	rev_result(res);
	return (res);
}
