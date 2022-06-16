/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student-42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:29:37 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/06/16 19:52:09 by fmarin-p         ###   ########.fr       */
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

int	check_num(char *num)
{
	int	i;
	int	n;

	i = -1;
	while (num[++i])
		if (num[i] < 48 && num[i] > 57 && num[i] != '-' && num[i] != '+')
			return (0);
	n = ft_atoi(num);
	if (n == -2147483648)
	{
		if (num[0] != '-')
			return (0);
		return (1);
	}
	if (n < 0)
		n *= -1;
	while (n)
	{
		if (n % 10 != num[--i] - 48)
			return (0);
		n /= 10;
	}
	return (1);
}

int	check_dup(char **argv, int argc, int i)
{
	int	num;

	num = i;
	i += 1;
	while (i < argc && i)
		if (ft_atoi(argv[num]) == ft_atoi(argv[i++]))
			return (0);
	return (1);
}

t_stack	*create_stack(int argc, char **argv)
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
	stack_a = create_stack(argc, argv);
	print_stack(stack_a);
	free(stack_a->values);
	free(stack_a);
	return (0);
}
