/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:14:25 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/21 16:23:47 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_scenario(t_stack *a)
{
	int	*n;

	n = a->values;
	if (n[2] > n[1] && n[2] < n[0] && n[1] < n[0])
		swap(a, 1);
	else if (n[2] > n[1] && n[2] > n[0] && n[1] > n[0])
	{
		swap(a, 1);
		reverse_rotate(a, 1);
	}
	else if (n[2] > n[1] && n[2] > n[0] && n[1] < n[0])
		rotate(a, 1);
	else if (n[2] < n[1] && n[2] < n[0] && n[1] > n[0])
	{
		swap(a, 1);
		rotate(a, 1);
	}
	else if (n[2] < n[1] && n[2] > n[0] && n[1] > n[0])
		reverse_rotate(a, 1);
}

void	push_by_index(t_stack *a, t_stack *b, int i)
{
	int	value;

	value = a->values[i];
	if (i >= a->top / 2)
	{
		while (a->values[a->top] != value)
			rotate(a, 1);
	}
	else
		while (a->values[a->top] != value)
			reverse_rotate(a, 1);
	push_b(a, b);
}

void	medium_scenario(t_stack *a, t_stack *b)
{
	push_by_index(a, b, find_smallest(a));
	if (a->size == 5)
		push_by_index(a, b, find_smallest(a));
	small_scenario(a);
	push_a(a, b);
	if (a->size == 5)
		push_a(a, b);
}

void	index_stack(t_stack *stack)
{
	int	i;
	int	j;
	int	count;
	int	*order;

	i = 0;
	j = 0;
	order = (int *) malloc(sizeof(int) * stack->size);
	while (i < stack->size)
	{
		j = 0;
		count = 1;
		while (j < stack->size)
		{
			if (stack->values[i] > stack->values[j])
				count++;
			++j;
		}
		order[i++] = count;
	}
	i = -1;
	while (++i < stack->size)
		stack->values[i] = order[i];
	free(order);
}

void	big_scenario(t_stack *a, t_stack *b)
{
	(void)b;
	index_stack(a);
	chunks_to_b(a, b);
}
