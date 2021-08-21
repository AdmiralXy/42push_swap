/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/19 23:34:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_collection *stacks, int print)
{
	ft_rotate(&stacks->a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_collection *stacks, int print)
{
	ft_rotate(&stacks->b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rra(t_collection *stacks, int print)
{
	ft_reverse_rotate(&stacks->a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_collection *stacks, int print)
{
	ft_reverse_rotate(&stacks->b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}
