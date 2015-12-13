/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:57:20 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/13 17:02:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		color_create(unsigned char red, unsigned char green, unsigned char blue)
{
	int		color;

	color = 0xFF0000 * red + 0x00FF00 * green + 0x0000FF * blue;
	return (color);
}
