/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricky <kricky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/09/01 13:38:21 by kricky           ###   ########.fr       */
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

void	ft_validate_number(const char *str, t_collection *stacks)
{
	int	i;

	i = 0;
	while (str[i] != '\0'
		&& (str[i] == '\n' || str[i] == '\t' || str[i] == ' '))
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
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
	int		i;
	int		j;
	char	**tmp;
	int		checked;

	checked = 0;
	i = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		j = 0;
		while (tmp[j] != '\0')
		{
			if (!ft_whitespaces(tmp[j]))
			{
				ft_digit_exists(tmp[j], stacks);
				ft_validate_number(tmp[j], stacks);
				checked = 1;
			}
			j++;
		}
		tmp = ft_clear_strs(tmp);
		i++;
	}
	return (checked);
}
