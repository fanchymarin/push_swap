/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:32:58 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/21 15:39:25 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i <= stack->top)
	{
		j = 0;
		while (j <= stack->top)
		{
			if (stack->values[i] > stack->values[j])
				break ;
			++j;
		}
		if (j == stack->top + 1)
			break ;
		i++;
	}
	return (i);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free(a->values);
	free(b->values);
	free(a);
	free(b);
}
