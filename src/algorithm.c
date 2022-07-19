/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:14:25 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/19 19:50:13 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_scenario(t_stack *s_a)
{
	int	*n;

	n = s_a->values;
	if (n[2] > n[1] && n[2] < n[0] && n[1] < n[0])
		swap(s_a, 1);
	else if (n[2] > n[1] && n[2] > n[0] && n[1] > n[0])
	{
		swap(s_a, 1);
		reverse_rotate(s_a, 1);
	}
	else if (n[2] > n[1] && n[2] > n[0] && n[1] < n[0])
		rotate(s_a, 1);
	else if (n[2] < n[1] && n[2] < n[0] && n[1] > n[0])
	{
		swap(s_a, 1);
		rotate(s_a, 1);
	}
	else if (n[2] < n[1] && n[2] > n[0] && n[1] > n[0])
		reverse_rotate(s_a, 1);
}

void	push_smallest(t_stack *s_a, t_stack *s_b)
{
	int	i;
	int	value;

	i = find_smallest(s_a);
	value = s_a->values[i];
	if (i >= s_a->top / 2)
	{
		while (s_a->values[s_a->top] != value)
			rotate(s_a, 1);
	}
	else
		while (s_a->values[s_a->top] != value)
			reverse_rotate(s_a, 1);
	push_b(s_a, s_b);
}

void	medium_scenario(t_stack *s_a, t_stack *s_b)
{
	push_smallest(s_a, s_b);
	if (s_a->size == 5)
		push_smallest(s_a, s_b);
	small_scenario(s_a);
	push_a(s_a, s_b);
	if (s_a->size == 5)
		push_a(s_a, s_b);
}

void	index_stack(t_stack *stack)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (i < stack->size)
	{
		j = 0;
		count = 0;
		while (j < stack->size)
		{
			if (stack->values[i] > stack->values[j])
				count++;
			++j;
		}
		stack->order[i++] = count;
	}
}

void	big_scenario(t_stack *s_a, t_stack *s_b)
{
	(void)s_b;
	index_stack(s_a);
}
