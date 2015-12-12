/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:35:38 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/12 15:16:42 by acazuc           ###   ########.fr       */
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
		if ((distance = collide(env, direction, list->object)) != -1)
			if (nearest_distance == -1 || distance < nearest_distance)
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
	if ((nearest_object = get_nearest_object(env, direction)))
		return (nearest_object->color);
	return (0);
}
