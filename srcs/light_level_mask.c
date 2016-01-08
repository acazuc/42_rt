/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_level_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:53:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/08 07:37:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		add_mask_smooth(t_color_mask *mask, t_vector *normal_v
		, t_ray *ray, t_light_collision *data)
{
	if (data->collision->object->type != SPHERE
			&& data->collision->object->type != CYLINDER
			&& data->collision->object->type != CONE)
		return ;
	mask->red += MAX(0, cos(vector_angle(normal_v, ray->direction))) *
				data->light->luminosity * data->light->mask->red *
				MAX(0, 1 - 20 *
						(1 - sin(vector_angle(ray->direction
											  , data->collision->normal))));
	mask->green += MAX(0, cos(vector_angle(normal_v, ray->direction))) *
				data->light->luminosity * data->light->mask->green *
				MAX(0, 1 - 20 *
						(1 - sin(vector_angle(ray->direction
											  , data->collision->normal))));
	mask->blue += MAX(0, cos(vector_angle(normal_v, ray->direction))) *
				data->light->luminosity * data->light->mask->blue *
				MAX(0, 1 - 20 *
						(1 - sin(vector_angle(ray->direction
											  , data->collision->normal))));
}

void		add_mask_specular(t_color_mask *mask, t_ray *ray
		, t_collision *collision, t_ray *origin_ray)
{
	double			angle_light;
	double			angle_ray;
	double			added;

	angle_light = vector_angle(ray->direction, collision->normal);
	angle_ray = vector_angle(origin_ray->direction, collision->normal);
	added = (-cos(angle_light - angle_ray) - .8) * 1.;
	if (added < 0)
		added = 0;
	added = 0;
	mask->red += added;
	mask->green += added;
	mask->blue += added;
}

void		add_mask(t_color_mask *mask, t_vector *normal_v, t_ray *ray
		, t_light *light)
{
	mask->red += MAX(0, cos(vector_angle(normal_v, ray->direction))) *
				light->luminosity * light->mask->red;
	mask->green += MAX(0, cos(vector_angle(normal_v, ray->direction))) *
				light->luminosity * light->mask->green;
	mask->blue += MAX(0, cos(vector_angle(normal_v, ray->direction))) *
				light->luminosity * light->mask->blue;
}
