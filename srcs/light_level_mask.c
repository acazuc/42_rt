/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_level_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:53:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 09:11:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		add_mask_transparency(t_env *env, t_collision *coll
		, t_light_level *ll, t_light *light)
{
	t_color_mask	*mask;
	t_vector		*lrd;
	t_vector		*nm_bck;
	double			cot;

	cot = coll->object->transparency;
	lrd = ll->ray->direction;
	nm_bck = coll->normal;
	mask = light_level(env, ll->origin_ray, coll);
	coll->normal = nm_bck;
	ll->mask->red += MAX(0, cos(vector_angle(ll->origin->normal, lrd))) *
				light->luminosity * light->mask->red * cot;
	ll->mask->green += MAX(0, cos(vector_angle(ll->origin->normal, lrd))) *
				light->luminosity * light->mask->green * cot;
	ll->mask->blue += MAX(0, cos(vector_angle(ll->origin->normal, lrd))) *
				light->luminosity * light->mask->blue * cot;
	free(mask);
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
