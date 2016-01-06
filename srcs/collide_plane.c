/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 09:16:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/06 15:30:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_collision		*collide_plane(t_ray *ray, t_object *plane)
{
	t_collision	*collision;
	t_vector	p;
	double		dividende;
	double		divisor;
	double		t;

	collision = collision_create();
	dividende = vector_dot(plane->rotation, ray->direction);
	if (dividende == 0)
		return (collision);
	p.x = -ray->origin->x + plane->position->x;
	p.y = -ray->origin->y + plane->position->y;
	p.z = -ray->origin->z + plane->position->z;
	divisor = vector_dot(plane->rotation, &p);
	t = divisor / dividende;
	if (t < 0)
		return (collision);
	collision->vector = vector_create();
	collision->vector->x = ray->origin->x + ray->direction->x * t;
	collision->vector->y = ray->origin->y + ray->direction->y * t;
	collision->vector->z = ray->origin->z + ray->direction->z * t;
	return (collision);
}
