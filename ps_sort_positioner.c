/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_positioner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/25 19:00:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_better_solution(t_stack *stack, int smallest, int src)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value < smallest && stack->value > src)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	ft_best_offset(t_collection *stacks)
{
	int	smallest;
	int	offset;
	int	better_solution;

	smallest = 0;
	offset = 0;
	while (stacks->a)
	{
		smallest = stacks->a->value;
		if (stacks->b->value > stacks->a->value)
		{
			offset += 1;
			stacks->a = stacks->a->next;
		}
		else
			break ;
	}
	better_solution = ft_better_solution(stacks->a, smallest, stacks->b->value);
	if (better_solution != -1)
		offset = better_solution;
	if (stacks->a->direction == -1)
		return (stacks->counter_a - offset);
	return (offset);
}

int	ft_best_distance(t_collection *stacks, t_actions *actions, int distance)
{
	int	offset;

	offset = ft_best_offset(stacks);
	if (distance == -1 || (offset + stacks->b->index) < distance)
	{
		actions->direction_a = stacks->a->direction;
		actions->direction_b = stacks->b->direction;
		actions->offset_a = offset;
		actions->offset_b = stacks->b->index;
		return (offset + stacks->b->index);
	}
	return (distance);
}
