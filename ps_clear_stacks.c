/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_clear_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/20 01:27:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear_stacks(t_collection *stacks, int throw_exception)
{
	int		iterator;
	t_stack	*tmp;

	iterator = 0;
	while (iterator < stacks->counter_a)
	{
		tmp = stacks->a;
		stacks->a = stacks->a->next;
		free(tmp);
		iterator++;
	}
	iterator = 0;
	while (iterator < stacks->counter_b)
	{
		tmp = stacks->b;
		stacks->b = stacks->b->next;
		free(tmp);
		iterator++;
	}
	if (throw_exception)
	{
		free(stacks);
		ft_error();
	}
}
