/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:49:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/08 08:32:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_light_position(t_light *light, char **datas, int count)
{
	if (datas[count])
		light->position->x = ft_atod(datas[count]);
	else
		error_quit("Failed to read light x position");
	if (datas[count + 1])
		light->position->y = ft_atod(datas[count + 1]);
	else
		error_quit("Failed to read light y position");
	if (datas[count + 2])
		light->position->z = ft_atod(datas[count + 2]);
	else
		error_quit("Failed to read light z position");
}

static void		parse_light_mask(t_light *light, char **datas, int count)
{
	if (datas[count])
		light->mask->red = ft_atod(datas[count]);
	else
		error_quit("Failed to read light red mask");
	if (datas[count + 1])
		light->mask->green = ft_atod(datas[count + 1]);
	else
		error_quit("Failed to read light green mask");
	if (datas[count + 2])
		light->mask->blue = ft_atod(datas[count + 2]);
	else
		error_quit("Failed to read light blue mask");
}

static int		parse_light_part(t_light *light, char **datas, int count)
{
	if (!datas[count])
		error_quit("Failed to read light's param entry");
	if (!ft_strcmp(datas[count], "position"))
	{
		parse_light_position(light, datas, count + 1);
		return (3);
	}
	else if (!ft_strcmp(datas[count], "color"))
	{
		parse_light_mask(light, datas, count + 1);
		return (3);
	}
	else if (!ft_strcmp(datas[count], "luminosity"))
	{
		if (datas[count + 1])
			light->luminosity = ft_atod(datas[count + 1]);
		else
			error_quit("Failed to parse light luminosity");
		return (1);
	}
	error_quit("Unknown light's param entry");
	return (0);
}

void			parse_light(t_light *light, char **datas)
{
	int		count;

	count = 1;
	while (datas[count])
	{
		count += parse_light_part(light, datas, count);
		count++;
	}
}
