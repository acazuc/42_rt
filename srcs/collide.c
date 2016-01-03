/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:52:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/03 08:50:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*collide(t_ray *ray, t_object *object)
{
	t_vector	*vector;

	vector = NULL;
	vector_rotate(ray->direction, object->rotation);
	if (object->type == SPHERE)
		vector = collide_sphere(ray, object);
	else if (object->type == CYLINDER)
		vector = collide_cylinder(ray, object);
	else if (object->type == CONE)
		vector = collide_cone(ray, object);
	vector_unrotate(ray->direction, object->rotation);
	if (vector)
		vector_unrotate(vector, object->rotation);
	return (vector);
}
