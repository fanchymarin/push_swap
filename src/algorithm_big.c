/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:53:47 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/23 18:22:06 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_or_bottom(t_stack *stack, int sup_limit, int inf_limit)
{
	int	i;
	int	j;

	i = 0;
	j = stack->top;
	while (i < j)
	{
		if (stack->values[i] > sup_limit || stack->values[i] < inf_limit
			|| stack->values[i] == stack->size / 2)
			++i;
		if (stack->values[j] > sup_limit || stack->values[j] < inf_limit
			|| stack->values[j] == stack->size / 2)
			--j;
		if ((stack->values[i] <= sup_limit && stack->values[i] >= inf_limit)
			&& (stack->values[j] <= sup_limit && stack->values[j] >= inf_limit))
		{
			if (i < (stack->top - j))
				return (i);
			else
				return (j);
		}
	}
	return (-1);
}

void	chunks_to_b(t_stack *a, t_stack *b)
{
	int	i;
	int	left_to_push;
	int	range;

	range = a->size / 2;
	left_to_push = a->size - range;
	while (a->top)
	{
		while (left_to_push)
		{
			i = top_or_bottom(a, range + CHUNK_SIZE, range);
			if (i == -1)
				range += CHUNK_SIZE;
			else
			{
				push_by_index_a(a, b, i);
				--left_to_push;
			}
			if (i == -1 && !a->top)
				break ;
		}
		left_to_push = a->top + 1;
		range = 1;
	}
}

void	push_back(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	index;

	i = a->size / 2 + 2;
	j = a->size / 2 - 2;
	while (b->top != -1)
	{
		print_stack(a, b);
		if (b->values[top_or_bottom(b, i, j)] < b->size / 2)
		{
			index = top_or_bottom(b, j + 1, j);
			while (index != -1)
			{
				push_by_index_b(a, b, index);
				index = top_or_bottom(b, j + 1, j);
			}
			if (a->values[a->top] > a->values[a->top - 1])
				swap(a, 1);
			j -= 2;
		}
		else if (b->values[top_or_bottom(b, i, j)] > b->size / 2)
		{
			index = top_or_bottom(b, i, i - 1);
			while (index != -1)
			{
				push_by_index_b(a, b, index);
				index = top_or_bottom(b, i, i - 1);
			}
			if (a->values[a->top] > a->values[a->top - 1])
				swap(a, 1);
			if (a->values[a->top] == a->values[a->top - 1] - 1)
				rotate(a, 1);
			rotate(a, 1);
			i += 2;
		}
	}
}
