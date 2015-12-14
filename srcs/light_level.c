/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:31:16 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/14 12:17:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

double	light_level(t_env *env, t_vector *vector)
{
	t_light_list	*list;
	t_collision		*collision;
	t_ray			*ray;
	double			level;

	level = 0;
	ray = ray_create();
	ray->origin->x = vector->x;
	ray->origin->y = vector->y;
	ray->origin->z = vector->z;
	list = env->lights;
	while (list)
	{
		ray->direction->x = list->light->position->x - vector->x;
		ray->direction->y = list->light->position->y - vector->y;
		ray->direction->z = list->light->position->z - vector->z;
		collision = trace(env, ray);
		level += MAX(0, list->light->luminosity
				* (1.5 - vector_size(ray->direction)) / 1.5);
		list = list->next;
	}
	ray_free(ray);
	return (level);
}
