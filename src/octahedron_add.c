/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octahedron_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 10:07:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 13:34:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_properties(t_octahedron *octahedron, t_object *triangle)
{
	triangle->transparency = octahedron->transparency;
	triangle->reflection = octahedron->reflection;
	triangle->brilliance = octahedron->brilliance;
	triangle->color = octahedron->color;
}

static void		octahedron_add_points_2(t_env *env, t_octahedron *octahedron)
{
	t_object	*t;

	t = create_triangle();
	set_properties(octahedron, t);
	set_triangle_vectors(t, octahedron->p1, octahedron->p2, octahedron->p6);
	object_add(env, t);
	t = create_triangle();
	set_properties(octahedron, t);
	set_triangle_vectors(t, octahedron->p2, octahedron->p3, octahedron->p6);
	object_add(env, t);
	t = create_triangle();
	set_properties(octahedron, t);
	set_triangle_vectors(t, octahedron->p3, octahedron->p4, octahedron->p6);
	object_add(env, t);
	t = create_triangle();
	set_properties(octahedron, t);
	set_triangle_vectors(t, octahedron->p4, octahedron->p1, octahedron->p6);
	object_add(env, t);
}

static void		octahedron_add_points(t_env *env, t_octahedron *octahedron)
{
	t_object	*t;

	t = create_triangle();
	set_properties(octahedron, t);
	set_triangle_vectors(t, octahedron->p1, octahedron->p2, octahedron->p5);
	object_add(env, t);
	t = create_triangle();
	set_properties(octahedron, t);
	set_triangle_vectors(t, octahedron->p2, octahedron->p3, octahedron->p5);
	object_add(env, t);
	t = create_triangle();
	set_properties(octahedron, t);
	set_triangle_vectors(t, octahedron->p3, octahedron->p4, octahedron->p5);
	object_add(env, t);
	t = create_triangle();
	set_properties(octahedron, t);
	set_triangle_vectors(t, octahedron->p4, octahedron->p1, octahedron->p5);
	object_add(env, t);
	octahedron_add_points_2(env, octahedron);
}

void			octahedron_add(t_env *env, t_octahedron *octahedron)
{
	if (octahedron->regular)
	{
		octahedron_add_regular(octahedron);
		octahedron_add_rotate(octahedron);
		octahedron_add_moves(octahedron);
	}
	octahedron_add_points(env, octahedron);
}
