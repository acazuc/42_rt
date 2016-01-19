/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:36:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/19 16:25:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			draw(t_env *env)
{
	pthread_t	threads[THREAD_NUMBER];
	t_worker	workers[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		workers[i].env = env;
		workers[i].start = env->window->width * env->window->height
			/ (double)THREAD_NUMBER * i;
		workers[i].end = env->window->width * env->window->height
			/ (double)THREAD_NUMBER * (i + 1);
		pthread_create(&(threads[i]), NULL, worker_run, &(workers[i]));
		i++;
	}
	i = 0;
	while (i < THREAD_NUMBER)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
