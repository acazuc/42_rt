/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:17:37 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/17 10:34:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

int		color_add(int c1, int c2)
{
	int		red;
	int		green;
	int		blue;

	red = color_get_red(c1) + color_get_red(c2);
	if (red > 255)
		red = 255;
	green = color_get_green(c1) + color_get_green(c2);
	if (green > 255)
		green = 255;
	blue = color_get_blue(c1) + color_get_blue(c2);
	if (blue > 255)
		blue = 255;
	return ((red << 16) + (green << 8) + blue);
}
