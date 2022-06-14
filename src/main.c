/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student-42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:29:37 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/06/14 17:50:53 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_stack **top)
{
	write(1, "Error\n", 6);
	free_stack(top);
	exit(0);
}

int	check_num(char *num)
{
	int	i;
	int	n;

	i = 0;
	while (num[i])
	{
		if (num[i] < 48 && num[i] > 57 && num[i] != '-' && num[i] != '+')
			return (0);
		i++;
	}
	i -= 1;
	n = ft_atoi(num);
	if (n == -2147483648)
		return (1);
	if (n < 0)
		n *= -1;
	if (n % 10 != num[i] - 48)
		return (0);
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

t_stack	**create_stack(int argc, char **argv)
{
	int		i;
	t_stack	**top;

	i = argc;
	top = (t_stack **) ft_calloc(sizeof(t_stack *), 1);
	while (--i)
	{
		if (check_num(argv[i]) && check_dup(argv, argc, i))
			push(top, ft_atoi(argv[i]));
		else
			error(top);
	}
	return (top);
}

int	main(int argc, char **argv)
{
	t_stack	**top;

	if (argc < 2)
		exit(0);
	top = create_stack(argc, argv);
	free_stack(top);
	return (0);
}
