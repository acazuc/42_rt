/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:05:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/03 09:37:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*normal(t_object *object, t_vector *point)
{
	t_vector	*vector;

	vector = NULL;
	if (object->type == SPHERE)
		vector = normal_sphere(object, point);
	if (object->type == CYLINDER)
		vector = normal_cylinder(object, point);
	if (vector)
	{
		vector_rotate_z(vector, DTR(object->rotation->z));
		vector_rotate_x(vector, DTR(object->rotation->x));
	}
	return (vector);
}
