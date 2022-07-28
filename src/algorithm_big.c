/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:53:47 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/28 19:18:43 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_or_bottom(t_stack *stack, int sup_limit, int inf_limit)
{
	int	i;
	int	j;

	i = 0;
	j = stack->top;
	while (i <= j)
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

void	chunks_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	range_down;
	int	range_up;
	int	left_to_push;

	range_down = a->size / 2 - chunk_size;
	range_up = a->size / 2 + chunk_size;
	while (range_down + chunk_size > 0)
	{
		left_to_push = chunk_size / 2 + 1;
		while (--left_to_push)
		{
			push_by_index_a(a, b, top_or_bottom(a, range_up, range_up - chunk_size));
			push_by_index_a(a, b, top_or_bottom(a, range_down + chunk_size, range_down));
		}
		range_up += chunk_size;
		range_down -= chunk_size;
	}
	range_up = a->size;
	range_down = 0;
	while (range_down < range_up)
	{
		while (!push_by_index_a(a, b, top_or_bottom(a, range_up, range_up - chunk_size)) &&	!push_by_index_a(a, b, top_or_bottom(a, range_down + chunk_size, range_down)));
		range_up -= chunk_size;
		range_down += chunk_size;
	}
	print_stack(a, b);
	exit(1);
}
/*
void	chunks_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	left_to_push;
	int	range;

	range = a->size / 2 + 1;
	left_to_push = a->size - range;
	while (a->top)
	{
		while (left_to_push)
		{
			if (push_by_index_a(a, b, top_or_bottom(a, range + chunk_size, range)))
				range += chunk_size;
			else
				--left_to_push;
			if (!a->top)
				break ;
		}
		left_to_push = a->top + 1;
		range = 1;
	}
}
*/
void	push_by_pairs(t_stack *a, t_stack *b, int *i, int *j)
{
	if (a->values[a->top] == *j)
	{
		push_by_index_b(a, b, top_or_bottom(b, *j + 1, *j + 1));
		swap(a, 1);
		*j -= 2;
	}
	else if (a->values[a->top] == *i)
	{
		push_by_index_b(a, b, top_or_bottom(b, *i - 1, *i - 1));
		rotate(a, 1);
		rotate(a, 1);
		*i += 2;
	}
}

void	push_back(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = a->size / 2 + 2;
	j = a->size / 2 - 2;
	while (b->top != -1)
	{
		push_by_index_b(a, b, top_or_bottom(b, i, j));
		if (a->values[a->top] == j + 1)
			j--;
		else if (a->values[a->top] == i - 1)
		{
			rotate(a, 1);
			i++;
		}
		else
			push_by_pairs(a, b, &i, &j);
	}
}
