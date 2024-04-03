/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhittlov <mhittlov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:54:07 by mhittlov          #+#    #+#             */
/*   Updated: 2024/02/03 18:41:40 by mhittlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	int	i;
	int	j;
	int	temp_nb;
	int	temp_index;

	if (src->size == 0)
		return ;
	i = dest->size + 1;
	j = -1;
	temp_nb = src->nb[0];
	temp_index = src->index[0];
	while (--i > 0)
	{
		dest->nb[i] = dest->nb[i - 1];
		dest->index[i] = dest->index[i - 1];
	}
	while (++j < src->size)
	{
		src->nb[j] = src->nb[j + 1];
		src->index[j] = src->index[j + 1];
	}
	dest->nb[0] = temp_nb;
	dest->index[0] = temp_index;
	src->size--;
	dest->size++;
}

void	ft_pa(t_stacks *stacks)
{
	push(&stacks->b, &stacks->a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stacks *stacks)
{
	push(&stacks->a, &stacks->b);
	write(1, "pb\n", 3);
}
