/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_triangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:22:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/29 16:51:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector		*get_normal(t_ray *ray, t_object *triangle)
{
	t_vector			*vector;
	double				angle;

	vector = vector_create();
	vector->x = (triangle->rotation->x - triangle->position->x) *
		(triangle->dimensions[0] - triangle->position->x);
	vector->y = (triangle->rotation->y - triangle->position->y) *
		(triangle->dimensions[1] - triangle->position->y);
	vector->z = (triangle->rotation->z - triangle->position->z) *
		(triangle->dimensions[2] - triangle->position->z);
	angle = vector_angle(vector, ray->direction) * 180. / M_PI;
	if (angle <= 90)
	{
		vector->x = -vector->x;
		vector->y = -vector->y;
		vector->z = -vector->z;
	}
	return (vector);
}

static t_vector		*collide_triangle_result(t_ray *ray, double t)
{
	t_vector			*vector;

	vector = vector_create();
	vector->x = ray->origin->x + ray->direction->x * t;
	vector->y = ray->origin->y + ray->direction->y * t;
	vector->z = ray->origin->z + ray->direction->z * t;
	return (vector);
}

static void			collide_triangle_init(t_triangle_collide *coll, t_ray *ray
		, t_object *triangle)
{
	coll->e1.x = triangle->rotation->x - triangle->position->x;
	coll->e1.y = triangle->rotation->y - triangle->position->y;
	coll->e1.z = triangle->rotation->z - triangle->position->z;
	coll->e2.x = triangle->dimensions[0] - triangle->position->x;
	coll->e2.y = triangle->dimensions[1] - triangle->position->y;
	coll->e2.z = triangle->dimensions[2] - triangle->position->z;
	coll->p.x = ray->direction->y * coll->e2.z - ray->direction->z * coll->e2.y;
	coll->p.y = ray->direction->z * coll->e2.x - ray->direction->x * coll->e2.z;
	coll->p.z = ray->direction->x * coll->e2.y - ray->direction->y * coll->e2.x;
	coll->det = vector_dot(&coll->e1, &coll->p);
}

static void			collide_triangle_part(t_triangle_collide *coll
		, t_object *triangle, t_ray *ray)
{
	coll->det = 1. / coll->det;
	coll->t.x = ray->origin->x - triangle->position->x;
	coll->t.y = ray->origin->y - triangle->position->y;
	coll->t.z = ray->origin->z - triangle->position->z;
	coll->u = vector_dot(&coll->t, &coll->p) * coll->det;
}

t_collision			*collide_triangle(t_ray *ray, t_object *triangle)
{
	t_triangle_collide	coll;
	t_collision			*collision;
	double				factor;

	collide_triangle_init(&coll, ray, triangle);
	collision = collision_create();
	if (coll.det == 0)
		return (collision);
	collide_triangle_part(&coll, triangle, ray);
	if (coll.u < 0 || coll.u > 1)
		return (collision);
	coll.q.x = coll.t.y * coll.e1.z - coll.t.z * coll.e1.y;
	coll.q.y = coll.t.z * coll.e1.x - coll.t.x * coll.e1.z;
	coll.q.z = coll.t.x * coll.e1.y - coll.t.y * coll.e1.x;
	coll.v = vector_dot(ray->direction, &coll.q) * coll.det;
	if (coll.v < 0 || coll.u + coll.v > 1)
		return (collision);
	factor = vector_dot(&coll.e2, &coll.q) * coll.det;
	if (factor <= 0)
		return (collision);
	collision->vector = collide_triangle_result(ray, factor);
	if (collision->vector)
		collision->normal = get_normal(ray, triangle);
	return (collision);
}
