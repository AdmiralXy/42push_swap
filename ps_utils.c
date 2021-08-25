/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/25 22:19:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_print_helper(const t_collection *stacks, const char array)
{
	if (array == 'a')
	{
		ft_putstr_fd("---------------------------   "
			"A Stack   ---------------------------\n", 1);
		return (stacks->a);
	}
	else
	{
		ft_putstr_fd("---------------------------   "
			"B Stack   ---------------------------\n", 1);
		return (stacks->b);
	}
}

void	ft_print_stack(const t_collection *stacks, const char array)
{
	t_stack	*head;

	head = ft_print_helper(stacks, array);
	while (head)
	{
		ft_putnbr_fd(head->value, 1);
		ft_putstr_fd(" ", 1);
		head = head->next;
	}
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Length: ", 1);
	if (array == 'a')
		ft_putnbr_fd(stacks->counter_a, 1);
	else
		ft_putnbr_fd(stacks->counter_b, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("------------------------------"
		"-------------------------------------\n\n\n", 1);
}
