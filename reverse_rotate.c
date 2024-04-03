/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhittlov <mhittlov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:54:10 by mhittlov          #+#    #+#             */
/*   Updated: 2024/02/03 19:04:44 by mhittlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	int	temp_nb;
	int	temp_index;
	int	i;

	if (stack->size < 2)
		return ;
	temp_nb = stack->nb[stack->size - 1];
	temp_index = stack->index[stack->size - 1];
	i = stack->size;
	while (i > 0)
	{
		stack->nb[i] = stack->nb[i - 1];
		stack->index[i] = stack->index[i - 1];
		i--;
	}
	stack->nb[0] = temp_nb;
	stack->index[0] = temp_index;
}

void	ft_rra(t_stacks *stacks)
{
	reverse_rotate(&stacks->a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stacks *stacks)
{
	reverse_rotate(&stacks->b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stacks *stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
	write(1, "rrr\n", 4);
}
