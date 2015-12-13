/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:49:42 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/13 16:53:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

static int			collide_cylinder_result_inside(t_ray *ray
		, t_object *cylinder, double t)
{
	double		y;

	y = ray->direction->y * t + ray->origin->y;
	if (y < cylinder->position->y - (cylinder->dimensions[1] / 2.)
			|| y > cylinder->position->y + (cylinder->dimensions[1] / 2.))
		return (0);
	return (1);
}

static t_vector		*collide_cylinder_result(t_ray *ray, t_trinome *trinome
		, t_object *cylinder)
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
	{
		t1 = (-trinome->b + sqrt(trinome->d)) / (2. * trinome->a);
		t2 = (-trinome->b - sqrt(trinome->d)) / (2. * trinome->a);
		t = MIN(t1, t2);
	}
	if (!(collide_cylinder_result_inside(ray, cylinder, t)))
		return (NULL);
	vector = vector_create();
	vector->x = ray->direction->x * t;
	vector->y = ray->direction->y * t;
	vector->z = ray->direction->z * t;
	return (vector);
}

t_vector			*collide_cylinder(t_ray *ray, t_object *cylinder)
{
	t_trinome	trinome;

	trinome.a = pow(ray->direction->x, 2) + pow(ray->direction->z, 2);
	trinome.b = 2.
		* (ray->direction->x * (ray->origin->x - cylinder->position->x)
			+ ray->direction->z * (ray->origin->z - cylinder->position->z));
	trinome.c = (pow(ray->origin->x - cylinder->position->x, 2)
			+ pow(ray->origin->z - cylinder->position->z, 2))
		- pow(cylinder->dimensions[0], 2);
	trinome.d = trinome.b * trinome.b - 4. * trinome.a * trinome.c;
	return (collide_cylinder_result(ray, &trinome, cylinder));
}
