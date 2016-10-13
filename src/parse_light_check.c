/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 09:23:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/22 09:26:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_light_check(t_light *light)
{
	if (light->luminosity < 0)
		light->luminosity = 0;
	if (light->luminosity > 1)
		light->luminosity = 1;
	if (light->mask->red < 0)
		light->mask->red = 0;
	if (light->mask->red > 1)
		light->mask->red = 1;
	if (light->mask->green < 0)
		light->mask->green = 0;
	if (light->mask->green > 1)
		light->mask->green = 1;
	if (light->mask->blue < 0)
		light->mask->blue = 0;
	if (light->mask->blue > 1)
		light->mask->blue = 1;
}
