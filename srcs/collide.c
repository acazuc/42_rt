/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:52:58 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/17 17:14:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

t_vector	*collide(t_ray *ray, t_object *object)
{
	t_vector	*vector;

	vector = NULL;
	if (object->type == SPHERE)
		vector = collide_sphere(ray, object);
	else if (object->type == CYLINDER)
		vector = collide_cylinder(ray, object);
	else if (object->type == CONE)
		vector = collide_cone(ray, object);
	return (vector);
}
