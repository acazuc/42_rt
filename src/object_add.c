/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 08:55:16 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 14:45:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	object_add(t_env *env, t_object *object)
{
	t_object_list	*list;
	t_object_list	*new_item;

	if (!(new_item = malloc(sizeof(*new_item))))
		error_quit("Failed to malloc new object list item");
	new_item->object = object;
	new_item->next = NULL;
	if (!(env->objects))
		env->objects = new_item;
	else
	{
		list = env->objects;
		while (list->next)
			list = list->next;
		list->next = new_item;
	}
}
