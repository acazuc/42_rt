/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:31:16 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/16 07:46:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

double	light_level(t_env *env, t_collision *origin)
{
	t_light_list	*list;
	t_collision		*collision;
	t_vector		*normal_v;
	t_ray			*ray;
	double			level;

	level = 0;
	ray = ray_create();
	ray->origin->x = origin->vector->x;
	ray->origin->y = origin->vector->y;
	ray->origin->z = origin->vector->z;
	list = env->lights;
	if (!(normal_v = normal(origin->object, origin->vector)))
		return (0);
	while (list)
	{
		ray->direction->x = list->light->position->x - origin->vector->x;
		ray->direction->y = list->light->position->y - origin->vector->y;
		ray->direction->z = list->light->position->z - origin->vector->z;
		if (!((collision = trace(env, ray, origin->object))->object))
			level += MAX(0, cos(vector_angle(normal_v, ray->direction)))
				* list->light->luminosity;
		list = list->next;
	}
	ray_free(ray);
	return (level);
}
