/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 07:43:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/09 13:39:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	vector_angle(t_vector *v1, t_vector *v2)
{
	double	angle;

	angle = acos(vector_dot(v1, v2) / (vector_size(v1) * vector_size(v2)));
	return (angle);
}
