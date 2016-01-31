/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:09:21 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 16:00:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_properties_r(t_pyramid *pyramid, t_rectangle *rectangle)
{
	rectangle->transparency = pyramid->transparency;
	rectangle->reflection = pyramid->reflection;
	rectangle->brilliance = pyramid->brilliance;
	rectangle->color = pyramid->color;
}

static void		set_properties(t_pyramid *pyramid, t_object *triangle)
{
	triangle->transparency = pyramid->transparency;
	triangle->reflection = pyramid->reflection;
	triangle->brilliance = pyramid->brilliance;
	triangle->color = pyramid->color;
}

static void		set_points_r(t_pyramid *pyramid, t_rectangle *rectangle)
{
	vector_dup(rectangle->p1, pyramid->p1);
	vector_dup(rectangle->p2, pyramid->p2);
	vector_dup(rectangle->p3, pyramid->p3);
	vector_dup(rectangle->p4, pyramid->p4);
}

static void		set_points(t_object *triangle
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

static void		pyramid_add_points(t_env *env, t_pyramid *pyramid)
{
	t_rectangle		*r;
	t_object		*t;

	r = create_rectangle();
	set_properties_r(pyramid, r);
	set_points_r(pyramid, r);
	rectangle_add(env, r);
	rectangle_free(r);
	set_properties(pyramid, (t = create_triangle()));
	set_points(t, pyramid->p1, pyramid->p2, pyramid->p5);
	object_add(env, t);
	set_properties(pyramid, (t = create_triangle()));
	set_points(t, pyramid->p2, pyramid->p3, pyramid->p5);
	object_add(env, t);
	set_properties(pyramid, (t = create_triangle()));
	set_points(t, pyramid->p3, pyramid->p4, pyramid->p5);
	object_add(env, t);
	set_properties(pyramid, (t = create_triangle()));
	set_points(t, pyramid->p4, pyramid->p1, pyramid->p5);
	object_add(env, t);
}

void			pyramid_add(t_env *env, t_pyramid *pyramid)
{
	if (pyramid->regular)
	{
		pyramid_add_regular(pyramid);
		pyramid_add_rotate(pyramid);
		pyramid_add_moves(pyramid);
	}
	pyramid_add_points(env, pyramid);
}
