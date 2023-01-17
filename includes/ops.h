/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 07:56:27 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/10 07:57:32 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include "liblp_c/liblp.h"

void	swap(t_array pile);
void	push(t_array src, t_array dest);
void	rotate(t_array pile);
void	rrotate(t_array pile);

#endif