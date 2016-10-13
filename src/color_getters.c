/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:00:43 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/14 10:05:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	color_get_red(int color)
{
	unsigned char	red;

	red = (unsigned char)(color >> 16);
	return (red);
}

unsigned char	color_get_green(int color)
{
	unsigned char	green;

	green = (unsigned char)(color >> 8);
	return (green);
}

unsigned char	color_get_blue(int color)
{
	unsigned char	blue;

	blue = (unsigned char)color;
	return (blue);
}
