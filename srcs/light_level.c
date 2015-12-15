/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:31:16 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/15 07:34:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

double	light_level(t_env *env, t_collision *origin)
{
	t_light_list	*list;
	t_collision		*collision;
	t_ray			*ray;
	double			level;

	level = 0;
	ray = ray_create();
	ray->origin->x = origin->vector->x;
	ray->origin->y = origin->vector->y;
	ray->origin->z = origin->vector->z;
	list = env->lights;
	while (list)
	{
		ray->direction->x = list->light->position->x - origin->vector->x;
		ray->direction->y = list->light->position->y - origin->vector->y;
		ray->direction->z = list->light->position->z - origin->vector->z;
		collision = trace(env, ray);
			level += MAX(0, list->light->luminosity
					* (2. - vector_size(ray->direction)) / 2.);
		list = list->next;
	}
	ray_free(ray);
	return (level);
}
