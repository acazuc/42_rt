/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_rotation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:18:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 09:30:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_object_rotation(t_object *object, char **datas, int count)
{
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read object x rotation");
	object->rotation->x = ft_atod(datas[count++]);
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read object y rotation");
	object->rotation->y = ft_atod(datas[count++]);
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read object z rotation");
	object->rotation->z = ft_atod(datas[count++]);
}
