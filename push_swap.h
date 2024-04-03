/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhittlov <mhittlov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:00:29 by mhittlov          #+#    #+#             */
/*   Updated: 2024/02/10 13:30:51 by mhittlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*nb;
	int	*index;
	int	size;
}				t_stack;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
}				t_stacks;

void			ft_putstr_fd(char *s, int fd);
void			ft_free_error(char *message, t_stacks *stacks);
void			ft_free_exit(t_stacks *stacks);
void			ft_free_split(char **split_args, int count_args);

void			ft_sa(t_stacks *stacks);
void			ft_sb(t_stacks *stacks);
void			ft_ss(t_stacks *stacks);
void			ft_pa(t_stacks *stacks);
void			ft_pb(t_stacks *stacks);
void			ft_ra(t_stacks *stacks);
void			ft_rb(t_stacks *stacks);
void			ft_rr(t_stacks *stacks);
void			ft_rra(t_stacks *stacks);
void			ft_rrb(t_stacks *stacks);
void			ft_rrr(t_stacks *stacks);

void			ft_update_index(t_stacks *stacks);
int				ft_index_min(int *numbers, int size);
void			ft_move_min_to_b(t_stacks *stacks);

int				ft_sorted(t_stacks *stacks);
int				ft_duplicate(int number, t_stack stack);
int				ft_number(char *str);
long			ft_atol(const char *str);

void			ft_sort_3(t_stacks *stacks);
void			ft_sort_4(t_stacks *stacks);
void			ft_sort_5(t_stacks *stacks);
void			ft_sort_radix(t_stacks *stacks);

void			*ft_calloc(size_t count, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);

int				main(int argc, char **argv);

#endif