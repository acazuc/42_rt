/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 09:58:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 12:41:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_rectangle_part(t_rectangle *rectangle, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "p1"))
		parse_rectangle_point(rectangle->p1, p);
	else if (!ft_strcmp(p->datas[p->count], "p2"))
		parse_rectangle_point(rectangle->p2, p);
	else if (!ft_strcmp(p->datas[p->count], "p3"))
		parse_rectangle_point(rectangle->p3, p);
	else if (!ft_strcmp(p->datas[p->count], "p4"))
		parse_rectangle_point(rectangle->p4, p);
	else if (!ft_strcmp(p->datas[p->count], "reflection"))
		rectangle->reflection = parse_double(p
				, "Failed to read object reflection");
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
		rectangle->transparency = parse_double(p
				, "Failed to read object transparency");
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
		rectangle->brilliance = parse_double(p
				, "Failed to read object brilliance");
	else if (!ft_strcmp(p->datas[p->count], "color"))
		rectangle->color = parse_color(p);
	else
		parse_error(p, "Unknown object's param entry");
}

void			parse_rectangle(t_env *env, t_parser *p)
{
	t_rectangle		*rectangle;

	rectangle = create_rectangle();
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_rectangle_part(rectangle, p);
		p->count++;
	}
	parse_rectangle_check(rectangle);
	rectangle_add(env, rectangle);
}
