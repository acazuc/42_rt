/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octahedron_add_regular.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:08:29 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 11:12:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	octahedron_add_regular(t_octahedron *octahedron)
{
	octahedron->p1->x = -1 * octahedron->size / 2;
	octahedron->p1->y = 0;
	octahedron->p1->z = 0;
	octahedron->p2->x = 0;
	octahedron->p2->y = 0;
	octahedron->p2->z = 1 * octahedron->size / 2.;
	octahedron->p3->x = -1 * octahedron->size / 2.;
	octahedron->p3->y = 0;
	octahedron->p3->z = 0;
	octahedron->p4->x = 0;
	octahedron->p4->y = 0;
	octahedron->p4->z = -1 * octahedron->size / 2.;
	octahedron->p5->x = 0;
	octahedron->p5->y = 1 * octahedron->size / 2.;
	octahedron->p5->z = 0;
	octahedron->p6->x = 0;
	octahedron->p6->y = -1 * octahedron->size / 2.;
	octahedron->p6->z = 0;
}
