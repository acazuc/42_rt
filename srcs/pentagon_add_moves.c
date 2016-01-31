/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pentagon_add_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:03:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:05:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	pentagon_add_moves(t_pentagon *pentagon)
{
	pentagon->p1->x += pentagon->position->x;
	pentagon->p1->y += pentagon->position->y;
	pentagon->p1->z += pentagon->position->z;
	pentagon->p2->x += pentagon->position->x;
	pentagon->p2->y += pentagon->position->y;
	pentagon->p2->z += pentagon->position->z;
	pentagon->p3->x += pentagon->position->x;
	pentagon->p3->y += pentagon->position->y;
	pentagon->p3->z += pentagon->position->z;
	pentagon->p4->x += pentagon->position->x;
	pentagon->p4->y += pentagon->position->y;
	pentagon->p4->z += pentagon->position->z;
	pentagon->p5->x += pentagon->position->x;
	pentagon->p5->y += pentagon->position->y;
	pentagon->p5->z += pentagon->position->z;
}
