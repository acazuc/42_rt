/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:35:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/19 15:21:30 by acazuc           ###   ########.fr       */
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

static void			trace_init(double *nearest_distance, double *distance
		, t_collision **nearest)
{
	*nearest = collision_create();
	*nearest_distance = -1;
	*distance = -1;
}

t_collision			*trace(t_env *env, t_ray *ray, t_object *avoid)
{
	t_object_list	*list;
	t_collision		*nearest;
	t_collision		*coll;
	double			nrst_dst;
	double			dst;

	trace_init(&nrst_dst, &dst, &nearest);
	list = env->objects;
	while (list)
	{
		if (!avoid || avoid != list->object)
		{
			if ((coll = collide(ray, list->object))->vector && (nrst_dst == -1
						| (dst = get_dst(ray, coll->vector)) < nrst_dst))
			{
				collision_free(nearest);
				nearest = coll;
				nrst_dst = dst;
			}
			else
				collision_free(coll);
		}
		list = list->next;
	}
	return (nearest);
}
