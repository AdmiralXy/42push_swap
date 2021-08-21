#include "push_swap.h"

int		ft_find_smaller_index(t_stack *stack)
{
	int		i;
	int		index;
	int		min;

	min = 2147483647;
	i = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

void	ft_run_ra_rra(t_collection *stacks, char direction, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (direction == 0)
			ft_ra(stacks, 1);
		else
			ft_rra(stacks, 1);
		i++;
	}
}

void	ft_move_to_b(t_collection *stacks)
{
	int smaller_i;

	smaller_i = ft_find_smaller_index(stacks->a);
	if (smaller_i < stacks->counter_a / 2)
		ft_run_ra_rra(stacks, 0, smaller_i);
	else
		ft_run_ra_rra(stacks, 1, stacks->counter_a - smaller_i);
	ft_pb(stacks, 1);
}
