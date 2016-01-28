/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_dimensions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:35:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 09:42:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		parse_object_dimensions_sphere(t_object *sphere
		, char **datas, int count)
{
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read sphere diametre");
	sphere->dimensions[0] = ft_atod(datas[count]);
	return (1);
}

static int		parse_object_dimensions_cylinder(t_object *cylinder
		, char **datas, int count)
{
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read cylinder diametre");
	cylinder->dimensions[0] = ft_atod(datas[count]);
	return (1);
}

int				parse_object_dimensions(t_object *object, char **datas, int count)
{
	if (object->type == SPHERE)
		return (parse_object_dimensions_sphere(object, datas, count));
	else if (object->type == CYLINDER)
		return (parse_object_dimensions_cylinder(object, datas, count));
	return (0);
}
