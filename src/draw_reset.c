/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:24:08 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 14:43:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_reset(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->window->height)
	{
		x = 0;
		while (x < env->window->width)
		{
			pixel_put(env, x, y, 0);
			x++;
		}
		y++;
	}
}
