/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_level_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:53:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/22 08:28:12 by acazuc           ###   ########.fr       */
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
	t_ray			*new_ray;
	double			angle;
	double			added;

	new_ray = get_reflection_ray(ll->origin_ray, ll->origin);
	vector_normalize(new_ray->direction);
	vector_normalize(ll->ray->direction);
	angle = vector_dot(new_ray->direction, ll->ray->direction);
	if (angle < 0)
		angle = 0;
	added = pow(angle, 500);
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
	ray_free(new_ray);
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
