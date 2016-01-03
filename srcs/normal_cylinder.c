/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 07:00:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/03 16:52:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*normal_cylinder(t_object *cylinder, t_vector *point)
{
	t_vector	*vector;

	vector = vector_create();
	vector->x = point->x - cylinder->position->x;
	vector->y = point->y - cylinder->position->y;
	vector->z = point->z - cylinder->position->z;
	vector_unrotate(vector, cylinder->rotation);
	vector->x = point->x + vector->x;
	vector->y = point->y + vector->y;
	vector->z = point->z + vector->z;
	vector_rotate(vector, cylinder->rotation);
	return (vector);
}
