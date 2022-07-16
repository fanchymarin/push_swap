/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:06:41 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/16 18:06:08 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *num)
{
	int	i;
	int	n;

	i = -1;
	while (num[++i])
		if ((num[i] < 48 || num[i] > 57) && (num[i] != '-' && num[i] != '+'))
			return (0);
	n = ft_atoi(num);
	if (!n && num[i - 1] != 48)
		return (0);
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
	i++;
	while (i < argc && i)
		if (ft_atoi(argv[num]) == ft_atoi(argv[i++]))
			return (0);
	return (1);
}

t_stack	*handle_argv(char *argv)
{
	t_stack	*stack_a;
	char	*argv_2;
	char	**numbers;
	int		argc;
	int		i;

	i = -1;
	argc = 0;
	argv = ft_strtrim(argv, " ");
	argv_2 = ft_strjoin("./push_swap ", argv);
	free(argv);
	numbers = ft_split(argv_2, ' ');
	free(argv_2);
	while (numbers[++i])
		++argc;
	stack_a = create_stack_a(argc, numbers);
	i = -1;
	while (numbers[++i])
		free(numbers[i]);
	free(numbers);
	return (stack_a);
}
