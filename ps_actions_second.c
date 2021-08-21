/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/20 00:34:05 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_collection *stacks, int print)
{
	ft_swap_top(stacks->a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_collection *stacks, int print)
{
	ft_swap_top(stacks->b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ft_pa(t_collection *stacks, int print)
{
	ft_send_top(stacks, 'a');
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_collection *stacks, int print)
{
	ft_send_top(stacks, 'b');
	if (print)
		ft_putstr_fd("pb\n", 1);
}
