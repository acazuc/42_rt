/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:17:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/29 14:42:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_triangle_part2(t_object *triangle, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "reflection"))
	{
		if (!p->datas[++p->count] || !parse_valid_number(p->datas[p->count]))
			parse_error(p, "Failed to read object reflection");
		triangle->reflection = ft_atod(p->datas[p->count]);
	}
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
	{
		if (!p->datas[++p->count] || !parse_valid_number(p->datas[p->count]))
			parse_error(p, "Failed to read object transparency");
		triangle->transparency = ft_atod(p->datas[p->count]);
	}
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
	{
		if (!p->datas[++p->count] || !parse_valid_number(p->datas[p->count]))
			parse_error(p, "Failed to read object brilliance");
		triangle->brilliance = ft_atod(p->datas[p->count]);
	}
	else
		parse_error(p, "Unknown object's param entry");
}

static void		parse_triangle_part(t_object *triangle, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "p1"))
	{
		p->count++;
		parse_triangle_point(&triangle->position->x, &triangle->position->y
				, &triangle->position->z, p);
	}
	else if (!ft_strcmp(p->datas[p->count], "p2"))
	{
		p->count++;
		parse_triangle_point(&triangle->rotation->x, &triangle->rotation->y
				, &triangle->rotation->z, p);
	}
	else if (!ft_strcmp(p->datas[p->count], "p3"))
	{
		p->count++;
		parse_triangle_point(&triangle->dimensions[0], &triangle->dimensions[1]
				, &triangle->dimensions[2], p);
	}
	else if (!ft_strcmp(p->datas[p->count], "color"))
	{
		if (!p->datas[p->count])
			parse_error(p, "Failed to read object color");
		triangle->color = parse_color(p->datas[p->count]);
	}
	else
		parse_triangle_part2(triangle, p);
}

void	parse_triangle(t_object *triangle, t_parser *p)
{
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_triangle_part(triangle, p);
		p->count++;
	}
	parse_object_check(triangle);
}
