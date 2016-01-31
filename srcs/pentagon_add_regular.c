/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pentagon_add_regular.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:08:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:18:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	pentagon_add_regular(t_pentagon *pentagon)
{
	pentagon->p1->x = cos(M_PI * 2. / 5. * 0.) * pentagon->size / 2.;
	pentagon->p1->y = sin(M_PI * 2. / 5. * 0.) * pentagon->size / 2.;
	pentagon->p1->z = 0;
	pentagon->p2->x = cos(M_PI * 2. / 5. * 1.) * pentagon->size / 2.;
	pentagon->p2->y = sin(M_PI * 2. / 5. * 1.) * pentagon->size / 2.;
	pentagon->p2->z = 0;
	pentagon->p3->x = cos(M_PI * 2. / 5. * 2.) * pentagon->size / 2.;
	pentagon->p3->y = sin(M_PI * 2. / 5. * 2.) * pentagon->size / 2.;
	pentagon->p3->z = 0;
	pentagon->p4->x = cos(M_PI * 2. / 5. * 3.) * pentagon->size / 2.;
	pentagon->p4->y = sin(M_PI * 2. / 5. * 3.) * pentagon->size / 2.;
	pentagon->p4->z = 0;
	pentagon->p5->x = cos(M_PI * 2. / 5. * 4.) * pentagon->size / 2.;
	pentagon->p5->y = sin(M_PI * 2. / 5. * 4.) * pentagon->size / 2.;
	pentagon->p5->z = 0;
}
