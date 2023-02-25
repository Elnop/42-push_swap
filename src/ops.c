/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 07:49:44 by lperroti          #+#    #+#             */
/*   Updated: 2023/02/25 22:30:11 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_array dest, t_array src)
{
	array_pushfront(dest, array_get(src, 0));
	array_remove(src, 0);
}

void	rotate(t_array pile)
{
	array_rotate(pile);
}

void	rrotate(t_array pile)
{
	array_rrotate(pile);
}

void	swap(t_array pile)
{
	if (array_size(pile) < 2)
		return ;
	array_swap(pile, 0, 1);
}
