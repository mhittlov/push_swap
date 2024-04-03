/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhittlov <mhittlov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:54:14 by mhittlov          #+#    #+#             */
/*   Updated: 2024/02/03 19:02:02 by mhittlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	int	temp_nb;
	int	temp_index;
	int	i;

	if (stack->size < 2)
		return ;
	temp_nb = stack->nb[0];
	temp_index = stack->index[0];
	i = 0;
	while (i < stack->size)
	{
		stack->nb[i] = stack->nb[i + 1];
		stack->index[i] = stack->index[i + 1];
		i++;
	}
	stack->nb[stack->size - 1] = temp_nb;
	stack->index[stack->size - 1] = temp_index;
}

void	ft_ra(t_stacks *stacks)
{
	rotate(&stacks->a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stacks *stacks)
{
	rotate(&stacks->b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stacks *stacks)
{
	ft_ra(stacks);
	ft_rb(stacks);
	write(1, "rr\n", 3);
}
