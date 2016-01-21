/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:22:41 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/21 16:43:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	env_init(t_env *env)
{
	if (!(env->window = malloc(sizeof(*(env->window)))))
		error_quit("Failed to malloc window");
	env->objects = NULL;
	env->lights = NULL;
	env->position = vector_create();
	env->rotation = vector_create();
	env->ambient_light = 0;
	env->max_recur = 10;
	env->fov = 60;
}
