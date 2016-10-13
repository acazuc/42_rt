/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_transparency_ray.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 09:51:53 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 14:44:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray	*get_transparency_ray(t_ray *ray, t_collision *collision)
{
	t_ray	*new_ray;

	new_ray = ray_create();
	new_ray->direction->x = ray->direction->x;
	new_ray->direction->y = ray->direction->y;
	new_ray->direction->z = ray->direction->z;
	new_ray->origin->x = collision->vector->x;
	new_ray->origin->y = collision->vector->y;
	new_ray->origin->z = collision->vector->z;
	return (new_ray);
}
