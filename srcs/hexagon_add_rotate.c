/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexagon_add_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:07:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:08:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hexagon_add_rotate(t_hexagon *hexagon)
{
	vector_rotate(hexagon->p1, hexagon->rotation);
	vector_rotate(hexagon->p2, hexagon->rotation);
	vector_rotate(hexagon->p3, hexagon->rotation);
	vector_rotate(hexagon->p4, hexagon->rotation);
	vector_rotate(hexagon->p5, hexagon->rotation);
	vector_rotate(hexagon->p6, hexagon->rotation);
}
