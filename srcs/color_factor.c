/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_factor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:37:19 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/14 12:16:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

int		color_factor(int color, double factor)
{
	int		new_color;

	if (factor <= 0)
		return (0);
	new_color = 0;
	new_color += (int)((color_get_red(color) * factor)) << 16;
	new_color += (int)((color_get_green(color) * factor)) << 8;
	new_color += (int)(color_get_blue(color) * factor);
	return (new_color);
}
