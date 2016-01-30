/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:36:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 11:47:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_cubve_part(t_cube *cube, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "p1"))
		parse_cube_point(cube->p1, p);
	else if (!ft_strcmp(p->datas[p->count], "p2"))
		parse_cube_point(cube->p2, p);
	else if (!ft_strcmp(p->datas[p->count], "p3"))
		parse_cube_point(cube->p3, p);
	else if (!ft_strcmp(p->datas[p->count], "p4"))
		parse_cube_point(cube->p4, p);
	else if (!ft_strcmp(p->datas[p->count], "p5"))
		parse_cube_point(cube->p5, p);
	else if (!ft_strcmp(p->datas[p->count], "p6"))
		parse_cube_point(cube->p6, p);
	else if (!ft_strcmp(p->datas[p->count], "reflection"))
		cube->reflection = parse_double(p, "Failed to read object reflection");
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
		cube->transparency = parse_double(p
				, "Failed to read object transparency");
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
		cube->brilliance = parse_double(p, "Failed to read object brilliance");
	else if (!ft_strcmp(p->datas[p->count], "color"))
		cube->color = parse_color(p);
	else
		parse_error(p, "Unknown object's param entry");
}

void			parse_cube(t_env *env, t_parser *p)
{
	t_cube	*cube;

	cube = create_cube();
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_cube_part(cube, p);
		p->count++;
	}
	cube_add(env, cube);
}
