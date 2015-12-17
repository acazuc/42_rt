/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:31:16 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/17 11:19:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

static void		add_mask(t_color_mask *mask, t_vector *normal_v, t_ray *ray
		, t_light *light)
{
	mask->red += MAX(0, cos(vector_angle(normal_v, ray->direction)))
				* light->luminosity * light->mask->red;
	mask->green += MAX(0, cos(vector_angle(normal_v, ray->direction)))
				* light->luminosity * light->mask->green;
	mask->blue += MAX(0, cos(vector_angle(normal_v, ray->direction)))
				* light->luminosity * light->mask->blue;
}

static void		loop(t_env *env, t_ray *ray, t_collision *origin
		, t_color_mask *mask)
{
	t_light_list	*list;
	t_collision		*collision;
	t_vector		*normal_v;

	list = env->lights;
	if (!(normal_v = normal(origin->object, origin->vector)))
		return ;
	while (list)
	{
		ray->direction->x = list->light->position->x - origin->vector->x;
		ray->direction->y = list->light->position->y - origin->vector->y;
		ray->direction->z = list->light->position->z - origin->vector->z;
		if (!((collision = trace(env, ray, origin->object))->object))
			add_mask(mask, normal_v, ray, list->light);
		else
			free(collision);
		list = list->next;
	}
	free(normal_v);
}

t_color_mask	*light_level(t_env *env, t_collision *origin)
{
	t_ray			*ray;
	t_color_mask	*mask;

	mask = color_mask_create();
	ray = ray_create();
	ray->origin->x = origin->vector->x;
	ray->origin->y = origin->vector->y;
	ray->origin->z = origin->vector->z;
	loop(env, ray, origin, mask);
	ray_free(ray);
	return (mask);
}
