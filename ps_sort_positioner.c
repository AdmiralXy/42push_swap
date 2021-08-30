/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_positioner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/31 01:30:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_minimum_max(t_stack *stack, int higher, int b_value)
{
	int	offset;

	offset = 0;
	while (stack)
	{
		if (stack->value < higher && stack->value > b_value)
			return (offset);
		stack = stack->next;
		offset++;
	}
	return (-1);
}

int	ft_get_offset(t_collection *stacks)
{
	int	higher;
	int	offset;
	int	better_solution;

	higher = 0;
	offset = 0;
	while (stacks->a)
	{
		higher = stacks->a->value;
		if (stacks->b->value > higher)
		{
			offset++;
			stacks->a = stacks->a->next;
		}
		else
			break ;
	}
	better_solution = ft_minimum_max(stacks->a, higher, stacks->b->value);
	if (better_solution != -1)
		offset = better_solution;
	if (stacks->a->direction == -1)
		return (stacks->counter_a - offset);
	return (offset);
}

int	ft_best_distance(t_collection *stacks, t_actions *actions, int distance)
{
	int	offset;
	int	total_offset;

	offset = ft_get_offset(stacks);
	total_offset = offset + stacks->b->index;
	if (distance == -1 || total_offset < distance)
	{
		actions->direction_a = stacks->a->direction;
		actions->direction_b = stacks->b->direction;
		actions->offset_a = offset;
		actions->offset_b = stacks->b->index;
		return (total_offset);
	}
	return (distance);
}
