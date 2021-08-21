/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/19 23:37:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_issign(int c)
{
	return ((char)c == '-' || (char)c == '+');
}

static int	ft_iswhitespace(int c)
{
	return ((char)c == '\t' || (char)c == '\v' || (char)c == '\f'
		|| (char)c == '\r' || (char)c == '\n' || (char)c == ' ');
}

static	int	ft_checkoverflow(int res, int term, int sign)
{
	long long int	result;

	result = res;
	result = (result * 10) + term;
	result = result * sign;
	if (result > +2147483647 || result < -2147483648)
	{
		ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	ft_atoi_overflow(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] != '\0' && ft_iswhitespace(str[i]))
		i++;
	if (str[i] != '\0' && ft_issign(str[i]))
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		ft_checkoverflow(res, (str[i] - '0'), sign);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
