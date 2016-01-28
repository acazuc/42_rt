/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:37:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 09:42:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	parse_object_check(object);
}
