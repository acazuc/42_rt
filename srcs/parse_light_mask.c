/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:46:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 09:50:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_light_mask(t_light *light, char **datas, int count)
{
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read light red mask");
	light->mask->red = ft_atod(datas[count++]);
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read light green mask");
	light->mask->green = ft_atod(datas[count++]);
	if (!datas[count] || !parse_valid_number(datas[count]))
		error_quit("Failed to read light blue mask");
	light->mask->blue = ft_atod(datas[count++]);
}
