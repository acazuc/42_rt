/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:05:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/06 16:42:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*normal(t_object *object, t_vector *point)
{
	t_vector	*vector;

	vector = NULL;
	if (object->type == SPHERE)
		vector = normal_sphere(object, point);
	else if (object->type == CYLINDER)
		vector = normal_cylinder(object, point);
	else if (object->type == CONE)
		vector = normal_cone(object, point);
	else if (object->type == PLANE)
		vector = normal_plane(object, point);
	return (vector);
}
