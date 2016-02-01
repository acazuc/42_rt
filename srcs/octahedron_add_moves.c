/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octahedron_add_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:06:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 11:07:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	octahedron_add_moves(t_octahedron *octahedron)
{
	octahedron->p1->x += octahedron->position->x;
	octahedron->p1->y += octahedron->position->y;
	octahedron->p1->z += octahedron->position->z;
	octahedron->p2->x += octahedron->position->x;
	octahedron->p2->y += octahedron->position->y;
	octahedron->p2->z += octahedron->position->z;
	octahedron->p3->x += octahedron->position->x;
	octahedron->p3->y += octahedron->position->y;
	octahedron->p3->z += octahedron->position->z;
	octahedron->p4->x += octahedron->position->x;
	octahedron->p4->y += octahedron->position->y;
	octahedron->p4->z += octahedron->position->z;
	octahedron->p5->x += octahedron->position->x;
	octahedron->p5->y += octahedron->position->y;
	octahedron->p5->z += octahedron->position->z;
	octahedron->p6->x += octahedron->position->x;
	octahedron->p6->y += octahedron->position->y;
	octahedron->p6->z += octahedron->position->z;
}
