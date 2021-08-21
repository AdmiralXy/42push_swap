/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_third.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 00:34:19 by                   #+#    #+#             */
/*   Updated: 2021/08/20 00:34:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_collection *stacks, int print)
{
	ft_sa(stacks, 0);
	ft_sb(stacks, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}

void	ft_rr(t_collection *stacks, int print)
{
	ft_ra(stacks, 0);
	ft_rb(stacks, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
}

void	ft_rrr(t_collection *stacks, int print)
{
	ft_rra(stacks, 0);
	ft_rrb(stacks, 0);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
