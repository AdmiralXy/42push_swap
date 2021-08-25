/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/25 22:07:38 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	int				index;
	int				direction;
}					t_stack;

typedef struct s_collection
{
	t_stack			*a;
	t_stack			*b;
	int				min;
	int				max;
	int				counter_a;
	int				counter_b;
}					t_collection;

typedef struct s_actions
{
	int				direction_a;
	int				direction_b;
	int				offset_a;
	int				offset_b;
}					t_actions;

// Throw an error functions
void	ft_error(void);
void	ft_error_silence(void);

// Sorting functions
void	ft_sort(t_collection *stacks);
void	ft_sort_small(t_collection *stacks);
void	ft_sort_middle(t_collection *stacks);
void	ft_sort_large(t_collection *stacks);

// Sorting utils
void	ft_set_min_max(t_collection *stacks);
void	ft_setup_stack_properties(t_stack *stack, int n);
void	ft_selection_sort(t_collection *stacks);
int		ft_best_distance(t_collection *stacks, t_actions *actions, int dst);

// Initialization functions
void	ft_initialize(t_collection *stacks);
void	ft_fill_stack(int argc, char **argv, t_collection *stacks);

// Validation functions
int		ft_validation(int argc, char **argv, t_collection *stacks);
int		ft_is_sorted(t_stack *a);

// Utilities functions
void	ft_print_stack(const t_collection *stacks, char array);
int		ft_atoi_overflow(const char *str, t_collection *stacks);

// Clear functions
void	ft_clear_stacks(t_collection *stacks, int throw_exception);

// Actions utils
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);
void	ft_swap_top(t_stack *a);
void	ft_send_top(t_collection *stacks, char destination);

// Actions
void	ft_ra(t_collection *stacks, int print);
void	ft_rb(t_collection *stacks, int print);
void	ft_rra(t_collection *stacks, int print);
void	ft_rrb(t_collection *stacks, int print);

void	ft_sa(t_collection *stacks, int print);
void	ft_sb(t_collection *stacks, int print);
void	ft_pa(t_collection *stacks, int print);
void	ft_pb(t_collection *stacks, int print);

void	ft_ss(t_collection *stacks, int print);
void	ft_rr(t_collection *stacks, int print);
void	ft_rrr(t_collection *stacks, int print);

#endif