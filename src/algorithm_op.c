/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:25:11 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/16 18:35:58 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack, int print)
{
	int	swap[2];

	if (stack->top < 1)
		return (1);
	swap[0] = pop(stack);
	swap[1] = pop(stack);
	push(stack, swap[0]);
	push(stack, swap[1]);
	if (print == 1)
		ft_putstr_fd("sa\n", 1);
	else if (print == 2)
		ft_putstr_fd("sb\n", 1);
	return (0);
}

void	ss(t_stack *s_a, t_stack *s_b)
{
	swap(s_a, 0);
	swap(s_b, 0);
	ft_putstr_fd("ss\n", 1);
}

int	rotate(t_stack *stack, int print)
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
	push(stack, rotate[0]);
	while (stack->top < n)
		push(stack, rotate[--i]);
	free(rotate);
	if (print == 1)
		ft_putstr_fd("ra\n", 1);
	else if (print == 2)
		ft_putstr_fd("rb\n", 1);
	return (0);
}

void	rr(t_stack *s_a, t_stack *s_b)
{
	rotate(s_a, 0);
	rotate(s_b, 0);
	ft_putstr_fd("rr\n", 1);
}
