/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 09:16:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/05 08:16:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		*collide_plane(t_ray *ray, t_object *plane)
{
	t_vector	*vector;
	t_vector	p;
	double		dividende;
	double		divisor;
	double		t;

	dividende = vector_dot(plane->rotation, ray->direction);
	if (dividende == 0)
		return (NULL);
	p.x = -ray->origin->x + plane->position->x;
	p.y = -ray->origin->y + plane->position->y;
	p.z = -ray->origin->z + plane->position->z;
	divisor = vector_dot(plane->rotation, &p);
	t = divisor / dividende;
	if (t < 0)
		return (NULL);
	vector = vector_create();
	vector->x = ray->origin->x + ray->direction->x * t;
	vector->y = ray->origin->y + ray->direction->y * t;
	vector->z = ray->origin->z + ray->direction->z * t;
	return (vector);
}
