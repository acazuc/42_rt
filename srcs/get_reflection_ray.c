/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflection_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:00:51 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/18 16:33:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

t_ray	*get_reflection_ray(t_ray *ray, t_collision *collision)
{
	t_vector	*normal_vector;
	t_ray		*new_ray;
	double		factor;

	new_ray = ray_create();
	vector_normalize(ray->direction);
	new_ray->origin->x = collision->vector->x;
	new_ray->origin->y = collision->vector->y;
	new_ray->origin->z = collision->vector->z;
	normal_vector = normal(collision->object, collision->vector);
	vector_normalize(normal_vector);
	factor = ray->direction->x * normal_vector->x
		+ ray->direction->y * normal_vector->y
		+ ray->direction->z * normal_vector->z;
	new_ray->direction->x = ray->direction->x - 2 * factor * normal_vector->x;
	new_ray->direction->y = ray->direction->y - 2 * factor * normal_vector->y;
	new_ray->direction->z = ray->direction->z - 2 * factor * normal_vector->z;
	free(normal_vector);
	return (new_ray);
}
