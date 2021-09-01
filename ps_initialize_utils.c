/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initialize_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricky <kricky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:27:39 by                   #+#    #+#             */
/*   Updated: 2021/09/01 13:37:13 by kricky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_args(int argc, char **argv)
{
	int	i;
	int	result;

	i = 1;
	result = 0;
	while (i < argc)
	{
		result += ft_wdcounter(argv[i], ' ');
		i++;
	}
	return (result);
}

char	**ft_clear_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}
