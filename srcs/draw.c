/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:36:58 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/18 11:17:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

void			draw(t_env *env)
{
	pthread_t 	threads[8];
	t_worker	workers[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		workers[i].env = env;
		workers[i].start = env->window->width * env->window->height / 8. * i;
		workers[i].end = env->window->width * env->window->height / 8. * (i + 1);
		pthread_create(&(threads[i]), NULL, worker_run, &(workers[i]));
		i++;
	}
	i = 0;
	while (i < 8)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
