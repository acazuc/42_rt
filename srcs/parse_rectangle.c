/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 09:58:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 09:29:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_rectangle_part(t_rectangle *rectangle, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "p1"))
		parse_point(rectangle->p1, p);
	else if (!ft_strcmp(p->datas[p->count], "p2"))
		parse_point(rectangle->p2, p);
	else if (!ft_strcmp(p->datas[p->count], "p3"))
		parse_point(rectangle->p3, p);
	else if (!ft_strcmp(p->datas[p->count], "p4"))
		parse_point(rectangle->p4, p);
	else if (!ft_strcmp(p->datas[p->count], "reflection"))
		parse_reflection(&rectangle->reflection, p);
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
		parse_transparency(&rectangle->transparency, p);
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
		parse_brilliance(&rectangle->brilliance, p);
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
	rectangle_free(rectangle);
}
