/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/20 01:29:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_whitespaces(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' || str[i] == '\f')
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_digit_exists(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			return ;
		i++;
	}
	ft_error();
}

void	ft_valid_str(const char *str)
{
	int		i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				ft_error();
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-') &&
		(sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

int		ft_is_sorted(t_stack *a)
{
	int	tmp;

	tmp = a->value;
	while (a)
	{
		if (a->value < tmp)
			return (0);
		tmp = a->value;
		a = a->next;
	}
	return (1);
}

int	ft_validation(int argc, char **argv)
{
	int i;
	int ret;

	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (!ft_whitespaces(argv[i]))
		{
			ft_digit_exists(argv[i]);
			ft_valid_str(argv[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}
