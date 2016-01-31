/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pentagon.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:15:36 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 09:14:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_pentagon_part(t_pentagon *pentagon, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "p1"))
		parse_point(pentagon->p1, p);
	else if (!ft_strcmp(p->datas[p->count], "p2"))
		parse_point(pentagon->p2, p);
	else if (!ft_strcmp(p->datas[p->count], "p3"))
		parse_point(pentagon->p3, p);
	else if (!ft_strcmp(p->datas[p->count], "p4"))
		parse_point(pentagon->p4, p);
	else if (!ft_strcmp(p->datas[p->count], "p5"))
		parse_point(pentagon->p5, p);
	else if (!ft_strcmp(p->datas[p->count], "reflection"))
		pentagon->reflection = parse_double(p
				, "Failed to read object reflection");
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
		pentagon->transparency = parse_double(p
				, "Failed to read object transparency");
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
		pentagon->brilliance = parse_double(p
				, "Failed to read object brilliance");
	else if (!ft_strcmp(p->datas[p->count], "color"))
		pentagon->color = parse_color(p);
	else
		parse_error(p, "Unknown object's param entry");
}

void			parse_pentagon(t_env *env, t_parser *p)
{
	t_pentagon		*pentagon;

	pentagon = create_pentagon();
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_pentagon_part(pentagon, p);
		p->count++;
	}
	parse_pentagon_check(pentagon);
	pentagon_add(env, pentagon);
	pentagon_free(pentagon);
}
