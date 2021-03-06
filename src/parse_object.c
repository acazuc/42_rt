/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:37:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 09:27:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_object_part(t_object *object, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "position"))
		parse_object_position(object, p);
	else if (!ft_strcmp(p->datas[p->count], "rotation"))
		parse_object_rotation(object, p);
	else if (!ft_strcmp(p->datas[p->count], "dimensions"))
		parse_object_dimensions(object, p);
	else if (!ft_strcmp(p->datas[p->count], "color"))
		object->color = parse_color(p);
	else if (!ft_strcmp(p->datas[p->count], "reflection"))
		parse_reflection(&object->reflection, p);
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
		parse_transparency(&object->transparency, p);
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
		parse_brilliance(&object->brilliance, p);
	else
		parse_error(p, "Unknown objet's param entry");
}

void			parse_object(t_object *object, t_parser *p)
{
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_object_part(object, p);
		p->count++;
	}
	parse_object_check(object);
}
