/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:57:34 by lperroti          #+#    #+#             */
/*   Updated: 2023/02/26 00:25:00 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	sort_3elems(int *pile_a, int *pile_b, int *pile_s)
{
	while (!array_issort(pile_a, sort_handler))
	{
		if ((long)array_indexof(pile_s, pile_a)
			- (long)array_indexof(pile_s, pile_a + 1) == 1)
			do_op(pile_a, pile_b, SA);
		if ((long)array_indexof(pile_s, pile_a + 1)
			- (long)array_indexof(pile_s, pile_a + 2) == 1)
			do_op(pile_a, pile_b, PB);
		if ((long)array_indexof(pile_s, pile_a)
			- (long)array_indexof(pile_s, pile_a + 2) == 1)
			do_op(pile_a, pile_b, RA);
		if (array_size(pile_a) != 3)
			do_op(pile_a, pile_b, PA);
	}
	return (true);
}