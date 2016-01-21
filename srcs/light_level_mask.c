/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_level_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:53:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/21 16:25:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		add_mask_transparency(t_collision *coll
		, t_light_level *ll, t_light *light)
{
	t_vector		*lrd;
	t_vector		*nm_bck;
	double			cot;

	cot = coll->object->transparency;
	lrd = ll->ray->direction;
	nm_bck = coll->normal;
	coll->normal = nm_bck;
	ll->mask->red += MAX(0, cos(vector_angle(ll->origin->normal, lrd))) *
				light->luminosity * light->mask->red * cot;
	ll->mask->green += MAX(0, cos(vector_angle(ll->origin->normal, lrd))) *
				light->luminosity * light->mask->green * cot;
	ll->mask->blue += MAX(0, cos(vector_angle(ll->origin->normal, lrd))) *
				light->luminosity * light->mask->blue * cot;
}

void		add_mask_specular(t_light_level *ll, t_light *light)
{
	double			angle_light;
	double			angle_ray;
	double			added;

	angle_light = vector_angle(ll->ray->direction, ll->origin->normal);
	angle_ray = vector_angle(ll->origin_ray->direction, ll->origin->normal);
	added = (-cos(angle_light - angle_ray) - .8) * 5.;
	if (added < 0)
		added = 0;
	ll->spec->red += added * light->mask->red;
	if (ll->spec->red > 1)
		ll->spec->red = 1;
	ll->spec->green += added * light->mask->green;
	if (ll->spec->green > 1)
		ll->spec->green = 1;
	ll->spec->blue += added * light->mask->blue;
	if (ll->spec->blue > 1)
		ll->spec->blue = 1;
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
