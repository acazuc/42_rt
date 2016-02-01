/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:41:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 14:18:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_obj_part(t_obj *obj, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "position"))
		parse_point(obj->position, p);
	else if (!ft_strcmp(p->datas[p->count], "rotation"))
		parse_point(obj->rotation, p);
	else if (!ft_strcmp(p->datas[p->count], "reflection"))
		parse_reflection(&obj->reflection, p);
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
		parse_transparency(&obj->transparency, p);
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
		parse_brilliance(&obj->brilliance, p);
	else if (!ft_strcmp(p->datas[p->count], "color"))
		obj->color = parse_color(p);
	else if (!ft_strcmp(p->datas[p->count], "file"))
		obj->file = p->datas[++p->count];
	else
		parse_error(p, "Unknown object's param entry");
}

void			parse_obj(t_env *env, t_parser *p)
{
	t_obj	*obj;

	obj = create_obj();
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_obj_part(obj, p);
		p->count++;
	}
	parse_obj_check(obj);
	obj_add(env, obj);
	obj_free(obj);
}
