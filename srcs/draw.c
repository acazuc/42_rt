/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:36:58 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/11 15:55:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

void	draw(t_env *env)
{
	t_point		*coord;
	t_point		*fov;
	double		angle_x;
	double		angle_y;

	coord = point_create();
	fov = point_create();
	fov->x = env->fov / 2. / 180. * M_PI;
	fov->y = fov->x / env->window->width * env->window->height;
	coord->y = 0;
	while (coord->y < env->window->height)
	{
		coord->x = 0;
		while (coord->x < env->window->width)
		{
			angle_y = (double)(coord->x - env->window->width / 2.)
				/ (double)(env->window->width / 2.) * fov->x;
			angle_x = (double)(coord->y - env->window->height / 2.)
				/ (double)(env->window->height / 2.) * fov->y;
			pixel_put(env, coord->x, coord->y, trace(env, angle_x, angle_y));
			coord->x++;
		}
		coord->y++;
	}
}
