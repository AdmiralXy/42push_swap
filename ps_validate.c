/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/25 22:00:05 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_whitespaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_digit_exists(char *str, t_collection *stacks)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			return ;
		i++;
	}
	ft_clear_stacks(stacks, 1);
}

void	ft_valid_str(const char *str, t_collection *stacks)
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
				ft_clear_stacks(stacks, 1);
			nbr = 0;
			sign = 0;
		}
		else if (str[i + 1] != '\0' && (str[i] == '+' || str[i] == '-')
			&& sign == 0 && nbr == 0)
			sign++;
		else
			ft_clear_stacks(stacks, 1);
		i++;
	}
}

int	ft_is_sorted(t_stack *a)
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

int	ft_validation(int argc, char **argv, t_collection *stacks)
{
	int	i;
	int	checked;

	checked = 0;
	i = 1;
	while (i < argc)
	{
		if (!ft_whitespaces(argv[i]))
		{
			ft_digit_exists(argv[i], stacks);
			ft_valid_str(argv[i], stacks);
			checked = 1;
		}
		i++;
	}
	return (checked);
}
