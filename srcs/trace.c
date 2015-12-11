/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:35:38 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/11 16:16:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

static t_object		*get_nearest_object(t_env *env, t_vector *direction)
{
	t_object_list	*list;
	t_object		*nearest_object;
	double			nearest_distance;
	double			distance;

	nearest_object = NULL;
	nearest_distance = -1;
	list = env->objects;
	while (list)
	{
		if ((distance = collide(direction, list->object)) != -1)
			if (nearest_distance == -1 | distance < nearest_distance)
			{
				nearest_distance = distance;
				nearest_object = list->object;
			}
		list = list->next;
	}
	return (nearest_object);
}

int					trace(t_env *env, double angle_x, double angle_y)
{
	t_vector		*direction;
	t_object		*nearest_object;

	direction = vector_create();
	direction->x = sin(angle_y);
	direction->y = sin(angle_x);
	direction->z = cos(angle_x) * cos(angle_y);
	int red = 0xFF0000 * ABS(direction->x);
	red = red - red % 0x010000;
	int green = 0x00FF00 * ABS(direction->y);
	green = (green - green % 0x000100) % 0x010000;
	int blue = 0x0000FF * ABS(direction->z);
	blue = blue % 0x000100;
	return (red + green + blue);
	if ((nearest_object = get_nearest_object(env, direction)))
		return (nearest_object->color);
	return (0);
}
