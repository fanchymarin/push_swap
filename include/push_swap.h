/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student-42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:19:05 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/22 15:41:41 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define CHUNK_SIZE 10

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
void	error_parsing(t_stack *stack);

void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	print_stack(t_stack *stack_a, t_stack *stack_b);
int		find_smallest(t_stack *stack);
t_stack	*init_stack(int size);
void	free_stacks(t_stack *a, t_stack *b);

int		swap(t_stack *stack, int print);
void	ss(t_stack *a, t_stack *b);
int		rotate(t_stack *stack, int print);
void	rr(t_stack *a, t_stack *b);
int		reverse_rotate(t_stack *stack, int print);
void	rrr(t_stack *a, t_stack *b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);

void	small_scenario(t_stack *a);
void	medium_scenario(t_stack *a, t_stack *b);
void	big_scenario(t_stack *a, t_stack *b);

void	push_by_index(t_stack *a, t_stack *b, int i);
void	chunks_to_b(t_stack *a, t_stack *b);

#endif
