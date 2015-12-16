/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:35:38 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/15 13:27:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

t_collision			*trace(t_env *env, t_ray *ray, t_object *avoid)
{
	t_vector		*vector;
	t_object_list	*list;
	t_collision		*collision;
	double			nearest_distance;
	double			distance;

	nearest_distance = -1;
	distance = -1;
	list = env->objects;
	collision = collision_create();
	while (list)
	{
		if (!avoid || avoid != list->object)
			if ((vector = collide(ray, list->object))
					&& (nearest_distance == -1
						| (distance = vector_size(vector)) < nearest_distance))
			{
				collision->vector = vector;
				collision->object = list->object;
				nearest_distance = distance;
			}
		list = list->next;
	}
	return (collision);
}
