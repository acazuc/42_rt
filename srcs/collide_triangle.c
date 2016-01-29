/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_triangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:22:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/29 16:27:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector		*get_normal(t_ray *ray, t_object *triangle)
{
	t_vector	*vector;
	double		angle;

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
	t_vector	*vector;

	vector = vector_create();
	vector->x = ray->origin->x + ray->direction->x * t;
	vector->y = ray->origin->y + ray->direction->y * t;
	vector->z = ray->origin->z + ray->direction->z * t;
	return (vector);
}

t_collision			*collide_triangle(t_ray *ray, t_object *triangle)
{
	t_collision	*collision;
	t_vector	e1;
	t_vector	e2;
	t_vector	p;
	t_vector	q;
	t_vector	t;
	double		det;
	double		u;
	double		v;
	double		factor;

	e1.x = triangle->rotation->x - triangle->position->x;
	e1.y = triangle->rotation->y - triangle->position->y;
	e1.z = triangle->rotation->z - triangle->position->z;
	e2.x = triangle->dimensions[0] - triangle->position->x;
	e2.y = triangle->dimensions[1] - triangle->position->y;
	e2.z = triangle->dimensions[2] - triangle->position->z;
	p.x = ray->direction->y * e2.z - ray->direction->z * e2.y;
	p.y = ray->direction->z * e2.x - ray->direction->x * e2.z;
	p.z = ray->direction->x * e2.y - ray->direction->y * e2.x;
	det = vector_dot(&e1, &p);
	collision = collision_create();
	if (det == 0)
		return (collision);
	det = 1. / det;
	t.x = ray->origin->x - triangle->position->x;
	t.y = ray->origin->y - triangle->position->y;
	t.z = ray->origin->z - triangle->position->z;
	u = vector_dot(&t, &p) * det;
	if (u < 0 || u > 1)
		return (collision);
	q.x = t.y * e1.z - t.z * e1.y;
	q.y = t.z * e1.x - t.x * e1.z;
	q.z = t.x * e1.y - t.y * e1.x;
	v = vector_dot(ray->direction, &q) * det;
	if (v < 0 || u + v > 1)
		return (collision);
	factor = vector_dot(&e2, &q) * det;
	if (factor <= 0)
		return (collision);
	collision->vector = collide_triangle_result(ray, factor);
	if (collision->vector)
		collision->normal = get_normal(ray, triangle);
	return (collision);
}
