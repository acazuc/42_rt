/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 09:20:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/22 09:22:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_object_check(t_object *object)
{
	if (object->transparency < 0)
		object->transparency = 0;
	if (object->transparency > 1)
		object->transparency = 1;
	if (object->reflection < 0)
		object->reflection = 0;
	if (object->reflection > 1)
		object->reflection = 1;
	if (object->brilliance < 0)
		object->brilliance = 0;
	if (object->brilliance > 1)
		object->brilliance = 1;
}
