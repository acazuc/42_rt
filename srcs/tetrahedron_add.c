/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 09:37:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 14:38:40 by acazuc           ###   ########.fr       */
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
	t_object	*t1;
	t_object	*t2;
	t_object	*t3;
	t_object	*t4;

	t1 = create_triangle();
	set_properties(tetrahedron, t1);
	dup_values(t1, tetrahedron->p1, tetrahedron->p2, tetrahedron->p4);
	t2 = create_triangle();
	set_properties(tetrahedron, t2);
	dup_values(t2, tetrahedron->p2, tetrahedron->p3, tetrahedron->p4);
	t3 = create_triangle();
	set_properties(tetrahedron, t3);
	dup_values(t3, tetrahedron->p3, tetrahedron->p1, tetrahedron->p4);
	t4 = create_triangle();
	set_properties(tetrahedron, t4);
	dup_values(t4, tetrahedron->p1, tetrahedron->p2, tetrahedron->p3);
	object_add(env, t1);
	object_add(env, t2);
	object_add(env, t3);
	object_add(env, t4);
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
