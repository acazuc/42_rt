/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 09:45:27 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 14:45:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray	*ray_create(void)
{
	t_ray	*ray;

	if (!(ray = malloc(sizeof(*ray))))
		error_quit("Failed to malloc ray");
	ray->direction = vector_create();
	ray->origin = vector_create();
	return (ray);
}
