/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 10:28:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/06 16:32:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_ray(t_env *env, t_ray *ray, t_point *coord, t_point *fov)
{
	double		angle_x;
	double		angle_y;

	angle_y = (double)(coord->x - env->window->width / 2.)
		/ (double)(env->window->width / 2.) * fov->x
		+ DTR(env->rotation->y);
	angle_x = (double)(coord->y - env->window->height / 2.)
		/ (double)(env->window->height / 2.) * fov->y * -1.
		+ DTR(env->rotation->x);
	ray->direction->x = sin(angle_y);
	ray->direction->y = sin(angle_x);
	ray->direction->z = cos(angle_x) * cos(angle_y);
}

static void		worker_loop(t_worker *worker, t_point *coord, t_ray *ray
		, t_point *fov)
{
	int			color;
	int			i;

	i = worker->start - 1;
	while (++i < worker->end)
	{
		coord->x = i % worker->env->window->width;
		coord->y = i / worker->env->window->width;
		set_ray(worker->env, ray, coord, fov);
		color = get_ray_color(worker->env, ray, NULL, 0);
		pixel_put(worker->env, coord->x, coord->y, color);
	}
}

void			*worker_run(void *data)
{
	t_worker	*worker;
	t_point		*coord;
	t_point		*fov;
	t_ray		*ray;

	worker = (t_worker*)data;
	coord = point_create();
	fov = point_create();
	fov->x = DTR(worker->env->fov / 2.);
	fov->y = fov->x / worker->env->window->width * worker->env->window->height;
	ray = ray_create();
	ray->origin->x = worker->env->position->x;
	ray->origin->y = worker->env->position->y;
	ray->origin->z = worker->env->position->z;
	worker_loop(worker, coord, ray, fov);
	free(fov);
	free(coord);
	ray_free(ray);
	return (NULL);
}
