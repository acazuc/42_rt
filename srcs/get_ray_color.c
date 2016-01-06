/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 09:36:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/06 16:37:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	get_transparency_color(int color, int transparency_color
		, t_collision *collision)
{
	return (color_add(color_factor(color
						, (1 - collision->object->transparency))
				, color_factor(transparency_color
					, collision->object->transparency)));
}

static int	get_reflect_color(int color, int reflection_color
		, t_collision *collision)
{
	return (color_add(color_factor(color
						, (1 - collision->object->reflection))
				, color_factor(reflection_color
					, collision->object->reflection)));
}

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
		data->color = get_reflect_color(data->color, temp_color
				, data->collision);
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
		data->color = get_transparency_color(data->color, temp_color
				, data->collision);
		ray_free(new_ray);
	}
}

int			get_ray_color(t_env *env, t_ray *ray, t_object *avoid, int recur)
{
	t_ray_data		data;

	data.color = BLACK;
	if ((data.collision = trace(env, ray, avoid)) && data.collision->vector
			&& recur <= env->max_recur)
	{
		data.mask = light_level(env, ray, data.collision);
		data.color = color_factor(color_mask(data.collision->object->color
					, data.mask), 1 - env->ambient_light);
		free(data.mask);
		check_reflection(env, ray, &data, recur);
		check_transparency(env, ray, &data, recur);
	}
	free(data.collision->vector);
	free(data.collision);
	return (data.color);
}
