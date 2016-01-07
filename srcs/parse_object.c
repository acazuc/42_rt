/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:37:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/07 16:03:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_object_position(t_object *object, char **datas, int count)
{
	if (datas[count])
		object->position->x = ft_atoi(datas[count]);
	else
		error_quit("Failed to read object x position");
	if (datas[count + 1])
		object->position->y = ft_atoi(datas[count + 1]);
	else
		error_quit("Failed to read object y position");
	if (datas[count + 2])
		object->position->z = ft_atoi(datas[count + 2]);
	else
		error_quit("Failed to read object z position");
}

static void		parse_object_rotation(t_object *object, char **datas, int count)
{
	if (datas[count])
		object->rotation->x = ft_atoi(datas[count]);
	else
		error_quit("Failed to read object x position");
	if (datas[count + 1])
		object->rotation->y = ft_atoi(datas[count + 1]);
	else
		error_quit("Failed to read object y position");
	if (datas[count + 2])
		object->rotation->z = ft_atoi(datas[count + 2]);
	else
		error_quit("Failed to read object z position");
}

static int		parse_object_dimensions(t_object* obj, char **datas, int count)
{
	if (obj->type == SPHERE)
	{
		if (datas[count])
			obj->dimensions[0] = ft_atoi(datas[count]);
		else
			error_quit("Failed to read sphere diametre");
		return (1);
	}
	else if (obj->type == CYLINDER)
	{
		if (datas[count])
			obj->dimensions[0] = ft_atoi(datas[count]);
		else
			error_quit("Failed to read cylinder diametre");
		return (1);
	}
	else
		error_quit("Only sphere and cylinder have dimensions");
	return (0);
}

static int		parse_object_part(t_object *object, char **datas, int count)
{
	if (!datas[count])
		error_quit("Failed to read object's param entry");
	if (!ft_strcmp(datas[count], "position"))
	{
		parse_object_position(object, datas, count + 1);
		return (3);
	}
	else if (!ft_strcmp(datas[count], "rotation"))
	{
		parse_object_rotation(object, datas, count + 1);
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
	error_quit("Unknown objet's param entry");
	return (0);
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
