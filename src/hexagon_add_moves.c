/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexagon_add_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:05:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:06:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hexagon_add_moves(t_hexagon *hexagon)
{
	hexagon->p1->x += hexagon->position->x;
	hexagon->p1->y += hexagon->position->y;
	hexagon->p1->z += hexagon->position->z;
	hexagon->p2->x += hexagon->position->x;
	hexagon->p2->y += hexagon->position->y;
	hexagon->p2->z += hexagon->position->z;
	hexagon->p3->x += hexagon->position->x;
	hexagon->p3->y += hexagon->position->y;
	hexagon->p3->z += hexagon->position->z;
	hexagon->p4->x += hexagon->position->x;
	hexagon->p4->y += hexagon->position->y;
	hexagon->p4->z += hexagon->position->z;
	hexagon->p5->x += hexagon->position->x;
	hexagon->p5->y += hexagon->position->y;
	hexagon->p5->z += hexagon->position->z;
	hexagon->p6->x += hexagon->position->x;
	hexagon->p6->y += hexagon->position->y;
	hexagon->p6->z += hexagon->position->z;
}
