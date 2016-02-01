/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 09:37:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 10:13:43 by acazuc           ###   ########.fr       */
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

static void		tetrahedron_add_points(t_env *env, t_tetrahedron *tetrahedron)
{
	t_object	*t;

	t = create_triangle();
	set_properties(tetrahedron, t);
	set_triangle_vectors(t, tetrahedron->p1, tetrahedron->p2, tetrahedron->p4);
	object_add(env, t);
	t = create_triangle();
	set_properties(tetrahedron, t);
	set_triangle_vectors(t, tetrahedron->p2, tetrahedron->p3, tetrahedron->p4);
	object_add(env, t);
	t = create_triangle();
	set_properties(tetrahedron, t);
	set_triangle_vectors(t, tetrahedron->p3, tetrahedron->p1, tetrahedron->p4);
	object_add(env, t);
	t = create_triangle();
	set_properties(tetrahedron, t);
	set_triangle_vectors(t, tetrahedron->p1, tetrahedron->p2, tetrahedron->p3);
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
