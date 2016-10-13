/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexagon_add_regular.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:11:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:14:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hexagon_add_regular(t_hexagon *hexagon)
{
	hexagon->p1->x = cos(M_PI * 2. / 6. * 0.) * hexagon->size / 2.;
	hexagon->p1->y = sin(M_PI * 2. / 6. * 0.) * hexagon->size / 2.;
	hexagon->p1->z = 0;
	hexagon->p2->x = cos(M_PI * 2. / 6. * 1.) * hexagon->size / 2.;
	hexagon->p2->y = sin(M_PI * 2. / 6. * 1.) * hexagon->size / 2.;
	hexagon->p2->z = 0;
	hexagon->p3->x = cos(M_PI * 2. / 6. * 2.) * hexagon->size / 2.;
	hexagon->p3->y = sin(M_PI * 2. / 6. * 2.) * hexagon->size / 2.;
	hexagon->p3->z = 0;
	hexagon->p4->x = cos(M_PI * 2. / 6. * 3.) * hexagon->size / 2.;
	hexagon->p4->y = sin(M_PI * 2. / 6. * 3.) * hexagon->size / 2.;
	hexagon->p4->z = 0;
	hexagon->p5->x = cos(M_PI * 2. / 6. * 4.) * hexagon->size / 2.;
	hexagon->p5->y = sin(M_PI * 2. / 6. * 4.) * hexagon->size / 2.;
	hexagon->p5->z = 0;
	hexagon->p6->x = cos(M_PI * 2. / 6. * 5.) * hexagon->size / 2.;
	hexagon->p6->y = sin(M_PI * 2. / 6. * 5.) * hexagon->size / 2.;
	hexagon->p6->z = 0;
}
