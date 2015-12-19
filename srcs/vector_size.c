/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:31:12 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/19 15:58:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

double	vector_size(t_vector *vector)
{
	double	dx;
	double	dy;
	double	dz;

	dx = vector->x * vector->x;
	dy = vector->y * vector->y;
	dz = vector->z * vector->z;
	return (sqrt(dx + dy + dz));
}
