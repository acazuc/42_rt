/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:05:13 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 14:45:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*normal(t_object *object, t_vector *point)
{
	if (object->type == SPHERE)
		return (normal_sphere(object, point));
	if (object->type == CYLINDER)
		return (normal_cylinder(object, point));
	return (NULL);
}
