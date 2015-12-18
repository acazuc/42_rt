/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:49:42 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/18 16:36:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

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

static t_vector		*collide_sphere_result(t_ray *ray, t_trinome *trinome)
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
		if ((t = get_t(trinome)) <= 0)
			return (NULL);
	vector = vector_create();
	vector->x = ray->origin->x + ray->direction->x * t;
	vector->y = ray->origin->y + ray->direction->y * t;
	vector->z = ray->origin->z + ray->direction->z * t;
	return (vector);
}

t_vector			*collide_sphere(t_ray *ray, t_object *sphere)
{
	t_trinome	trinome;

	trinome.a = pow(ray->direction->x, 2)
		+ pow(ray->direction->y, 2)
		+ pow(ray->direction->z, 2);
	trinome.b = 2. * (ray->direction->x * (ray->origin->x - sphere->position->x)
			+ ray->direction->y * (ray->origin->y - sphere->position->y)
			+ ray->direction->z * (ray->origin->z - sphere->position->z));
	trinome.c = (pow(ray->origin->x - sphere->position->x, 2)
			+ pow(ray->origin->y - sphere->position->y, 2)
			+ pow(ray->origin->z - sphere->position->z, 2))
		- pow(sphere->dimensions[0], 2);
	trinome.d = trinome.b * trinome.b - 4. * trinome.a * trinome.c;
	return (collide_sphere_result(ray, &trinome));
}
