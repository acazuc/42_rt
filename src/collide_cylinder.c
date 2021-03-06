/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:49:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/09 14:00:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector		*get_normal(t_vector *point, t_object *cylinder)
{
	t_vector	*vector;

	vector = vector_create();
	vector->x = point->x - cylinder->position->x;
	vector->y = point->y - cylinder->position->y;
	vector->z = point->z - cylinder->position->z;
	vector_unrotate(vector, cylinder->rotation);
	vector->y = 0;
	vector_rotate(vector, cylinder->rotation);
	return (vector);
}

static double		get_t(t_trinome *trinome)
{
	double		t1;
	double		t2;

	t1 = (-trinome->b + sqrt(trinome->d)) / (2. * trinome->a);
	t2 = (-trinome->b - sqrt(trinome->d)) / (2. * trinome->a);
	if (t1 < 0)
		return (t2);
	else if (t2 < 0)
		return (t1);
	return (MIN(t1, t2));
}

static t_vector		*collide_cylinder_result(t_ray *ray, t_trinome *trinome)
{
	t_vector	*vector;
	double		t1;
	double		t2;
	double		t;

	t1 = 0;
	t2 = 0;
	t = 0;
	if (trinome->d < 0)
		return (NULL);
	else if (trinome->d == 0)
		t = -trinome->b / (2. * trinome->a);
	else if (trinome->d > 0)
		if ((t = get_t(trinome)) < 0)
			return (NULL);
	vector = vector_create();
	vector->x = ray->origin->x + ray->direction->x * t;
	vector->y = ray->origin->y + ray->direction->y * t;
	vector->z = ray->origin->z + ray->direction->z * t;
	return (vector);
}

t_collision			*collide_cylinder(t_ray *ray, t_object *cylinder)
{
	t_collision	*collision;
	t_trinome	trinome;
	t_vector	p;

	p.x = ray->origin->x - cylinder->position->x;
	p.y = ray->origin->y - cylinder->position->y;
	p.z = ray->origin->z - cylinder->position->z;
	vector_unrotate(&p, cylinder->rotation);
	vector_unrotate(ray->direction, cylinder->rotation);
	trinome.a = pow(ray->direction->x, 2) + pow(ray->direction->z, 2);
	trinome.b = 2. * (ray->direction->x * p.x + ray->direction->z * p.z);
	trinome.c = pow(p.x, 2) + pow(p.z, 2) - pow(cylinder->dimensions[0], 2);
	trinome.d = trinome.b * trinome.b - 4. * trinome.a * trinome.c;
	collision = collision_create();
	vector_rotate(ray->direction, cylinder->rotation);
	collision->vector = collide_cylinder_result(ray, &trinome);
	if (collision->vector)
		collision->normal = get_normal(collision->vector, cylinder);
	return (collision);
}
