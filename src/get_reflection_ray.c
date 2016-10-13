/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflection_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:00:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/08 16:40:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray	*get_reflection_ray(t_ray *ray, t_collision *coll)
{
	t_ray		*new_ray;
	double		factor;

	new_ray = ray_create();
	vector_normalize(ray->direction);
	new_ray->origin->x = coll->vector->x;
	new_ray->origin->y = coll->vector->y;
	new_ray->origin->z = coll->vector->z;
	factor = vector_dot(ray->direction, coll->normal);
	new_ray->direction->x = ray->direction->x - 2 * factor * coll->normal->x;
	new_ray->direction->y = ray->direction->y - 2 * factor * coll->normal->y;
	new_ray->direction->z = ray->direction->z - 2 * factor * coll->normal->z;
	return (new_ray);
}
