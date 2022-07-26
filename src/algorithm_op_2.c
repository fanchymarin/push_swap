/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_op_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:39:44 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/26 18:11:17 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	reverse_rotate(t_stack *stack, int print)
{
	int	*rotate;
	int	n;
	int	i;

	if (stack->top < 1)
		return (1);
	i = 0;
	n = stack->top;
	rotate = (int *) malloc(sizeof(int) * n + 1);
	while (stack->top > -1)
		rotate[i++] = pop(stack);
	i--;
	while (stack->top < n - 1)
		push(stack, rotate[--i]);
	push(stack, rotate[n]);
	free(rotate);
	if (print == 1)
		ft_putstr_fd("rra\n", 1);
	else if (print == 2)
		ft_putstr_fd("rrb\n", 1);
	return (0);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	ft_putstr_fd("rrr\n", 1);
}

void	push_a(t_stack *a, t_stack *b)
{
	push(a, pop(b));
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack *a, t_stack *b)
{
	push(b, pop(a));
	ft_putstr_fd("pb\n", 1);
}
