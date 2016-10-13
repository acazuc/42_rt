/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:58:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 13:12:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj	*create_obj(void)
{
	t_obj	*obj;

	if (!(obj = malloc(sizeof(*obj))))
		error_quit("Failed to malloc obj");
	obj->position = vector_create();
	obj->rotation = vector_create();
	obj->reflection = 0;
	obj->transparency = 0;
	obj->brilliance = 0;
	obj->file = NULL;
	obj->color = WHITE;
	return (obj);
}
