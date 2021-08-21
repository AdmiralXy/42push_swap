/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/20 00:29:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*stack_ptr;
	t_stack	*first_node;
	t_stack	*rotate_node;
	t_stack	*last_node;

	stack_ptr = *stack;
	if (stack_ptr == NULL || stack_ptr->next == NULL)
		return ;
	rotate_node = stack_ptr;
	first_node = stack_ptr->next;
	last_node = stack_ptr;
	while (last_node->next != NULL)
		last_node = last_node->next;
	rotate_node->next = NULL;
	last_node->next = rotate_node;
	*stack = first_node;
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack		*stack_ptr;
	t_stack		*first_node;
	t_stack		*rotate_node;
	t_stack		*second_to_last_node;

	stack_ptr = *stack;
	if (stack_ptr == NULL || stack_ptr->next == NULL)
		return ;
	first_node = stack_ptr;
	second_to_last_node = stack_ptr;
	while (second_to_last_node->next->next != NULL)
		second_to_last_node = second_to_last_node->next;
	rotate_node = second_to_last_node->next;
	second_to_last_node->next = NULL;
	rotate_node->next = first_node;
	*stack = rotate_node;
}

void	ft_swap_top(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	ft_send_top(t_collection *stacks, const char destination)
{
	t_stack	*tmp;

	if (destination == 'a')
	{
		if (stacks->b == NULL)
			return ;
		stacks->counter_a += 1;
		stacks->counter_b -= 1;
		tmp = stacks->b;
		stacks->b = stacks->b->next;
		tmp->next = stacks->a;
		stacks->a = tmp;
	}
	else if (destination == 'b')
	{
		if (stacks->a == NULL)
			return ;
		stacks->counter_a -= 1;
		stacks->counter_b += 1;
		tmp = stacks->a;
		stacks->a = stacks->a->next;
		tmp->next = stacks->b;
		stacks->b = tmp;
	}
}
