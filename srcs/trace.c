/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:35:38 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/13 10:13:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

int					trace(t_env *env, t_ray *ray)
{
	t_object_list	*list;
	t_object		*nearest_object;
	double			nearest_distance;
	double			distance;

	nearest_object = NULL;
	nearest_distance = -1;
	list = env->objects;
	while (list)
	{
		if ((distance = collide(ray, list->object)) != -1
				&& (nearest_distance == -1 || distance < nearest_distance))
		{
			nearest_distance = distance;
			nearest_object = list->object;
		}
		list = list->next;
	}
	if (nearest_object)
		return (nearest_object->color);
	return (0);
}
