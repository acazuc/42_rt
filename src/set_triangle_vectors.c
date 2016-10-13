/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_triangle_vectors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 10:10:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 11:13:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_triangle_vectors(t_object *triangle, t_vector *v1, t_vector *v2
		, t_vector *v3)
{
	triangle->position->x = v1->x;
	triangle->position->y = v1->y;
	triangle->position->z = v1->z;
	triangle->rotation->x = v2->x;
	triangle->rotation->y = v2->y;
	triangle->rotation->z = v2->z;
	triangle->dimensions[0] = v3->x;
	triangle->dimensions[1] = v3->y;
	triangle->dimensions[2] = v3->z;
}
