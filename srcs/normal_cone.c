/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:08:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/06 15:22:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*normal_cone(t_object *cone, t_vector *point)
{
	t_vector *vector;

	vector = vector_create();
	vector->x = point->x - cone->position->x;
	vector->y = -point->y + cone->position->y;
	vector->z = point->z - cone->position->z;
	return (vector);
}
