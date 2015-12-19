/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 07:43:25 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/19 08:38:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

double	vector_angle(t_vector *v1, t_vector *v2)
{
	double	product;
	double	angle;

	product = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	angle = acos(product / (vector_size(v1) * vector_size(v2)));
	return (angle);
}
