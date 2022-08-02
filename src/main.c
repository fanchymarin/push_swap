/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student-42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:29:37 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/08/02 16:33:26 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_sorted(t_stack *a)
{
	int	i;

	i = -1;
	while (++i < a->size - 1)
		if (a->values[i] < a->values[i + 1])
			return ;
	exit(1);
}

void	check_scenario(t_stack *a, t_stack *b)
{
	check_if_sorted(a);
	if (a->size == 2)
		swap(a, 1);
	else if (a->size == 3)
		small_scenario(a);
	else if (a->size <= 5)
		medium_scenario(a, b);
	else
		big_scenario(a, b);
}

t_stack	*create_stack_a(int argc, char **argv)
{
	int		i;
	t_stack	*a;

	i = argc;
	a = init_stack(argc - 1);
	while (--i)
	{
		if (check_num(argv[i]) && check_dup(argv, argc, i))
			push(a, ft_atoi(argv[i]));
		else
			error_parsing(a);
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || !ft_strlen(argv[1]))
		exit(0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		a = handle_argv(argv[1]);
	else
		a = create_stack_a(argc, argv);
	b = init_stack(a->size);
	check_scenario(a, b);
	free_stacks(a, b);
	return (0);
}
