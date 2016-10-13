/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:31:16 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/21 16:17:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		is_behind(t_vector *c_vector, t_vector *r_vector
		, t_vector *o_vector)
{
	if (r_vector->x < 0 && c_vector->x - o_vector->x < r_vector->x)
		return (1);
	if (r_vector->x > 0 && c_vector->x - o_vector->x > r_vector->x)
		return (1);
	if (r_vector->y < 0 && c_vector->y - o_vector->y < r_vector->y)
		return (1);
	if (r_vector->y > 0 && c_vector->y - o_vector->y > r_vector->y)
		return (1);
	if (r_vector->z < 0 && c_vector->z - o_vector->z < r_vector->z)
		return (1);
	if (r_vector->z > 0 && c_vector->z - o_vector->z > r_vector->z)
		return (1);
	return (0);
}

static void		loop_set_direction(t_ray *ray, t_light *light, t_vector *origin)
{
	ray->direction->x = light->position->x - origin->x;
	ray->direction->y = light->position->y - origin->y;
	ray->direction->z = light->position->z - origin->z;
}

static void		loop_set_data(t_light_collision *data, t_collision *collision
		, t_light *light)
{
	data->collision = collision;
	data->light = light;
}

static void		loop(t_env *env, t_light_level *ll)
{
	t_light_collision	data;
	t_light_list		*list;
	t_collision			*coll;

	list = env->lights;
	while (list)
	{
		loop_set_direction(ll->ray, list->light, ll->origin->vector);
		if (!((coll = trace(env, ll->ray, ll->origin->object))->vector)
				|| is_behind(coll->vector, ll->ray->direction, ll->ray->origin))
		{
			loop_set_data(&data, ll->origin, list->light);
			add_mask_specular(ll, list->light);
			add_mask(ll->mask, ll->origin->normal, ll->ray, list->light);
		}
		else
			add_mask_transparency(coll, ll, list->light);
		collision_free(coll);
		list = list->next;
	}
}

t_light_data	*light_level(t_env *env, t_ray *origin_ray, t_collision *origin)
{
	t_light_level	ll;
	t_ray			*ray;
	t_light_data	*data;

	data = light_data_create();
	data->mask = color_mask_create();
	data->spec = color_mask_create();
	ray = ray_create();
	ray->origin->x = origin->vector->x;
	ray->origin->y = origin->vector->y;
	ray->origin->z = origin->vector->z;
	ll.ray = ray;
	ll.origin_ray = origin_ray;
	ll.origin = origin;
	ll.spec = data->spec;
	ll.mask = data->mask;
	loop(env, &ll);
	ray_free(ray);
	return (data);
}
