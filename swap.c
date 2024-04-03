/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhittlov <mhittlov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:54:18 by mhittlov          #+#    #+#             */
/*   Updated: 2024/02/03 18:55:57 by mhittlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp_nb;
	int	temp_index;

	if (stack->size < 2)
		return ;
	temp_nb = stack->nb[0];
	temp_index = stack->index[0];
	stack->nb[0] = stack->nb[1];
	stack->index[0] = stack->index[1];
	stack->nb[1] = temp_nb;
	stack->index[1] = temp_index;
}

void	ft_sa(t_stacks *stacks)
{
	swap(&stacks->a);
	write (1, "sa\n", 3);
}

void	ft_sb(t_stacks *stacks)
{
	swap(&stacks->b);
	write (1, "sb\n", 3);
}

void	ft_ss(t_stacks *stacks)
{
	swap(&stacks->a);
	swap(&stacks->b);
	write (1, "ss\n", 3);
}
