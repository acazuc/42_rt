/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:36:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 13:23:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_cube_part2(t_cube *cube, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "position"))
		parse_point(cube->position, p);
	else if (!ft_strcmp(p->datas[p->count], "rotation"))
		parse_point(cube->rotation, p);
	else if (!ft_strcmp(p->datas[p->count], "reflection"))
		parse_reflection(&cube->reflection, p);
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
		parse_transparency(&cube->transparency, p);
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
		parse_brilliance(&cube->brilliance, p);
	else if (!ft_strcmp(p->datas[p->count], "size"))
		cube->size = parse_double(p, "Failed to read object size");
	else if (!ft_strcmp(p->datas[p->count], "regular"))
		cube->regular = 1;
	else if (!ft_strcmp(p->datas[p->count], "color"))
		cube->color = parse_color(p);
	else
		parse_error(p, "Unknown object's param entry");
}

static void		parse_cube_part(t_cube *cube, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "p1"))
		parse_point(cube->p1, p);
	else if (!ft_strcmp(p->datas[p->count], "p2"))
		parse_point(cube->p2, p);
	else if (!ft_strcmp(p->datas[p->count], "p3"))
		parse_point(cube->p3, p);
	else if (!ft_strcmp(p->datas[p->count], "p4"))
		parse_point(cube->p4, p);
	else if (!ft_strcmp(p->datas[p->count], "p5"))
		parse_point(cube->p5, p);
	else if (!ft_strcmp(p->datas[p->count], "p6"))
		parse_point(cube->p6, p);
	else if (!ft_strcmp(p->datas[p->count], "p7"))
		parse_point(cube->p7, p);
	else if (!ft_strcmp(p->datas[p->count], "p8"))
		parse_point(cube->p8, p);
	else
		parse_cube_part2(cube, p);
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
	parse_cube_check(cube);
	cube_add(env, cube);
	cube_free(cube);
}
