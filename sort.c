/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 07:51:07 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/17 12:15:03 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

bool	sort_handler(void *a, void *b)
{
	return (*(int *)a <= *(int *)b);
}

bool	sort3(int *pile_a, int *pile_b)
{
	if (array_size(pile_a) == 3)
	{
		if (!sort_handler(pile_a, pile_a + 1)
			&& (
				!sort_handler(pile_a + 1, pile_a + 2)
				|| !sort_handler(pile_a + 2, pile_a)
			)
		)
			do_op(pile_a, pile_b, SA);
		else if (!sort_handler(pile_a + 1, pile_a + 2)
			&& !sort_handler(pile_a + 2, pile_a))
		{
			do_op(pile_a, pile_b, RA);
			do_op(pile_a, pile_b, SA);
		}
	}
	return (true);
}

bool	pa_insert_sort(int *pile_a, int *pile_b, int *pile_sorted)
{
	size_t	sorted_index;
	size_t	pile_b_index;

	sorted_index = array_size(pile_sorted);
	while (sorted_index--)
	{
		pile_b_index = 0;
		while (pile_b[pile_b_index] != pile_sorted[sorted_index])
			pile_b_index++;
		if (pile_b_index < array_size(pile_b) / 2)
			while (pile_b[0] != pile_sorted[sorted_index])
				do_op(pile_a, pile_b, RB);
		else
			while (pile_b[0] != pile_sorted[sorted_index])
				do_op(pile_a, pile_b, RRB);
		do_op(pile_a, pile_b, PA);
	}
	return (true);
}

bool	pb_elem(int *pile_a, int *pile_b, size_t index)
{
	if (index < array_size(pile_a) / 2)
		while (index-- > 0)
			do_op(pile_a, pile_b, RA);
	else
		while (index++ < array_size(pile_a))
			do_op(pile_a, pile_b, RRA);
	do_op(pile_a, pile_b, PB);
	return (true);
}

bool	pb_by_medianes(int *pile_a, int *pile_b, int *pile_s)
{
	size_t	mediane_index;
	int		mediane;
	size_t	i;

	mediane_index = 0;
	while (array_size(pile_a))
	{
		mediane_index += array_size(pile_s) / 10;
		if (!mediane_index || mediane_index > array_size(pile_s) - 1)
			mediane_index = array_size(pile_s) - 1;
		mediane = pile_s[mediane_index];
		i = 0;
		while (i < array_size(pile_a))
		{
			if (pile_a[i] <= mediane)
			{
				pb_elem(pile_a, pile_b, i);
				i = 0;
			}
			else if (i && pile_a[array_size(pile_a) - i] <= mediane)
			{
				pb_elem(pile_a, pile_b, array_size(pile_a) - i);
				i = 0;
			}
			else
				i++;
		}
	}
	return (true);
}

bool	sort(int *pile_a, int *pile_b)
{
	int		*pile_sorted;

	if (array_issort(pile_a, &sort_handler))
		return (true);
	pile_sorted = array_sort(array_dup(pile_a), &sort_handler);
	if (array_size(pile_a) == 3)
		sort3(pile_a, pile_b);
	else
	{
		if (!pb_by_medianes(pile_a, pile_b, pile_sorted))
			return (false);
		if (!pa_insert_sort(pile_a, pile_b, pile_sorted))
			return (false);
	}
	array_free(pile_sorted);
	return (true);
}
