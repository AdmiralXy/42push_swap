/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/31 01:18:34 by                  ###   ########.fr       */
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

void	ft_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(EXIT_FAILURE);
}

void	ft_error_silence(void)
{
	exit(EXIT_FAILURE);
}
