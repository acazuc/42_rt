/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflection_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:00:51 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/17 17:13:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

/*
 * r=d−2(d⋅n)n
 */

t_ray	*get_reflection_ray(t_ray *ray, t_collision *collision)
{
	t_vector	*normal_vector;
	t_ray		*new_ray;

	new_ray = ray_create();
	vector_normalize(ray->direction);
	new_ray->origin->x = collision->vector->x;
	new_ray->origin->y = collision->vector->y;
	new_ray->origin->z = collision->vector->z;
	normal_vector = normal(collision->object, collision->vector);
	vector_normalize(normal_vector);
	/*new_ray->direction->x = normal_vector->x + normal_vector->x + ray->direction->x;
	new_ray->direction->y = normal_vector->y + normal_vector->y + ray->direction->y;
	new_ray->direction->z = normal_vector->z + normal_vector->z + ray->direction->z*/;
	double factor = ray->direction->x * normal_vector->x + ray->direction->y * normal_vector->y + ray->direction->z * normal_vector->z;
	new_ray->direction->x = ray->direction->x - 2 * factor * normal_vector->x;
	new_ray->direction->y = ray->direction->y - 2 * factor * normal_vector->y;
	new_ray->direction->z = ray->direction->z - 2 * factor * normal_vector->z;
	free(normal_vector);
	return (new_ray);
}
