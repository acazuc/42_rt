/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:36:58 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/13 10:06:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

static void		set_ray(t_env *env, t_ray *ray, t_point *coord, t_point *fov)
{
	double		angle_x;
	double		angle_y;

	angle_y = (double)(coord->x - env->window->width / 2.)
		/ (double)(env->window->width / 2.) * fov->x;
	angle_x = (double)(coord->y - env->window->height / 2.)
		/ (double)(env->window->height / 2.) * fov->y;
	ray->direction->x = sin(angle_y);
	ray->direction->y = sin(angle_x);
	ray->direction->z = cos(angle_x) * cos(angle_y);
	ray->origin->x = env->position->x;
	ray->origin->y = env->position->y;
	ray->origin->z = env->position->z;
}

void			draw(t_env *env)
{
	t_point		*coord;
	t_point		*fov;
	t_ray		*ray;

	coord = point_create();
	fov = point_create();
	fov->x = DTR(env->fov / 2.);
	fov->y = fov->x / env->window->width * env->window->height;
	ray = ray_create();
	coord->y = 0;
	while (coord->y < env->window->height)
	{
		coord->x = 0;
		while (coord->x < env->window->width)
		{
			set_ray(env, ray, coord, fov);
			pixel_put(env, coord->x, coord->y, trace(env, ray));
			coord->x++;
		}
		coord->y++;
	}
	free(ray);
}
