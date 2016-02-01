/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:17:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 13:35:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_triangle_part(t_object *triangle, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "p1"))
		parse_triangle_point(&triangle->position->x, &triangle->position->y
				, &triangle->position->z, p);
	else if (!ft_strcmp(p->datas[p->count], "p2"))
		parse_triangle_point(&triangle->rotation->x, &triangle->rotation->y
				, &triangle->rotation->z, p);
	else if (!ft_strcmp(p->datas[p->count], "p3"))
		parse_triangle_point(&triangle->dimensions[0], &triangle->dimensions[1]
				, &triangle->dimensions[2], p);
	else if (!ft_strcmp(p->datas[p->count], "reflection"))
		parse_reflection(&triangle->reflection, p);
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
		parse_transparency(&triangle->transparency, p);
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
		parse_brilliance(&triangle->brilliance, p);
	else if (!ft_strcmp(p->datas[p->count], "color"))
		triangle->color = parse_color(p);
	else
		parse_error(p, "Unknown object's param entry");
}

void			parse_triangle(t_env *env, t_parser *p)
{
	t_object	*triangle;

	triangle = create_triangle();
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_triangle_part(triangle, p);
		p->count++;
	}
	parse_object_check(triangle);
	object_add(env, triangle);
}
