/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:52:58 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/12 14:19:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

double		collide(t_env *env, t_vector *vector, t_object *object)
{
	if (object->type == SPHERE)
		return (collide_sphere(env, vector, object));
	return (-1);
}
