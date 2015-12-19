/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mask.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 09:21:35 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/19 08:34:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int		color_mask(int color, t_color_mask *mask)
{
	int		red;
	int		green;
	int		blue;
	int		new_color;

	if (color <= 0)
		return (0);
	new_color = 0;
	red = color_get_red(color);
	green = color_get_green(color);
	blue = color_get_blue(color);
	if (red * mask->red > 255)
		new_color += 0xFF0000;
	else
		new_color += (int)(red * mask->red) << 16;
	if (green * mask->green > 255)
		new_color += 0x00FF00;
	else
		new_color += (int)(green * mask->green) << 8;
	if (blue * mask->blue > 255)
		new_color += 0x0000FF;
	else
		new_color += (blue * mask->blue);
	return (new_color);
}
