/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:37:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/29 10:55:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_object_part2(t_object *object, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "reflection"))
	{
		if (!p->datas[p->count++] || !parse_valid_number(p->datas[p->count]))
			parse_error(p, "Failed to read object reflection");
		object->reflection = ft_atod(p->datas[p->count]);
	}
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
	{
		if (!p->datas[p->count++] || !parse_valid_number(p->datas[p->count]))
			parse_error(p, "Failed to read object transparency");
		object->transparency = ft_atod(p->datas[p->count]);
	}
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
	{
		if (!p->datas[p->count++] || !parse_valid_number(p->datas[p->count]))
			parse_error(p, "Failed to read object brilliance");
		object->brilliance = ft_atod(p->datas[p->count]);
	}
	else
		parse_error(p, "Unknown objet's param entry");
}

static void		parse_object_part(t_object *object, t_parser *p)
{
	if (!p->datas[p->count])
		error_quit("Failed to read object's param entry");
	if (!ft_strcmp(p->datas[p->count], "position"))
	{
		p->count++;
		parse_object_position(object, p);
	}
	else if (!ft_strcmp(p->datas[p->count], "rotation"))
	{
		p->count++;
		parse_object_rotation(object, p);
	}
	else if (!ft_strcmp(p->datas[p->count], "dimensions"))
	{
		p->count++;
		parse_object_dimensions(object, p);
	}
	else if (!ft_strcmp(p->datas[p->count], "color"))
	{
		if (!p->datas[p->count++])
			parse_error(p, "Failed to read object color");
		object->color = parse_color(p->datas[p->count]);
	}
	else
		parse_object_part2(object, p);
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
