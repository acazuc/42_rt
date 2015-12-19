/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 08:50:43 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/19 11:04:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_object	*object_create(void)
{
	t_object	*object;

	if (!(object = malloc(sizeof(*object))))
		error_quit("Failed to malloc new object");
	object->position = vector_create();
	object->rotation = vector_create();
	object->dimensions[0] = 0;
	object->dimensions[1] = 0;
	object->dimensions[2] = 0;
	object->transparency = 0;
	object->reflection = 0;
	object->color = 0;
	return (object);
}
