/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexagon_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:35:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 16:47:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_properties(t_hexagon *hexagon, t_object *triangle)
{
	triangle->transparency = hexagon->transparency;
	triangle->reflection = hexagon->reflection;
	triangle->brilliance = hexagon->brilliance;
	triangle->color = hexagon->color;
}

static void		dup_values(t_object *triangle
		, t_vector *v1, t_vector *v2, t_vector *v3)
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

void			hexagon_add(t_env *env, t_hexagon *hexagon)
{
	t_object	*t1;
	t_object	*t2;
	t_object	*t3;
	t_object	*t4;

	t1 = create_triangle();
	set_properties(hexagon, t1);
	dup_values(t1, hexagon->p1, hexagon->p2, hexagon->p3);
	t2 = create_triangle();
	set_properties(hexagon, t2);
	dup_values(t2, hexagon->p1, hexagon->p3, hexagon->p6);
	t3 = create_triangle();
	set_properties(hexagon, t3);
	dup_values(t3, hexagon->p3, hexagon->p4, hexagon->p6);
	t4 = create_triangle();
	set_properties(hexagon, t4);
	dup_values(t4, hexagon->p6, hexagon->p4, hexagon->p5);
	object_add(env, t1);
	object_add(env, t2);
	object_add(env, t3);
	object_add(env, t4);
}
