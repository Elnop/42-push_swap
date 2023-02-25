/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:12:42 by lperroti          #+#    #+#             */
/*   Updated: 2023/02/25 22:29:01 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/liblp_c/liblp.h"

enum e_ops
{
	SA = 0,
	SB = 1,
	SS = 2,
	PA = 3,
	PB = 4,
	RA = 5,
	RB = 6,
	RR = 7,
	RRA = 8,
	RRB = 9,
	RRR = 10,
};

void	swap(t_array pile);
void	push(t_array src, t_array dest);
void	rotate(t_array pile);
void	rrotate(t_array pile);
void	do_op(t_array pile_a, t_array pile_b, enum e_ops op);
bool	sort(int *pile_a, int *pile_b);

#endif