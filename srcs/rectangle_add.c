/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 10:53:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 10:14:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_properties(t_rectangle *rectangle, t_object *triangle)
{
	triangle->transparency = rectangle->transparency;
	triangle->reflection = rectangle->reflection;
	triangle->brilliance = rectangle->brilliance;
	triangle->color = rectangle->color;
}

void			rectangle_add(t_env *env, t_rectangle *rectangle)
{
	t_object	*t;

	t = create_triangle();
	set_properties(rectangle, t);
	set_triangle_vectors(t, rectangle->p1, rectangle->p2, rectangle->p4);
	object_add(env, t);
	t = create_triangle();
	set_properties(rectangle, t);
	set_triangle_vectors(t, rectangle->p2, rectangle->p3, rectangle->p4);
	object_add(env, t);
}
