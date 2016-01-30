/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:32:48 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 17:36:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_properties(t_cube *cube, t_rectangle *rectangle)
{
	rectangle->transparency = cube->transparency;
	rectangle->reflection = cube->reflection;
	rectangle->brilliance = cube->brilliance;
	rectangle->color = cube->color;
}

static void		set_points(t_cube *cube, t_rectangle *rectangle, int face)
{
	vector_dup(rectangle->p1, cube_add_point_1(cube, face));
	vector_dup(rectangle->p2, cube_add_point_2(cube, face));
	vector_dup(rectangle->p3, cube_add_point_3(cube, face));
	vector_dup(rectangle->p4, cube_add_point_4(cube, face));
}

void			cube_add(t_env *env, t_cube *cube)
{
	t_rectangle		*r;
	int				i;

	i = 1;
	while (i <= 6)
	{
		r = create_rectangle();
		set_properties(cube, r);
		set_points(cube, r, i);
		rectangle_add(env, r);
		rectangle_free(r);
		i++;
	}
}
