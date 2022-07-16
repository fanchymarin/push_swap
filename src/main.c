/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student-42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:29:37 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/16 14:07:29 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_stack *stack)
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
			error(stack_a);
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		exit(0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		stack_a = handle_argv(argv[1]);
	else
		stack_a = create_stack_a(argc, argv);
	print_stack(stack_a);
	free(stack_a->values);
	free(stack_a);
	return (0);
}
