/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_octahedron.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:26:21 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 10:06:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	parse_octahedron_part2(t_octahedron *octahedron, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "reflection"))
		parse_reflection(&octahedron->reflection, p);
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
		parse_transparency(&octahedron->transparency, p);
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
		parse_brilliance(&octahedron->brilliance, p);
	else if (!ft_strcmp(p->datas[p->count], "size"))
		octahedron->size = parse_double(p, "Failed to read object size");
	else if (!ft_strcmp(p->datas[p->count], "regular"))
		octahedron->regular = 1;
	else if (!ft_strcmp(p->datas[p->count], "color"))
		octahedron->color = parse_color(p);
	else
		parse_error(p, "Unknown object's param entry");
}

static void	parse_octahedron_part(t_octahedron *octahedron, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "p1"))
		parse_point(octahedron->p1, p);
	else if (!ft_strcmp(p->datas[p->count], "p2"))
		parse_point(octahedron->p2, p);
	else if (!ft_strcmp(p->datas[p->count], "p3"))
		parse_point(octahedron->p3, p);
	else if (!ft_strcmp(p->datas[p->count], "p4"))
		parse_point(octahedron->p4, p);
	else if (!ft_strcmp(p->datas[p->count], "p5"))
		parse_point(octahedron->p5, p);
	else if (!ft_strcmp(p->datas[p->count], "p6"))
		parse_point(octahedron->p6, p);
	else if (!ft_strcmp(p->datas[p->count], "position"))
		parse_point(octahedron->position, p);
	else if (!ft_strcmp(p->datas[p->count], "rotation"))
		parse_point(octahedron->rotation, p);
	else
		parse_octahedron_part2(octahedron, p);
}

void		parse_octahedron(t_env *env, t_parser *p)
{
	t_octahedron	*octahedron;

	octahedron = create_octahedron();
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_octahedron_part(octahedron, p);
		p->count++;
	}
	parse_octahedron_check(octahedron);
	octahedron_add(env, octahedron);
	octahedron_free(octahedron);
}
