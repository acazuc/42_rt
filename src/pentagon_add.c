/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pentagon_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:39:59 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 16:03:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_properties(t_pentagon *pentagon, t_object *triangle)
{
	triangle->transparency = pentagon->transparency;
	triangle->reflection = pentagon->reflection;
	triangle->brilliance = pentagon->brilliance;
	triangle->color = pentagon->color;
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

static void		pentagon_add_points(t_env *env, t_pentagon *pentagon)
{
	t_object	*t;

	t = create_triangle();
	set_properties(pentagon, t);
	dup_values(t, pentagon->p2, pentagon->p1, pentagon->p5);
	object_add(env, t);
	t = create_triangle();
	set_properties(pentagon, t);
	dup_values(t, pentagon->p2, pentagon->p3, pentagon->p4);
	object_add(env, t);
	t = create_triangle();
	set_properties(pentagon, t);
	dup_values(t, pentagon->p2, pentagon->p5, pentagon->p4);
	object_add(env, t);
}

void			pentagon_add(t_env *env, t_pentagon *pentagon)
{
	if (pentagon->regular)
	{
		pentagon_add_regular(pentagon);
		pentagon_add_rotate(pentagon);
		pentagon_add_moves(pentagon);
	}
	pentagon_add_points(env, pentagon);
}
