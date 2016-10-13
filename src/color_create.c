/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:57:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/09 16:59:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		color_create(unsigned char red, unsigned char green, unsigned char blue)
{
	int		r;
	int		g;
	int		b;

	r = 0xFF0000 * (red / 255.);
	r = r - r % 0x010000;
	g = 0x00FF00 * (green / 255.);
	g = g % 0x010000;
	g = g - g % 0x000100;
	b = 0x0000FF * (blue / 255.);
	b = b % 0x000100;
	return (r + g + b);
}
