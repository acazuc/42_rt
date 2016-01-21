/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 09:36:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/21 16:11:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"



static void	check_reflection(t_env *env, t_ray *ray, t_ray_data *data
		, int recur)
{
	t_ray			*new_ray;
	int				temp_color;

	if (data->collision->object->reflection > 0)
	{
		new_ray = get_reflection_ray(ray, data->collision);
		temp_color = get_ray_color(env, new_ray, data->collision->object
				, recur + 1);
		data->color = color_add(color_factor(data->color
						, (1 - data->collision->object->reflection))
				, color_factor(temp_color
					, data->collision->object->reflection));
		ray_free(new_ray);
	}
}

static void	check_transparency(t_env *env, t_ray *ray, t_ray_data *data
		, int recur)
{
	t_ray			*new_ray;
	int				temp_color;

	if (data->collision->object->transparency > 0)
	{
		new_ray = get_transparency_ray(ray, data->collision);
		temp_color = get_ray_color(env, new_ray, data->collision->object
				, recur);
		data->color = color_add(color_factor(data->color
						, (1 - data->collision->object->transparency))
				, color_factor(temp_color
					, data->collision->object->transparency));
		ray_free(new_ray);
	}
}

static int	check_specular(int color, t_ray_data *data
		, t_color_mask *mask)
{
	int				spec_color;
	int				result;

	if (data->collision->object->brilliance <= 0)
		return (color);
	spec_color = color_mask(0xFFFFFF, mask);
	result = color_add(color, spec_color);
	return (result);
}

int			get_ray_color(t_env *env, t_ray *ray, t_object *avoid, int recur)
{
	t_ray_data		data;

	data.color = BLACK;
	if ((data.collision = trace(env, ray, avoid)) && data.collision->vector
			&& recur <= env->max_recur)
	{
		data.data = light_level(env, ray, data.collision);
		data.color = color_factor(color_mask(data.collision->object->color
					, data.data->mask), 1 - env->ambient_light);
		data.color = check_specular(data.color, &data, data.data->spec);
		check_reflection(env, ray, &data, recur);
		check_transparency(env, ray, &data, recur);
		light_data_free(data.data);
	}
	collision_free(data.collision);
	return (data.color);
}
