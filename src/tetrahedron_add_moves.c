/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_add_moves.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:36:36 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 14:37:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	tetrahedron_add_moves(t_tetrahedron *tetrahedron)
{
	tetrahedron->p1->x += tetrahedron->position->x;
	tetrahedron->p1->y += tetrahedron->position->y;
	tetrahedron->p1->z += tetrahedron->position->z;
	tetrahedron->p2->x += tetrahedron->position->x;
	tetrahedron->p2->y += tetrahedron->position->y;
	tetrahedron->p2->z += tetrahedron->position->z;
	tetrahedron->p3->x += tetrahedron->position->x;
	tetrahedron->p3->y += tetrahedron->position->y;
	tetrahedron->p3->z += tetrahedron->position->z;
	tetrahedron->p4->x += tetrahedron->position->x;
	tetrahedron->p4->y += tetrahedron->position->y;
	tetrahedron->p4->z += tetrahedron->position->z;
}
