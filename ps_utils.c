/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/20 00:41:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(const t_collection *stacks, const char array)
{
	t_stack	*head;

	if (array == 'a')
		head = stacks->a;
	else
		head = stacks->b;
	while (head)
	{
		ft_putnbr_fd(head->value, 1);
		ft_putstr_fd(" ", 1);
		head = head->next;
	}
	ft_putstr_fd("<- root\n", 1);
	ft_putstr_fd("Length: ", 1);
	if (array == 'a')
		ft_putnbr_fd(stacks->counter_a, 1);
	else
		ft_putnbr_fd(stacks->counter_b, 1);
	ft_putstr_fd("\n", 1);
}
