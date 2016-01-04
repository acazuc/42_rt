/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 07:00:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/04 11:19:58 by acazuc           ###   ########.fr       */
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
	vector->x = vector->x;
	vector->y = 0;
	vector->z = vector->z;
	vector_rotate(vector, cylinder->rotation);
	return (vector);
}
