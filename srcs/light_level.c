/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:31:16 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/20 10:54:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

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

static void		add_mask_smooth(t_color_mask *mask, t_vector *normal_v
		, t_ray *ray, t_light_collision *data)
{
	t_vector		*normal_object;

	if (data->collision->object->type != SPHERE
			&& data->collision->object->type != CYLINDER
			&& data->collision->object->type != CONE)
		return ;
	if (!(normal_object = normal(data->collision->object
					, data->collision->vector)))
		return ;
	mask->red += MAX(0, cos(vector_angle(normal_v, ray->direction))) *
				data->light->luminosity * data->light->mask->red *
				MAX(0, 1 - 5 *
						(1 - sin(vector_angle(ray->direction, normal_object))));
	mask->green += MAX(0, cos(vector_angle(normal_v, ray->direction))) *
				data->light->luminosity * data->light->mask->green *
				MAX(0, 1 - 5 *
						(1 - sin(vector_angle(ray->direction, normal_object))));
	mask->blue += MAX(0, cos(vector_angle(normal_v, ray->direction))) *
				data->light->luminosity * data->light->mask->blue *
				MAX(0, 1 - 5 *
						(1 - sin(vector_angle(ray->direction, normal_object))));
}

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

static void		loop(t_env *env, t_ray *ray, t_collision *origin
		, t_color_mask *mask)
{
	t_light_collision	data;
	t_light_list		*list;
	t_collision			*collision;
	t_vector			*normal_v;

	list = env->lights;
	if (!(normal_v = normal(origin->object, origin->vector)))
		return ;
	while (list)
	{
		ray->direction->x = list->light->position->x - origin->vector->x;
		ray->direction->y = list->light->position->y - origin->vector->y;
		ray->direction->z = list->light->position->z - origin->vector->z;
		if (!((collision = trace(env, ray, origin->object))->object)
				|| is_behind(collision->vector, ray->direction, ray->origin))
			add_mask(mask, normal_v, ray, list->light);
		else if (collision->object)
		{
			data.collision = collision;
			data.light = list->light;
			add_mask_smooth(mask, normal_v, ray, &data);
		}
		free(collision->vector);
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
