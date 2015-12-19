/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialias.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 08:43:07 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/19 09:34:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

static void		antialias_pixel(char *antialiased, char *original, int x, int y, t_window *window)
{
	int		total_red;
	int		total_green;
	int		total_blue;
	int		number;

	total_red = original[(y * window->width + x) * window->bpp / 8 + 2];
	total_green = original[(y * window->width + x) * window->bpp / 8 + 1];
	total_blue = original[(y * window->width + x) * window->bpp / 8];
	number = 1;
	if (x > 0)
	{
		total_red += original[(y * window->width + x - 1) * window->bpp / 8 + 2];
		total_green += original[(y * window->width + x - 1) * window->bpp / 8 + 1];
		total_blue += original[(y * window->width + x - 1) * window->bpp / 8];
		number++;
	}
	if (x < window->width - 1)
	{
		total_red += original[(y * window->width + x + 1) * window->bpp / 8 + 2];
		total_green += original[(y * window->width + x + 1) * window->bpp / 8 + 1];
		total_blue += original[(y * window->width + x + 1) * window->bpp / 8];
		number++;
	}
	if (y > 0)
	{
		total_red += original[((y - 1) * window->width + x) * window->bpp / 8 + 2];
		total_green += original[((y - 1) * window->width + x) * window->bpp / 8 + 1];
		total_blue += original[((y - 1) * window->width + x) * window->bpp / 8];
		number++;
	}
	if (y < window->height - 1)
	{
		total_red += original[((y + 1) * window->width + x) * window->bpp / 8 + 2];
		total_green += original[((y + 1) * window->width + x) * window->bpp / 8 + 1];
		total_blue += original[((y + 1) * window->width + x) * window->bpp / 8];
		number++;
	}
	antialiased[(y * window->width + x) * window->bpp / 8 + 2] = total_red / number;
	antialiased[(y * window->width + x) * window->bpp / 8 + 1] = total_green / number;
	antialiased[(y * window->width + x) * window->bpp / 8] = total_blue / number;
}

void			antialias(t_window *window)
{
	char	*antialiased;
	char	*original;
	int		i;
	int		x;
	int		y;

	antialiased = malloc(window->width * window->height * window->bpp);
	original = window->data;
	y = 0;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			antialias_pixel(antialiased, original, x, y, window);
			x++;
		}
		y++;
	}
	i = 0;
	while (i < window->width * window->height * window->bpp / 8)
	{
		window->data[i] = antialiased[i];
		i++;
	}
	free(antialiased);
}
