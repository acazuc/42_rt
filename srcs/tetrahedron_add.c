/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 09:37:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 13:44:15 by acazuc           ###   ########.fr       */
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

static void		vector_moves(t_tetrahedron *tetrahedron)
{
	tetrahedron->p1->x += tetrahedron->position->x;
	tetrahedron->p1->y += tetrahedron->position->y;
	tetrahedron->p1->z += tetrahedron->position->z;
	tetrahedron->p2->x += tetrahedron->position->x;
	tetrahedron->p2->y += tetrahedron->position->y;
	tetrahedron->p2->z += tetrahedron->position->z;
	tetrahedron->p3->x += tetrahedron->position->x;
	tetrahedron->p3->y += tetrahedron->position->y;
	tetrahedron->p3->z += tetrahedron->position->z;
	tetrahedron->p4->x += tetrahedron->position->x;
	tetrahedron->p4->y += tetrahedron->position->y;
	tetrahedron->p4->z += tetrahedron->position->z;
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
	if (!tetrahedron->regular)
		tetrahedron_add_points(env, tetrahedron);
	if (!tetrahedron->regular)
		return ;
	tetrahedron->p1->x = 1 * tetrahedron->size / 2.;
	tetrahedron->p1->y = 1 * tetrahedron->size / 2.;
	tetrahedron->p1->z = 1 * tetrahedron->size / 2.;
	tetrahedron->p2->x = 1 * tetrahedron->size / 2.;
	tetrahedron->p2->y = -1 * tetrahedron->size / 2.;
	tetrahedron->p2->z = -1 * tetrahedron->size / 2.;
	tetrahedron->p3->x = -1 * tetrahedron->size / 2.;
	tetrahedron->p3->y = 1 * tetrahedron->size / 2.;
	tetrahedron->p3->z = -1 * tetrahedron->size / 2.;
	tetrahedron->p4->x = -1 * tetrahedron->size / 2.;
	tetrahedron->p4->y = -1 * tetrahedron->size / 2.;
	tetrahedron->p4->z = 1 * tetrahedron->size / 2.;
	vector_rotate(tetrahedron->p1, tetrahedron->rotation);
	vector_rotate(tetrahedron->p2, tetrahedron->rotation);
	vector_rotate(tetrahedron->p3, tetrahedron->rotation);
	vector_rotate(tetrahedron->p4, tetrahedron->rotation);
	vector_moves(tetrahedron);
	tetrahedron_add_points(env, tetrahedron);
}
