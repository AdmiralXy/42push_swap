/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricky <kricky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:36:05 by kricky            #+#    #+#             */
/*   Updated: 2021/09/01 10:36:06 by kricky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrcmp(const int n1, const int n2)
{
	if (n1 > n2)
		return (1);
	else if (n1 < n2)
		return (-1);
	return (0);
}