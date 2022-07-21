/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:53:47 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/07/21 16:58:01 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_chunk(t_stack *a)
{
	int	*chunks;
	int	i;

	chunks = (int *) malloc(sizeof(int) * (a->size / CHUNK_SIZE));
	i = 0;
	while (++i < (a->size / CHUNK_SIZE))
		chunks[i] = CHUNK_SIZE * i;
	chunks[--i] = a->size;
	return (chunks);
}

int	

void	push_chunk(t_stack *a, t_stack *b, int chunk_values)
{
	int	left_to_push;

	if (chunk_values % CHUNK_SIZE)
		left_to_push = chunk_values % CHUNK_SIZE;
	else
		left_to_push = CHUNK_SIZE;
	while (left_to_push)
	{
		push_by_index(a, b, top_or_bottom(a, chunk_values));
		--left_to_push;
	}
}

void	chunks_to_b(t_stack *a, t_stack *b)
{
	int	*chunks;
	int	i;

	chunks = create_chunk(a);
	i = ((a->size / CHUNK_SIZE) / 2) - 1;
	while (++i < (a->size / CHUNK_SIZE))
		push_chunk(a, b, chunks[i]);
	i = ((a->size / CHUNK_SIZE) / 2);
	while (--i > -1)
		push_chunk(a, b, chunks[i]);
	free(chunks);
}
