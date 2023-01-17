/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 05:21:02 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/17 08:45:35 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

bool	check_dup(int *pile_a)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < array_size(pile_a) - 1)
	{
		j = 0;
		while (i + j++ < array_size(pile_a) - 1)
		{
			if (pile_a[i] == pile_a[i + j])
				return (false);
		}
		i++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_array	pile_a;
	t_array	pile_b;

	if (ac < 2)
		return (1);
	pile_a = (int *)strtab_to_intarray(av + 1, ac - 1);
	pile_b = (int *)array_new(ac - 1, sizeof(int));
	if (!pile_a || !pile_b || !check_dup(pile_a) || !sort(pile_a, pile_b))
		lp_putendl_fd("Error", 2);
	array_free(pile_a);
	array_free(pile_b);
}
