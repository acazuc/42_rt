/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:52:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/07 08:57:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_collision	*collide(t_ray *ray, t_object *object)
{
	t_collision	*collision;

	collision = NULL;
	if (object->type == SPHERE)
		collision = collide_sphere(ray, object);
	else if (object->type == CYLINDER)
		collision = collide_cylinder(ray, object);
	else if (object->type == CONE)
		collision = collide_cone(ray, object);
	else if (object->type == PLANE)
		collision = collide_plane(ray, object);
	if (collision && collision->vector)
		collision->object = object;
	return (collision);
}
