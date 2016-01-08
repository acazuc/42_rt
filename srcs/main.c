/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:59:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/08 10:02:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(void)
{
	t_object	*object;
	t_light		*light;
	t_env		*env;

	if (!(env = malloc(sizeof(*env))))
		error_quit("Failed to malloc env");
	env_init(env);
	window_init(env);
	
	/**
	 * ROTATIONS
	 */
	parse_scene(env, "scenes/demo.rt");
	/*env->position->z = -20;
	env->position->y = 20;
	env->position->x = 0;
	env->rotation->x = -45;
	env->rotation->y = 0;*/
	light = light_create();
	light->position->x = -5;
	light->position->z = 0;
	light->position->y = 10;
	light->mask->green = 0;
	light->mask->blue = 0;
	light->luminosity = 3;
	/*light_add(env, light);
	light = light_create();
	light->position->x = 0;
	light->position->z = 0;
	light->position->y = 10;
	light->mask->red = 0;
	light->mask->blue = 0;
	light->luminosity = 3;
	light_add(env, light);
	light = light_create();
	light->position->x = 5;
	light->position->z = 0;
	light->position->y = 10;
	light->mask->red = 0;
	light->mask->green = 0;
	light->luminosity = 3;
	light_add(env, light);*/
	/*int i = -20;
	while (i <= -30)
	{
		object = create_sphere();
		object->color = RED;
		object->position->z = 5;
		object->position->x = i;
		object->reflection = 1;
		object->dimensions[0] = .9;
		object_add(env, object);
		object = create_sphere();
		i += 5;
	}
	object->position->y = -10000001;
	object->color = WHITE;
	object->dimensions[0] = 10000000;
	object_add(env, object);*/
	object = NULL;
	ft_putstr(CONSOLE_GREEN);
	ft_putendl("Started drawing");
	draw(env);
	ft_putstr(CONSOLE_GREEN);
	ft_putendl("Finished drawing");
	mlx_expose_hook(env->window->mlx_window, &expose_listener, env);
	mlx_key_hook(env->window->mlx_window, &key_listener, env);
	mlx_loop(env->window->mlx);
	return (0);
}
