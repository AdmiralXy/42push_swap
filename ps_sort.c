/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/24 22:04:13 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small(t_collection *stacks)
{
	int	top;
	int	mid;
	int	bot;

	if (stacks->counter_a == 2)
		ft_sa(stacks, 1);
	else
	{
		top = stacks->a->value;
		mid = stacks->a->next->value;
		bot = stacks->a->next->next->value;
		if ((top > mid && mid > bot) || (top < mid && mid > bot && top < bot))
		{
			ft_sa(stacks, 1);
			top = stacks->a->value;
			mid = stacks->a->next->value;
			bot = stacks->a->next->next->value;
		}
		if (top > mid && mid < bot && top < bot)
			ft_sa(stacks, 1);
		else if (top > mid && mid < bot && top > bot)
			ft_ra(stacks, 1);
		else if (top < mid && mid > bot)
			ft_rra(stacks, 1);
	}
}

void	ft_sort_middle(t_collection *stacks)
{
	while (stacks->counter_b < 2)
	{
		if (stacks->a->value == stacks->min || stacks->a->value == stacks->max)
			ft_pb(stacks, 1);
		else
			ft_ra(stacks, 1);
	}
	if (!ft_is_sorted(stacks->a))
		ft_sort_small(stacks);
	ft_pa(stacks, 1);
	ft_pa(stacks, 1);
	if (stacks->a->value == stacks->max)
		ft_ra(stacks, 1);
	else
	{
		ft_sa(stacks, 1);
		ft_ra(stacks, 1);
	}
}

void	ft_sort_large(t_collection *stacks)
{
	while (stacks->counter_a != 2)
	{
		if (stacks->a->value != stacks->min && stacks->a->value != stacks->max)
			ft_pb(stacks, 1);
		else
			ft_ra(stacks, 1);
	}
	if (stacks->a->value < stacks->a->next->value)
		ft_sa(stacks, 1);
	ft_pa(stacks, 1);
	ft_selection_sort(stacks);
}
