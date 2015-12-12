/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:49:42 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/12 15:42:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

static double	collide_sphere_result(t_vector *vector, double a, double b
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
	return (sqrt(pow(vector->x * t, 2)
				+ pow(vector->y * t, 2)
				+ pow(vector->z * t, 2)));
}

double			collide_sphere(t_env *env, t_vector *vector, t_object *sphere)
{
	double	a;
	double	b;
	double	c;
	double	d;

	env = env + 1;
	env = env - 1;
	a = pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2);
	b = 2. * (vector->x * (env->position->x - sphere->position->x)
			+ vector->y * (env->position->y - sphere->position->y)
			+ vector->z * (env->position->z - sphere->position->z));
	c = (pow(env->position->x - sphere->position->x, 2)
			+ pow(env->position->y - sphere->position->y, 2)
			+ pow(env->position->z - sphere->position->z, 2))
		- pow(sphere->dimensions[0], 2);
	d = b * b - 4. * a * c;
	return (collide_sphere_result(vector, a, b, d));
}
