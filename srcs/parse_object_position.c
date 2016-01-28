/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:18:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 09:35:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_object_position(t_object *object, char **datas, int count)
{
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read object x position");
	object->position->x = ft_atod(datas[count++]);
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read object y position");
	object->position->y = ft_atod(datas[count++]);
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read object z position");
	object->position->z = ft_atod(datas[count++]);
}
