/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_level_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:53:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/07 09:02:14 by acazuc           ###   ########.fr       */
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
	t_vector		*normal_object;
	t_vector		light_vector;
	t_vector		ray_vector;
	double			angle_light;
	double			angle_ray;
	double			added;

	/*if (!(normal_object = normal(collision->object, collision->vector)))
		return ;
	light_vector.x = ray->direction->x;
	light_vector.y = ray->direction->y;
	light_vector.z = ray->direction->z;
	vector_normalize(&light_vector);
	angle_light = vector_angle(&light_vector, normal_object);
	ray_vector.x = origin_ray->direction->x;
	ray_vector.y = origin_ray->direction->y;
	ray_vector.z = origin_ray->direction->z;
	vector_normalize(&ray_vector);
	angle_ray = vector_angle(&ray_vector, normal_object);
	added = (-cos(angle_light - angle_ray) - .8) * 5;
	if (added < 0)
		added = 0;
	mask->red += added;
	mask->green += added;
	mask->blue += added;
	free(normal_object);*/
	(void)collision;
	(void)normal_object;
	(void)origin_ray;
	(void)light_vector;
	(void)ray_vector;
	(void)angle_light;
	(void)angle_ray;
	(void)added;
	(void)mask;
	(void)ray;
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
