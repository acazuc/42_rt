/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_rotation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:18:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 10:32:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_object_rotation(t_object *object, t_parser *p)
{
	object->rotation->x = parse_double(p, "Failed to read object x rotation");
	object->rotation->y = parse_double(p, "Failed to read object y rotation");
	object->rotation->z = parse_double(p, "Failed to read object z rotation");
}
