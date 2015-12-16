/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:59:40 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/16 08:30:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"
/*
void	add_objects(t_env *env)
{
	t_object	*object;
	double		dim;
	double		x;
	double		y;

	dim = 10;
	y = -dim / 2;
	while (y <= dim / 2)
	{
		x = -dim / 2;
		while (x <= dim / 2)
		{
			object = create_sphere();
			int red = 0xFF0000 * ((x + dim / 2.) / dim);
			red = red - red % 0x010000;
			int blue = 0x0000FF * ((y + dim / 2.) / dim);
			blue = blue % 0x000100;
			object->color = red + blue + 0x00FF00;
			object->dimensions[0] = 1;
			object->position->z = dim * 2;
			object->position->x = x;
			object->position->y = y;
			object_add(env, object);
			x++;
		}
		y++;
	}
}*/

int		main(void)
{
	t_object	*object;
	t_light		*light;
	t_env		*env;

	if (!(env = malloc(sizeof(*env))))
		error_quit("Failed to malloc env");
	env_init(env);
	window_init(env);
	env->fov = 45;
	//add_objects(env);
	object = create_sphere();
	object->color = BLUE;
	object->dimensions[0] = 1;
	object->position->y = 0;
	object->position->z = 5;
	object->position->x = 0;
	object_add(env, object);
	object = create_cylinder();
	object->color = 0x606060;
	object->dimensions[0] = .2;
	object->position->y = 0;
	object->position->z = 3;
	object->position->x = .5;
	//object->rotation->z = 90;
	object->rotation->z = 0;
	object_add(env, object);
	light = light_create();
	light->position->z = 0;
	light->position->x = 2;
	light->position->y = 1;
	light->luminosity = .75;
	light_add(env, light);
	light = light_create();
	light->luminosity = .0;
	light_add(env, light);
	draw(env);
	ft_putstr(CONSOLE_GREEN);
	ft_putendl("Finished drawing");
	mlx_expose_hook(env->window->mlx_window, &expose_listener, env);
	mlx_key_hook(env->window->mlx_window, &key_listener, env);
	mlx_loop(env->window->mlx);
	return (0);
}
