/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 09:37:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 09:41:08 by acazuc           ###   ########.fr       */
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

void	tetrahedron_add(t_env *env, t_tetrahedron *tetrahedron)
{
	t_object	*t1;
	t_object	*t2;
	t_object	*t3;
	t_object	*t4;

	t1 = create_triangle();
	set_properties(tetrahedron, t1);
	t2 = create_triangle();
	set_properties(tetrahedron, t2);
	t3 = create_triangle();
	set_properties(tetrahedron, t3);
	t4 = create_triangle();
	set_properties(tetrahedron, t4);
}
