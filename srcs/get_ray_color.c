/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 09:36:37 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/18 08:54:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

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
	int				reflection_color;
	int				color;

	collision = trace(env, ray, avoid);
	if (collision->object)
	{
		mask = light_level(env, collision);
		color = color_mask(collision->object->color, mask);
		free(mask);
		if (collision->object->reflection > 0)
		{
			new_ray = get_reflection_ray(ray, collision);
			reflection_color = get_ray_color(env, new_ray, collision->object
					, recur + 1);
			color = get_reflect_color(color, reflection_color, collision);
			free(new_ray);
		}
	}
	else
		color = BLACK;
	free(collision);
	return (color);
}
