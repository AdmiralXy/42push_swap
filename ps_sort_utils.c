/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/20 19:54:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_min_max(t_collection *stacks)
{
	t_stack	*a_ptr;
	t_stack	*b_ptr;

	a_ptr = stacks->a;
	b_ptr = stacks->b;
	while (a_ptr)
	{
		if (a_ptr->value > stacks->max)
			stacks->max = a_ptr->value;
		if (a_ptr->value < stacks->min)
			stacks->min = a_ptr->value;
		a_ptr = a_ptr->next;
	}
	while (b_ptr)
	{
		if (b_ptr->value > stacks->max)
			stacks->max = b_ptr->value;
		if (b_ptr->value < stacks->min)
			stacks->min = b_ptr->value;
		b_ptr = b_ptr->next;
	}
}

void	ft_setup_stack_properties(t_stack *stack, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (i <= n / 2)
		{
			stack->index = i;
			stack->direction = 1;
		}
		else
		{
			stack->index = n - i;
			stack->direction = -1;
		}
		stack = stack->next;
		i++;
	}
}
