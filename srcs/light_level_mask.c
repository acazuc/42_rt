/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_level_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:53:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/08 10:17:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		add_mask_smooth(t_color_mask *mask, t_vector *normal_v
		, t_ray *ray, t_light_collision *data)
{
	t_color_mask	*m;
	t_vector		*nm;
	t_vector		*rd;
	double			ll;

	m = data->light->mask;
	nm = data->collision->normal;
	rd = ray->direction;
	ll = data->light->luminosity;
	if (data->collision->object->type != SPHERE
			&& data->collision->object->type != CYLINDER
			&& data->collision->object->type != CONE)
		return ;
	mask->red += MAX(0, cos(vector_angle(normal_v, rd))) * ll * m->red *
				MAX(0, 1 - 20 * (1 - sin(vector_angle(rd, nm))));
	mask->green += MAX(0, cos(vector_angle(normal_v, rd))) * ll * m->green *
				MAX(0, 1 - 20 * (1 - sin(vector_angle(rd, nm))));
	mask->blue += MAX(0, cos(vector_angle(normal_v, rd))) * ll * m->blue *
				MAX(0, 1 - 20 * (1 - sin(vector_angle(rd, nm))));
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
