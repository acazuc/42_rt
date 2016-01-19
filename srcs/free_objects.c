/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:45:33 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/19 15:53:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		object_free(t_object *object)
{
	free(object->position);
	free(object->rotation);
	free(object);
}

void			free_objects(t_env *env)
{
	t_object_list	*lst;
	t_object_list	*nxt;

	lst = env->objects;
	while (lst)
	{
		object_free(lst->object);
		nxt = lst->next;
		free(lst);
		lst = nxt;
	}
	env->objects = NULL;
}
