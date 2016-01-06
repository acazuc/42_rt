/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 07:00:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/06 15:42:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*normal_cylinder(t_object *cylinder, t_vector *point)
{
	t_vector	*vector;

	vector = vector_create();
	vector->x = point->x - cylinder->position->x;
	vector->y = 0;
	vector->z = point->z - cylinder->position->z;
	return (vector);
}
