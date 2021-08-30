/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_large_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/31 00:57:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_run_ra_rra(t_collection *stacks, char direction, int offset)
{
	int	i;

	i = 0;
	while (i < offset)
	{
		if (direction == 1)
			ft_ra(stacks, 1);
		else
			ft_rra(stacks, 1);
		i++;
	}
}

void	ft_run_ra_rra_actions(t_collection *stacks, t_actions *actions)
{
	while (actions->offset_a > 0 || actions->offset_b > 0)
	{
		if (actions->offset_a > 0)
		{
			if (actions->direction_a == 1)
				ft_ra(stacks, 1);
			else
				ft_rra(stacks, 1);
			actions->offset_a--;
		}
		if (actions->offset_b > 0)
		{
			if (actions->direction_b == 1)
				ft_rb(stacks, 1);
			else
				ft_rrb(stacks, 1);
			actions->offset_b--;
		}
	}
	ft_pa(stacks, 1);
}

int	ft_smaller_element_index(t_stack *stack)
{
	int		i;
	int		index;
	int		min;

	min = 2147483647;
	i = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

void	ft_optimized_move(t_collection *stacks, t_actions *actions)
{
	int		best_distance;
	t_stack	*head_a;
	t_stack	*head_b;

	best_distance = -1;
	head_a = stacks->a;
	head_b = stacks->b;
	while (stacks->b)
	{
		best_distance = ft_best_distance(stacks, actions, best_distance);
		stacks->a = head_a;
		stacks->b = stacks->b->next;
	}
	stacks->b = head_b;
	ft_run_ra_rra_actions(stacks, actions);
}

void	ft_selection_sort(t_collection *stacks)
{
	int			smaller_index;
	t_actions	*actions;

	actions = malloc(sizeof(t_actions));
	if (!actions)
		ft_clear_stacks(stacks, 0);
	while (stacks->counter_b != 0)
	{
		ft_setup_stack_properties(stacks->a, stacks->counter_a);
		ft_setup_stack_properties(stacks->b, stacks->counter_b);
		ft_optimized_move(stacks, actions);
	}
	smaller_index = ft_smaller_element_index(stacks->a);
	if (smaller_index < stacks->counter_a / 2)
		ft_run_ra_rra(stacks, 1, smaller_index);
	else
		ft_run_ra_rra(stacks, -1, stacks->counter_a - smaller_index);
	free(actions);
}
