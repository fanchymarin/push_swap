/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:14:25 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/26 18:44:56 by fmarin-p         ###   ########.fr       */
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

void	push_by_index_a(t_stack *a, t_stack *b, int i)
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

void	push_by_index_b(t_stack *a, t_stack *b, int i)
{
	int	value;

	value = b->values[i];
	if (i >= b->top / 2)
	{
		while (b->values[b->top] != value)
			rotate(b, 2);
	}
	else
		while (b->values[b->top] != value)
			reverse_rotate(b, 2);
	push_a(a, b);
}

void	medium_scenario(t_stack *a, t_stack *b)
{
	push_by_index_a(a, b, find_smallest(a));
	if (a->size == 5)
		push_by_index_a(a, b, find_smallest(a));
	small_scenario(a);
	push_a(a, b);
	if (a->size == 5)
		push_a(a, b);
}

void	big_scenario(t_stack *a, t_stack *b)
{
	index_stack(a);
	chunks_to_b(a, b, (0.075 * a->size + 12.5));
	push_back(a, b);
}
