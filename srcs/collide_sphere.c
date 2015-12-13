/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:49:42 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/13 09:56:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

static double	collide_sphere_result(t_ray *ray, double a, double b
		, double d)
{
	double	t1;
	double	t2;
	double	t;

	t1 = 0;
	t2 = 0;
	t = 0;
	if (d < 0)
		return (-1);
	else if (d == 0)
		t = -b / (2. * a);
	else if (d > 0)
	{
		t1 = (-b + sqrt(d)) / (2. * a);
		t2 = (-b - sqrt(d)) / (2. * a);
		t = MIN(t1, t2);
	}
	return (sqrt(pow(ray->direction->x * t, 2)
				+ pow(ray->direction->y * t, 2)
				+ pow(ray->direction->z * t, 2)));
}

double			collide_sphere(t_ray *ray, t_object *sphere)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = pow(ray->direction->x, 2)
		+ pow(ray->direction->y, 2)
		+ pow(ray->direction->z, 2);
	b = 2. * (ray->direction->x * (ray->origin->x - sphere->position->x)
			+ ray->direction->y * (ray->origin->y - sphere->position->y)
			+ ray->direction->z * (ray->origin->z - sphere->position->z));
	c = (pow(ray->origin->x - sphere->position->x, 2)
			+ pow(ray->origin->y - sphere->position->y, 2)
			+ pow(ray->origin->z - sphere->position->z, 2))
		- pow(sphere->dimensions[0], 2);
	d = b * b - 4. * a * c;
	return (collide_sphere_result(ray, a, b, d));
}
