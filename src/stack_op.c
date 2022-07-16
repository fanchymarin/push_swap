/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_use.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student-42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:45:45 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/16 12:56:53 by fmarin-p         ###   ########.fr       */
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

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i != -1)
	{
		ft_putnbr_fd(stack->values[i--], 1);
		ft_putstr_fd("\n", 1);
	}
}
