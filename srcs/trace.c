/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:35:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/04 15:53:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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

static void			trace_init(t_collision **collision
		, double *nearest_distance, double *distance)
{
	*nearest_distance = -1;
	*distance = -1;
	*collision = collision_create();
}

static void			trace_put(t_collision *collision, t_vector *vector
		, t_object *object)
{
	free(collision->vector);
	collision->vector = vector;
	collision->object = object;
}

t_collision			*trace(t_env *env, t_ray *ray, t_object *avoid)
{
	t_vector		*vector;
	t_object_list	*list;
	t_collision		*collision;
	double			nearest_distance;
	double			distance;

	trace_init(&collision, &nearest_distance, &distance);
	list = env->objects;
	while (list)
	{
		if (!avoid || avoid != list->object)
		{
			if ((vector = collide(ray, list->object))
					&& (nearest_distance == -1
						| (distance = get_dst(ray, vector)) < nearest_distance))
			{
				trace_put(collision, vector, list->object);
				nearest_distance = distance;
			}
			else
				free(vector);
		}
		list = list->next;
	}
	return (collision);
}
