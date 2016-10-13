/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:49:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/09 13:43:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector		*get_normal(t_object *plane, t_ray *ray)
{
	t_vector	*vector;
	double		angle;

	vector = vector_create();
	vector->x = 0;
	vector->y = 1;
	vector->z = 0;
	vector_rotate(vector, plane->rotation);
	angle = vector_angle(vector, ray->direction) * 180. / M_PI;
	if (angle <= 90)
	{
		vector->x = -vector->x;
		vector->y = -vector->y;
		vector->z = -vector->z;
	}
	return (vector);
}

static t_vector		*collide_plane_result(t_ray *ray, double t)
{
	t_vector	*vector;

	if (t < 0)
		return (NULL);
	vector = vector_create();
	vector->x = ray->origin->x + ray->direction->x * t;
	vector->y = ray->origin->y + ray->direction->y * t;
	vector->z = ray->origin->z + ray->direction->z * t;
	return (vector);
}

t_collision			*collide_plane(t_ray *ray, t_object *plane)
{
	t_collision	*collision;
	t_vector	normal;
	t_vector	p;
	double		nd;
	double		t;

	normal.x = 0;
	normal.y = 1;
	normal.z = 0;
	p.x = plane->position->x - ray->origin->x;
	p.y = plane->position->y - ray->origin->y;
	p.z = plane->position->z - ray->origin->z;
	vector_rotate(&normal, plane->rotation);
	collision = collision_create();
	nd = vector_dot(&normal, ray->direction);
	if (nd == 0)
		return (collision);
	t = vector_dot(&normal, &p) / nd;
	collision->vector = collide_plane_result(ray, t);
	if (collision->vector)
		collision->normal = get_normal(plane, ray);
	return (collision);
}
