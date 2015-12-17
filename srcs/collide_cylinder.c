/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:49:42 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/17 11:42:23 by acazuc           ###   ########.fr       */
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

static t_vector		*collide_cylinder_result(t_ray *ray, t_trinome *trinome
		, t_object *cylinder)
{
	t_vector	*vector;
	double		t1;
	double		t2;
	double		t;

	(void)cylinder;
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
	vector->x = ray->direction->x * t;
	vector->y = ray->direction->y * t;
	vector->z = ray->direction->z * t;
	return (vector);
}

t_vector			*collide_cylinder(t_ray *ray, t_object *cylinder)
{
	t_trinome	trinome;
	t_vector	*pos;

	pos = vector_create();
	pos->x = ray->origin->x - cylinder->position->x;
	pos->y = ray->origin->y - cylinder->position->y;
	pos->z = ray->origin->z - cylinder->position->z;
	trinome.a = pow(ray->direction->x, 2) + pow(ray->direction->z, 2);
	trinome.b = 2.
		* (ray->direction->x * pos->x + ray->direction->z * pos->z);
	trinome.c = pos->x * pos->x + pos->z * pos->z
		- pow(cylinder->dimensions[0], 2);
	trinome.d = trinome.b * trinome.b - 4. * trinome.a * trinome.c;
	free(pos);
	return (collide_cylinder_result(ray, &trinome, cylinder));
}
