/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricky <kricky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/09/01 13:51:16 by kricky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_collection *stacks)
{
	ft_set_min_max(stacks);
	if (stacks->counter_a <= 3)
		ft_sort_small(stacks);
	else if (stacks->counter_a <= 5)
		ft_sort_middle(stacks);
	else
		ft_sort_large(stacks);
}

int	main(int argc, char **argv)
{
	t_collection	*stacks;

	if (argc < 2)
		ft_error_silence();
	stacks = malloc(sizeof(t_collection));
	if (!stacks)
		ft_error_silence();
	ft_initialize(stacks);
	if (ft_validation(argc, argv, stacks))
	{
		ft_fill_stack(argc, argv, stacks);
		if (!ft_is_sorted(stacks->a))
			ft_sort(stacks);
		ft_clear_stacks(stacks, 0);
	}
	free(stacks);
}
