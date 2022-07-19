/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:25:27 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/19 19:49:47 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_error(int error)
{
	ft_putstr_fd("Error while stack handling: ", 1);
	if (!error)
		ft_putstr_fd("Stack full\n", 1);
	else if (error == 1)
		ft_putstr_fd("Stack empty\n", 1);
	exit(0);
}

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	stack->values = (int *) malloc(sizeof(int) * size);
	stack->order = (int *) malloc(sizeof(int) * size);
	stack->size = size;
	stack->top = -1;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	if (stack->top < stack->size - 1)
		stack->values[++stack->top] = value;
	else
		stack_error(0);
}

int	pop(t_stack *stack)
{
	if (stack->top <= -1)
		stack_error(1);
	return (stack->values[stack->top--]);
}

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

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	top_a;
	int	top_b;

	top_a = stack_a->top;
	top_b = stack_b->top;
	while (1)
	{
		if (top_a == -1 && top_b == -1)
			break ;
		if (top_a >= top_b && top_a > -1)
			ft_putnbr_fd(stack_a->values[top_a--], 1);
		ft_putstr_fd("      ", 1);
		if (top_b > top_a && top_b > -1)
			ft_putnbr_fd(stack_b->values[top_b--], 1);
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("---------\n", 1);
}
