/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/08/21 18:19:34 by                  ###   ########.fr       */
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
	int				step;
	int				rotate;
	struct s_stack	*next;
}					t_stack;

typedef struct s_collection
{
	t_stack			*a;
	t_stack			*b;
	int				counter_a;
	int				counter_b;
	int				min;
	int				max;
	int				mid;
}					t_collection;

typedef struct s_actions
{
	int	counter_a;
	int	counter_b;
	int	destination_a;
	int	destination_b;
}		t_actions;

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
void	ft_move_to_b(t_collection *stacks);

// Initialization functions
void	ft_initialize(t_collection *stacks);
void	ft_fill_stack(int argc, char **argv, t_collection *stacks);

// Validation functions
int		ft_validation(int argc, char **argv);
int		ft_is_sorted(t_stack *a);

// Utilities functions
void	ft_print_stack(const t_collection *stacks, char array);
int		ft_atoi_overflow(const char *str);

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