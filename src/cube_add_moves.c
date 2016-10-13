/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_add_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:33:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 14:34:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cube_add_moves(t_cube *cube)
{
	cube->p1->x += cube->position->x;
	cube->p1->y += cube->position->y;
	cube->p1->z += cube->position->z;
	cube->p2->x += cube->position->x;
	cube->p2->y += cube->position->y;
	cube->p2->z += cube->position->z;
	cube->p3->x += cube->position->x;
	cube->p3->y += cube->position->y;
	cube->p3->z += cube->position->z;
	cube->p4->x += cube->position->x;
	cube->p4->y += cube->position->y;
	cube->p4->z += cube->position->z;
	cube->p5->x += cube->position->x;
	cube->p5->y += cube->position->y;
	cube->p5->z += cube->position->z;
	cube->p6->x += cube->position->x;
	cube->p6->y += cube->position->y;
	cube->p6->z += cube->position->z;
	cube->p7->x += cube->position->x;
	cube->p7->y += cube->position->y;
	cube->p7->z += cube->position->z;
	cube->p8->x += cube->position->x;
	cube->p8->y += cube->position->y;
	cube->p8->z += cube->position->z;
}
