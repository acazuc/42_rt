/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_factor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:37:19 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/19 08:34:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int		color_factor(int color, double factor)
{
	int		new_color;

	if (factor <= 0)
		return (0);
	new_color = 0;
	if (((int)color_get_red(color) * factor) > 255)
		new_color += 0xFF0000;
	else
		new_color += (int)((color_get_red(color) * factor)) << 16;
	if (((int)color_get_green(color) * factor) > 255)
		new_color += 0x00FF00;
	else
		new_color += (int)((color_get_green(color) * factor)) << 8;
	if (((int)color_get_blue(color) * factor) > 255)
		new_color += 0x0000FF;
	else
		new_color += (int)((color_get_blue(color) * factor));
	return (new_color);
}
