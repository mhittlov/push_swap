/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhittlov <mhittlov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:20:29 by mhittlov          #+#    #+#             */
/*   Updated: 2024/02/05 19:29:30 by mhittlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	str_len(char *str)
{
	size_t	a;

	a = 0;
	while (*(str + a))
		a++;
	return (a);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, str_len(s));
	}
}
