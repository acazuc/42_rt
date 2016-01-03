/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 07:00:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/03 16:39:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*normal_sphere(t_object *sphere, t_vector *point)
{
	t_vector	*vector;

	/*vector = vector_create();
	vector->x = point->x - sphere->position->x;
	vector->y = point->y - sphere->position->y;
	vector->z = point->z - sphere->position->z;*/
	vector = vector_create();
	vector->x = point->x - sphere->position->x;
	vector->y = point->y - sphere->position->y;
	vector->z = point->z - sphere->position->z;
	vector_unrotate(vector, sphere->rotation);
	vector->x = point->x + vector->x - sphere->position->x;
	vector->y = point->y + vector->y - sphere->position->y;
	vector->z = point->z + vector->z - sphere->position->z;
	vector_rotate(vector, sphere->rotation);
	return (vector);
}
