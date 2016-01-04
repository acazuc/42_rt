/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:49:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/04 15:53:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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

static t_vector		*collide_cone_result(t_ray *ray, t_trinome *trinome)
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
		t = get_t(trinome);
	if (t <= 0)
		return (NULL);
	vector = vector_create();
	vector->x = ray->origin->x + ray->direction->x * t;
	vector->y = ray->origin->y + ray->direction->y * t;
	vector->z = ray->origin->z + ray->direction->z * t;
	return (vector);
}

t_vector			*collide_cone(t_ray *ray, t_object *cone)
{
	t_trinome	trinome;
	t_vector	p;

	p.x = ray->origin->x - cone->position->x;
	p.y = ray->origin->y - cone->position->y;
	p.z = ray->origin->z - cone->position->z;
	vector_rotate(&p, cone->rotation);
	trinome.a = pow(ray->direction->x, 2) -
		pow(ray->direction->y, 2) +
		pow(ray->direction->z, 2);
	trinome.b = 2. * (ray->direction->x * p.x -
			ray->direction->y * p.y +
			ray->direction->z * p.z);
	trinome.c = pow(p.x, 2) - pow(p.y, 2) + pow(p.z, 2);
	trinome.d = trinome.b * trinome.b - 4. * trinome.a * trinome.c;
	return (collide_cone_result(ray, &trinome));
}
