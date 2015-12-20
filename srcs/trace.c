/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:35:38 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/20 15:21:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

static double		get_dst(t_ray *ray, t_vector *vector)
{
	double			dx;
	double			dy;
	double			dz;

	dx = vector->x - ray->origin->x;
	dy = vector->y - ray->origin->y;
	dz = vector->z - ray->origin->z;
	return (sqrt(dx * dx + dy * dy + dz * dz));
}

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
		{
			if ((vector = collide(ray, list->object))
					&& (nearest_distance == -1
						| (distance = get_dst(ray, vector)) < nearest_distance))
			{
				free(collision->vector);
				collision->vector = vector;
				collision->object = list->object;
				nearest_distance = distance;
			}
			else
				free(vector);
		}
		list = list->next;
	}
	return (collision);
}
