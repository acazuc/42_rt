/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_dimensions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:35:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 16:18:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_object_dimensions_sphere(t_object *sphere, t_parser *p)
{
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read sphere diametre");
	sphere->dimensions[0] = ft_atod(p->datas[p->count]);
}

static void		parse_object_dimensions_cylinder(t_object *cylinder, t_parser *p)
{
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		error_quit("Failed to read cylinder diametre");
	cylinder->dimensions[0] = ft_atod(p->datas[p->count]);
}

void			parse_object_dimensions(t_object *object, t_parser *p)
{
	if (object->type == SPHERE)
		return (parse_object_dimensions_sphere(object, p));
	else if (object->type == CYLINDER)
		return (parse_object_dimensions_cylinder(object, p));
}
