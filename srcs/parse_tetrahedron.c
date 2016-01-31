/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tetrahedron.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 08:55:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 11:47:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_tetrahedron_part(t_tetrahedron *tetrahedron, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "p1"))
		parse_point(tetrahedron->p1, p);
	else if (!ft_strcmp(p->datas[p->count], "p2"))
		parse_point(tetrahedron->p2, p);
	else if (!ft_strcmp(p->datas[p->count], "p3"))
		parse_point(tetrahedron->p3, p);
	else if (!ft_strcmp(p->datas[p->count], "p4"))
		parse_point(tetrahedron->p4, p);
	else if (!ft_strcmp(p->datas[p->count], "position"))
		parse_point(tetrahedron->position, p);
	else if (!ft_strcmp(p->datas[p->count], "rotation"))
		parse_point(tetrahedron->rotation, p);
	else if (!ft_strcmp(p->datas[p->count], "reflection"))
		parse_reflection(&tetrahedron->reflection, p);
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
		parse_transparency(&tetrahedron->transparency, p);
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
		parse_brilliance(&tetrahedron->brilliance, p);
	else if (!ft_strcmp(p->datas[p->count], "regular"))
		tetrahedron->regular = 1;
	else if (!ft_strcmp(p->datas[p->count], "color"))
		tetrahedron->color = parse_color(p);
	else
		parse_error(p, "Unknown object's param entry");
}

void	parse_tetrahedron(t_env *env, t_parser *p)
{
	t_tetrahedron	*tetrahedron;

	tetrahedron = create_tetrahedron();
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_tetrahedron_part(tetrahedron, p);
		p->count++;
	}
	parse_tetrahedron_check(tetrahedron);
	tetrahedron_add(env, tetrahedron);
	tetrahedron_free(tetrahedron);
}
