/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:30:22 by lperroti          #+#    #+#             */
/*   Updated: 2023/02/25 21:38:00 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_op(enum e_ops op)
{
	if (op == SA)
		write(1, "sa\n", 3);
	if (op == SB)
		write(1, "sb", 3);
	if (op == SS)
		write(1, "ss\n", 3);
	if (op == PA)
		write(1, "pa\n", 3);
	if (op == PB)
		write(1, "pb\n", 3);
	if (op == RA)
		write(1, "ra\n", 3);
	if (op == RB)
		write(1, "rb\n", 3);
	if (op == RR)
		write(1, "rr\n", 3);
	if (op == RRA)
		write(1, "rra\n", 4);
	if (op == RRB)
		write(1, "rrb\n", 4);
	if (op == RRR)
		write(1, "rrr\n", 4);
}

void	do_op(t_array pile_a, t_array pile_b, enum e_ops op)
{
	(void)(op == SA && (swap(pile_a), 1));
	(void)(op == SB && (swap(pile_b), 1));
	(void)(op == SS && (swap(pile_a), 1) && (swap(pile_b), 1));
	(void)(op == PA && (push(pile_a, pile_b), 1));
	(void)(op == PB && (push(pile_b, pile_a), 1));
	(void)(op == RA && (rotate(pile_a), 1));
	(void)(op == RB && (rotate(pile_b), 1));
	(void)(op == RR && (rotate(pile_a), 1) && (rotate(pile_b), 1));
	(void)(op == RRA && (rrotate(pile_a), 1));
	(void)(op == RRB && (rrotate(pile_b), 1));
	(void)(op == RRR && (rrotate(pile_a), 1) && (rrotate(pile_b), 1));
	print_op(op);
}
