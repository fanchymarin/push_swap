/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_use.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student-42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:45:45 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/06/14 17:47:33 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **top, int num)
{
	t_stack	*newnode;

	newnode = (t_stack *) ft_calloc(sizeof(t_stack), 1);
	newnode->value = num;
	newnode->next = *top;
	*top = newnode;
}

void	free_stack(t_stack **top)
{
	t_stack	*tmp;

	while (*top)
	{
		tmp = *top;
		*top = (*top)->next;
		free(tmp);
	}
	free(top);
}
