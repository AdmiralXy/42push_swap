/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/24 21:58:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initialize(t_collection *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->counter_a = 0;
	stacks->counter_b = 0;
	stacks->min = 2147483647;
	stacks->max = -2147483648;
}

t_stack	*ft_array_to_stack(const int *array, int argc)
{
	int		i;
	t_stack	*node;
	t_stack	*head;

	i = 0;
	head = malloc(sizeof(t_stack));
	if (!head)
		ft_error_silence();
	node = head;
	while (i < argc - 1)
	{
		node->value = array[i];
		if (i + 1 < argc - 1)
		{
			node->next = malloc(sizeof(t_stack));
			if (!node->next)
				ft_error_silence();
			node = node->next;
		}
		else
			node->next = NULL;
		i++;
	}
	return (head);
}

int	ft_unique_elements(t_stack *a)
{
	int		value;
	t_stack	*iterator_i;
	t_stack	*iterator_j;

	iterator_i = a;
	while (iterator_i)
	{
		if (iterator_i->next)
		{
			value = iterator_i->value;
			iterator_j = iterator_i->next;
			while (iterator_j)
			{
				if (value == iterator_j->value)
					return (0);
				iterator_j = iterator_j->next;
			}
		}
		iterator_i = iterator_i->next;
	}
	return (1);
}

void	ft_fill_stack(int argc, char **argv, t_collection *stacks)
{
	int	i;
	int	*array;

	array = malloc(sizeof(int) * argc);
	i = 0;
	while (i < argc - 1)
	{
		array[i] = ft_atoi_overflow(argv[i + 1], stacks);
		i++;
	}
	stacks->counter_a = i;
	stacks->a = ft_array_to_stack(array, argc);
	free(array);
	if (!ft_unique_elements(stacks->a))
	{
		ft_clear_stacks(stacks, 1);
	}
}
