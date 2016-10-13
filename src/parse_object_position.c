/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:18:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 10:31:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_object_position(t_object *object, t_parser *p)
{
	object->position->x = parse_double(p, "Failed to read object x position");
	object->position->y = parse_double(p, "Failed to read object y position");
	object->position->z = parse_double(p, "Failed to read object z position");
}
