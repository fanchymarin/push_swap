/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student-42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:19:05 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/16 14:09:18 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*values;
	int	size;
	int	top;
}	t_stack;

t_stack	*create_stack_a(int argc, char **argv);

int		check_num(char *num);
int		check_dup(char **argv, int argc, int i);
t_stack	*handle_argv(char *argv);

void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	print_stack(t_stack *stack);
t_stack	*init_stack(int size);

#endif
