/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:52:58 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/11 15:30:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

double		collide(t_vector *vector, t_object *object)
{
	if (object->type == SPHERE)
		return (collide_sphere(vector, object));
	return (-1);
}
