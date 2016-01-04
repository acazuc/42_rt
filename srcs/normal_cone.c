/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:08:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/04 15:07:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*normal_cone(t_object *cone, t_vector *point)
{
	t_vector *vector;

	vector = vector_create();
	vector->x = point->x - cone->position->x;
	vector->y = point->y - cone->position->y;
	vector->z = point->z - cone->position->z;
	vector_unrotate(vector, cone->rotation);
	vector->x = vector->x;
	vector->y = -vector->y;
	vector->z = vector->z;
	vector_rotate(vector, cone->rotation);
	return (vector);
}
