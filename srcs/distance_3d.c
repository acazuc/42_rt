/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 09:24:31 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/11 09:27:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

double		distance_3d(t_vector *v1, t_vector *v2)
{
	double	dx;
	double	dy;
	double	dz;

	dx = pow(v2->x - v1->x, 2);
	dy = pow(v2->y - v1->y, 2);
	dz = pow(v2->z - v1->z, 2);
	return (sqrt(dx + dy + dz));
}
