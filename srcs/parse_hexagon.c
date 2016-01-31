/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hexagon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:42:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:00:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_hexagon_part2(t_hexagon *hexagon, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "reflection"))
		parse_reflection(&hexagon->reflection, p);
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
		parse_transparency(&hexagon->transparency, p);
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
		parse_brilliance(&hexagon->brilliance, p);
	else if (!ft_strcmp(p->datas[p->count], "size"))
		hexagon->size = parse_double(p, "Failed to read object size");
	else if (!ft_strcmp(p->datas[p->count], "regular"))
		hexagon->regular = 1;
	else if (!ft_strcmp(p->datas[p->count], "color"))
		hexagon->color = parse_color(p);
	else
		parse_error(p, "Unknown object's param entry");
}

static void		parse_hexagon_part(t_hexagon *hexagon, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "p1"))
		parse_point(hexagon->p1, p);
	else if (!ft_strcmp(p->datas[p->count], "p2"))
		parse_point(hexagon->p2, p);
	else if (!ft_strcmp(p->datas[p->count], "p3"))
		parse_point(hexagon->p3, p);
	else if (!ft_strcmp(p->datas[p->count], "p4"))
		parse_point(hexagon->p4, p);
	else if (!ft_strcmp(p->datas[p->count], "p5"))
		parse_point(hexagon->p5, p);
	else if (!ft_strcmp(p->datas[p->count], "p6"))
		parse_point(hexagon->p6, p);
	else if (!ft_strcmp(p->datas[p->count], "position"))
		parse_point(hexagon->position, p);
	else if (!ft_strcmp(p->datas[p->count], "rotation"))
		parse_point(hexagon->rotation, p);
	else
		parse_hexagon_part2(hexagon, p);
}

void			parse_hexagon(t_env *env, t_parser *p)
{
	t_hexagon	*hexagon;

	hexagon = create_hexagon();
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_hexagon_part(hexagon, p);
		p->count++;
	}
	parse_hexagon_check(hexagon);
	hexagon_add(env, hexagon);
	hexagon_free(hexagon);
}
