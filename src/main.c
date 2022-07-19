/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student-42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:29:37 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/19 19:49:47 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *s_a, t_stack *s_b)
{
	free(s_a->values);
	free(s_a->order);
	free(s_b->values);
	free(s_b->order);
	free(s_a);
	free(s_b);
}

void	error_parsing(t_stack *stack)
{
	ft_putstr_fd("Error\n", 1);
	free(stack->values);
	free(stack);
	exit(0);
}

t_stack	*create_stack_a(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	i = argc;
	stack_a = init_stack(argc - 1);
	while (--i)
	{
		if (check_num(argv[i]) && check_dup(argv, argc, i))
			push(stack_a, ft_atoi(argv[i]));
		else
			error_parsing(stack_a);
	}
	return (stack_a);
}

void	check_scenario(t_stack *s_a, t_stack *s_b)
{
	if (s_a->size == 2 && s_a->values[1] > s_a->values[0])
		swap(s_a, 1);
	else if (s_a->size <= 3)
		small_scenario(s_a);
	else if (s_a->size <= 5)
		medium_scenario(s_a, s_b);
	else
		big_scenario(s_a, s_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2 || !ft_strlen(argv[1]))
		exit(0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		stack_a = handle_argv(argv[1]);
	else
		stack_a = create_stack_a(argc, argv);
	stack_b = init_stack(stack_a->size);
	check_scenario(stack_a, stack_b);
//	print_stack(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
