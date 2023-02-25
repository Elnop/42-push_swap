/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 07:51:07 by lperroti          #+#    #+#             */
/*   Updated: 2023/02/25 23:28:55 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	sort_handler(void *a, void *b)
{
	return (*(int *)a <= *(int *)b);
}

bool	sort3(int *pile_a, int *pile_b, int *pile_s)
{
	while (!array_issort(pile_a, &sort_handler))
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

bool	pa_insert_sort(int *pile_a, int *pile_b, int *pile_sorted)
{
	size_t	sorted_index;
	size_t	pile_b_index;

	sorted_index = array_size(pile_sorted);
	while (sorted_index--)
	{
		if (!array_has(pile_b, pile_sorted + sorted_index))
			continue ;
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
	while (array_size(pile_a) - 3)
	{
		mediane_index += array_size(pile_s) / 10;
		if (!mediane_index || mediane_index > array_size(pile_s) - 4)
			mediane_index = array_size(pile_s) - 4;
		mediane = pile_s[mediane_index];
		i = 0;
		while (i < array_size(pile_a))
		{
			if (pile_a[i] <= mediane)
				pb_elem(pile_a, pile_b, i);
			else if (i && pile_a[array_size(pile_a) - i] <= mediane)
				pb_elem(pile_a, pile_b, array_size(pile_a) - i);
			else
				i++;
		}
	}
	return (true);
}

bool	sort(int *pile_a, int *pile_b)
{
	int		*pile_sorted;

	if (array_size(pile_a) == 2 && !array_issort(pile_a, &sort_handler))
		do_op(pile_a, pile_b, SA);
	pile_sorted = array_sort(array_dup(pile_a), &sort_handler);
	if (array_issort(pile_a, &sort_handler))
		return (array_free(pile_sorted), true);
	if (array_size(pile_a) == 3)
		sort3(pile_a, pile_b, pile_sorted);
	else
	{
		if (!pb_by_medianes(pile_a, pile_b, pile_sorted))
			return (array_free(pile_sorted), false);
		sort3(pile_a, pile_b, pile_sorted);
		if (!pa_insert_sort(pile_a, pile_b, pile_sorted))
			return (array_free(pile_sorted), false);
	}
	return (array_free(pile_sorted), true);
}
