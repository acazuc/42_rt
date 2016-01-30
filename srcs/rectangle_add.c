/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 10:53:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 11:09:31 by acazuc           ###   ########.fr       */
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

static void		dup_values(t_object *triangle, t_vector *v1, t_vector *v2
		, t_vector *v3)
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

void	rectangle_add(t_env *env, t_rectangle *rectangle)
{
	t_object	*t1;
	t_object	*t2;

	t1 = create_triangle();
	set_properties(rectangle, t1);
	dup_values(t1, rectangle->p1, rectangle->p2, rectangle->p4);
	t2 = create_triangle();
	set_properties(rectangle, t2);
	dup_values(t2, rectangle->p2, rectangle->p3, rectangle->p4);
	object_add(env, t1);
	object_add(env, t2);
	rectangle_free(rectangle);
}
