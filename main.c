/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhittlov <mhittlov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:45:43 by mhittlov          #+#    #+#             */
/*   Updated: 2024/02/03 17:03:17 by mhittlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_argv(int argc, char **argv, t_stacks *stacks, int index)
{
	long	temp;

	stacks->a.size = 0;
	stacks->b.size = 0;
	stacks->a.nb = ft_calloc((argc - 1), sizeof(int));
	stacks->b.nb = ft_calloc((argc - 1), sizeof(int));
	stacks->a.index = ft_calloc((argc - 1), sizeof(int));
	stacks->b.index = ft_calloc((argc - 1), sizeof(int));
	if (!stacks->a.nb || !stacks->b.nb || !stacks->a.index || !stacks->b.index)
		ft_free_error("Error\n", stacks);
	while (++index < argc)
	{
		if (!ft_number(argv[index]))
			ft_free_error("Error\n", stacks);
		temp = ft_atol(argv[index]);
		if (temp < INT_MIN || temp > INT_MAX)
			ft_free_error("Error\n", stacks);
		if (ft_duplicate(temp, stacks->a))
			ft_free_error("Error\n", stacks);
		stacks->a.index[stacks->a.size] = (int)temp;
		stacks->a.nb[stacks->a.size] = (int)temp;
		stacks->a.size++;
	}
}

void	clean_argv(char *args, t_stacks *stacks)
{
	char	**split_args;
	int		count_args;

	split_args = ft_split(args, ' ');
	if (!split_args)
		ft_free_error("Error\n", stacks);
	count_args = 0;
	while (split_args[count_args] != NULL)
		count_args++;
	check_argv(count_args, split_args, stacks, -1);
	ft_free_split(split_args, count_args);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		ft_free_error("Error\n", stacks);
	if (argc == 2)
		clean_argv(argv[1], stacks);
	else
		check_argv(argc, argv, stacks, 0);
	if (ft_sorted(stacks))
		ft_free_error("", stacks);
	if (stacks->a.size == 2 && stacks->a.nb[0] > stacks->a.nb[1])
		ft_sa(stacks);
	else if (stacks->a.size == 3)
		ft_sort_3(stacks);
	else if (stacks->a.size == 4)
		ft_sort_4(stacks);
	else if (stacks->a.size == 5)
		ft_sort_5(stacks);
	else
		ft_sort_radix(stacks);
	ft_free_exit(stacks);
	return (0);
}
