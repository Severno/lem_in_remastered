/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:47:41 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 16:34:00 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ALGS_H
# define SORT_ALGS_H

# include "libft.h"

int					quick_select(int *arr, int left, int right, int k);
int					*ft_merge_sort(int *arr, int low, int high);
void				ft_bubble_sort(int arr[], int n);
void				ft_quick_sort(int arr[], int low, int high);

#endif
