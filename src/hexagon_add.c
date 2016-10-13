/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexagon_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:35:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 16:03:47 by acazuc           ###   ########.fr       */
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

static void		hexagon_add_points(t_env *env, t_hexagon *hexagon)
{
	t_object	*t;

	t = create_triangle();
	set_properties(hexagon, t);
	dup_values(t, hexagon->p1, hexagon->p2, hexagon->p3);
	object_add(env, t);
	t = create_triangle();
	set_properties(hexagon, t);
	dup_values(t, hexagon->p1, hexagon->p3, hexagon->p6);
	object_add(env, t);
	t = create_triangle();
	set_properties(hexagon, t);
	dup_values(t, hexagon->p3, hexagon->p4, hexagon->p6);
	object_add(env, t);
	t = create_triangle();
	set_properties(hexagon, t);
	dup_values(t, hexagon->p6, hexagon->p4, hexagon->p5);
	object_add(env, t);
}

void			hexagon_add(t_env *env, t_hexagon *hexagon)
{
	if (hexagon->regular)
	{
		hexagon_add_regular(hexagon);
		hexagon_add_rotate(hexagon);
		hexagon_add_moves(hexagon);
	}
	hexagon_add_points(env, hexagon);
}
