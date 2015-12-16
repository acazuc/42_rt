/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 15:40:01 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/16 09:33:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

t_light		*light_create(void)
{
	t_light		*light;

	if (!(light = malloc(sizeof(*light))))
		error_quit("Failed to malloc new light");
	light->position = vector_create();
	light->luminosity = 0;
	light->mask = color_mask_create();
	light->mask->red = 1;
	light->mask->green = 1;
	light->mask->blue = 1;
	return (light);
}
