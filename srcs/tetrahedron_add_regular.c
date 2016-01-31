/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_add_regular.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:37:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 14:38:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	tetrahedron_add_regular(t_tetrahedron *tetrahedron)
{
	tetrahedron->p1->x = 1 * tetrahedron->size / 2.;
	tetrahedron->p1->y = 1 * tetrahedron->size / 2.;
	tetrahedron->p1->z = 1 * tetrahedron->size / 2.;
	tetrahedron->p2->x = 1 * tetrahedron->size / 2.;
	tetrahedron->p2->y = -1 * tetrahedron->size / 2.;
	tetrahedron->p2->z = -1 * tetrahedron->size / 2.;
	tetrahedron->p3->x = -1 * tetrahedron->size / 2.;
	tetrahedron->p3->y = 1 * tetrahedron->size / 2.;
	tetrahedron->p3->z = -1 * tetrahedron->size / 2.;
	tetrahedron->p4->x = -1 * tetrahedron->size / 2.;
	tetrahedron->p4->y = -1 * tetrahedron->size / 2.;
	tetrahedron->p4->z = 1 * tetrahedron->size / 2.;
}
