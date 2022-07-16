/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_op_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:39:44 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/16 18:43:33 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rrr(t_stack *s_a, t_stack *s_b)
{
	reverse_rotate(s_a, 0);
	reverse_rotate(s_b, 0);
	ft_putstr_fd("rrr\n", 1);
}

void	push_a(t_stack *s_a, t_stack *s_b)
{
	push(s_b, pop(s_a));
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack *s_a, t_stack *s_b)
{
	push(s_a, pop(s_b));
	ft_putstr_fd("pb\n", 1);
}
