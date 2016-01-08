/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:37:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/08 16:15:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_object_vector(t_vector *vector, char **datas, int count)
{
	if (!datas[count])
		error_quit("Failed to read object x vector");
	vector->x = ft_atod(datas[count]);
	if (!datas[count + 1])
		error_quit("Failed to read object y vector");
	vector->y = ft_atod(datas[count + 1]);
	if (!datas[count + 2])
		error_quit("Failed to read object z vector");
	vector->z = ft_atod(datas[count + 2]);
}

static int		parse_object_dimensions(t_object *obj, char **datas, int count)
{
	if (obj->type == SPHERE)
	{
		if (datas[count])
			obj->dimensions[0] = ft_atod(datas[count]);
		else
			error_quit("Failed to read sphere diametre");
		return (1);
	}
	else if (obj->type == CYLINDER)
	{
		if (datas[count])
			obj->dimensions[0] = ft_atod(datas[count]);
		else
			error_quit("Failed to read cylinder diametre");
		return (1);
	}
	else
		error_quit("Only sphere and cylinder have dimensions");
	return (0);
}

static int		parse_object_part2(t_object *object, char **datas, int count)
{
	if (!ft_strcmp(datas[count], "reflection"))
	{
		if (!datas[count + 1])
			error_quit("Failed to read object reflection");
		object->reflection = ft_atod(datas[count + 1]);
		return (1);
	}
	else if (!ft_strcmp(datas[count], "transparency"))
	{
		if (!datas[count + 1])
			error_quit("Failed to read object transparency");
		object->transparency = ft_atod(datas[count + 1]);
		return (1);
	}
	error_quit("Unknown objet's param entry");
	return (0);
}

static int		parse_object_part(t_object *object, char **datas, int count)
{
	if (!datas[count])
		error_quit("Failed to read object's param entry");
	if (!ft_strcmp(datas[count], "position"))
	{
		parse_object_vector(object->position, datas, count + 1);
		return (3);
	}
	else if (!ft_strcmp(datas[count], "rotation"))
	{
		parse_object_vector(object->rotation, datas, count + 1);
		return (3);
	}
	else if (!ft_strcmp(datas[count], "dimensions"))
	{
		return (parse_object_dimensions(object, datas, count + 1));
	}
	else if (!ft_strcmp(datas[count], "color"))
	{
		if (!datas[count + 1])
			error_quit("Failed to read object color");
		object->color = parse_color(datas[count + 1]);
		return (1);
	}
	return (parse_object_part2(object, datas, count));
}

void			parse_object(t_object *object, char **datas)
{
	int		count;

	count = 1;
	while (datas[count])
	{
		count += parse_object_part(object, datas, count);
		count++;
	}
}
