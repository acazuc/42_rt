/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 09:36:37 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/19 11:05:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

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

int			get_ray_color(t_env *env, t_ray *ray, t_object *avoid, int recur)
{
	t_color_mask	*mask;
	t_collision		*collision;
	t_ray			*new_ray;
	int				transparency_color;
	int				reflection_color;
	int				color;

	color = BLACK;
	if ((collision = trace(env, ray, avoid))->object && recur <= env->max_recur)
	{
		mask = light_level(env, collision);
		color = color_factor(color_mask(collision->object->color, mask)
				, 1 - env->ambient_light);
		free(mask);
		if (collision->object->reflection > 0)
		{
			new_ray = get_reflection_ray(ray, collision);
			reflection_color = get_ray_color(env, new_ray, collision->object
					, recur + 1);
			color = get_reflect_color(color, reflection_color, collision);
			ray_free(new_ray);
		}
		if (collision->object->transparency > 0)
		{
			new_ray = get_transparency_ray(ray, collision);
			transparency_color = get_ray_color(env, new_ray, collision->object
					, recur);
			color = get_transparency_color(color, transparency_color, collision);
			ray_free(new_ray);
		}
	}
	free(collision->vector);
	free(collision);
	return (color);
}
