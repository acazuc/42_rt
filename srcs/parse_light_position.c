/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:43:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 09:45:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_light_position(t_light *light, char **datas, int count)
{
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read light x position");
	light->position->x = ft_atod(datas[count++]);
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read light y position");
	light->position->y = ft_atod(datas[count++]);
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read light z position");
	light->position->z = ft_atod(datas[count++]);
}
