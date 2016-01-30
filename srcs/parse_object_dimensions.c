/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_dimensions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:35:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 10:33:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_object_dimensions_sphere(t_object *sphere, t_parser *p)
{
	sphere->dimensions[0] = parse_double(p, "Failed to read sphere diametre");
}

static void		parse_object_dimensions_cyl(t_object *cylinder, t_parser *p)
{
	cylinder->dimensions[0] = parse_double(p
			, "Failed to read cylinder diametre");
}

void			parse_object_dimensions(t_object *object, t_parser *p)
{
	if (object->type == SPHERE)
		return (parse_object_dimensions_sphere(object, p));
	else if (object->type == CYLINDER)
		return (parse_object_dimensions_cyl(object, p));
}
