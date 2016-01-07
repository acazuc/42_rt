/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 07:34:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/05 07:42:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*normal_plane(t_object *plane, t_vector *point)
{
	t_vector	*vector;

	vector = vector_create();
	vector->y = 1;
	(void)plane;
	(void)point;
	return (vector);
}
