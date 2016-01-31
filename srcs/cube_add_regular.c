/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_add_regular.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:19:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 14:33:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cube_add_regular(t_cube *cube)
{
	cube->p1->x = -1 * cube->size / 2.;
	cube->p1->y = 1 * cube->size / 2.;
	cube->p1->z = -1 * cube->size / 2.;
	cube->p2->x = 1 * cube->size / 2.;
	cube->p2->y = 1 * cube->size / 2.;
	cube->p2->z = -1 * cube->size / 2.;
	cube->p3->x = 1 * cube->size / 2.;
	cube->p3->y = -1 * cube->size / 2.;
	cube->p3->z = -1 * cube->size / 2.;
	cube->p4->x = -1 * cube->size / 2.;
	cube->p4->y = -1 * cube->size / 2.;
	cube->p4->z = -1 * cube->size / 2.;
	cube->p5->x = -1 * cube->size / 2.;
	cube->p5->y = 1 * cube->size / 2.;
	cube->p5->z = 1 * cube->size / 2.;
	cube->p6->x = 1 * cube->size / 2.;
	cube->p6->y = 1 * cube->size / 2.;
	cube->p6->z = 1 * cube->size / 2.;
	cube->p7->x = 1 * cube->size / 2.;
	cube->p7->y = -1 * cube->size / 2.;
	cube->p7->z = 1 * cube->size / 2.;
	cube->p8->x = -1 * cube->size / 2.;
	cube->p8->y = -1 * cube->size / 2.;
	cube->p8->z = -1 * cube->size / 2.;
}
