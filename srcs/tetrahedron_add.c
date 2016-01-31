/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 09:37:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 16:01:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_properties(t_tetrahedron *tetrahedron, t_object *triangle)
{
	triangle->transparency = tetrahedron->transparency;
	triangle->reflection = tetrahedron->reflection;
	triangle->brilliance = tetrahedron->brilliance;
	triangle->color = tetrahedron->color;
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

static void		tetrahedron_add_points(t_env *env, t_tetrahedron *tetrahedron)
{
	t_object	*t;

	t = create_triangle();
	set_properties(tetrahedron, t);
	dup_values(t, tetrahedron->p1, tetrahedron->p2, tetrahedron->p4);
	object_add(env, t);
	t = create_triangle();
	set_properties(tetrahedron, t);
	dup_values(t, tetrahedron->p2, tetrahedron->p3, tetrahedron->p4);
	object_add(env, t);
	t = create_triangle();
	set_properties(tetrahedron, t);
	dup_values(t, tetrahedron->p3, tetrahedron->p1, tetrahedron->p4);
	object_add(env, t);
	t = create_triangle();
	set_properties(tetrahedron, t);
	dup_values(t, tetrahedron->p1, tetrahedron->p2, tetrahedron->p3);
	object_add(env, t);
}

void			tetrahedron_add(t_env *env, t_tetrahedron *tetrahedron)
{
	if (tetrahedron->regular)
	{
		tetrahedron_add_regular(tetrahedron);
		tetrahedron_add_rotate(tetrahedron);
		tetrahedron_add_moves(tetrahedron);
	}
	tetrahedron_add_points(env, tetrahedron);
}
