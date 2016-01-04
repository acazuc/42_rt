/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:08:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/04 14:15:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*normal_cone(t_object *cone, t_vector *point)
{
	t_vector *vector;

	vector = vector_create();
	vector->x = 0;
	vector->y = 0;
	vector->z = -1;
	(void)cone;
	(void)point;
	return (vector);
}
