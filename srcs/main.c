/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:59:40 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/19 17:14:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * OMG OMG OMG OMG OMG OMG OMG OMG OMG OMG GENIUSRIE
 * Suffit de check l'angle du rayon de lumiere par rapport a l'incidence
 * Si il est proche de 90 degres, on met un petit peu de lumiere, ca fera smooth




#include "../headers/rt.h"
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
	env->ambient_light = 0;
	env->fov = 66;
	env->rotation->x = -45;
	env->rotation->y = 0;
	env->position->y = 100;
	env->position->z = -75;
	//add_objects(env);
	object = create_sphere();
	object->color = 0xFFFFFF;
	object->position->y = -1000002;
	object->dimensions[0] = 1000000;
	object_add(env, object);
	double i = -60;
	while (i <= 60)
	{
		object = create_sphere();
		object->color = WHITE;
		object->dimensions[0] = 5;
		object->position->y = 3;
		object->position->z = 20;
		object->position->x = i;
		object->reflection = 0;
		object_add(env, object);
		i+= 10;
	}
	light = light_create();
	light->position->x = -5;
	light->position->y = 1;
	light->luminosity = 1;
	light->mask->blue = 0;
	light->mask->green = 0;
	light_add(env, light);
	light = light_create();
	light->position->x = 0;
	light->position->y = 1;
	light->luminosity = 1;
	light->mask->red = 0;
	light->mask->blue = 0;
	light_add(env, light);
	light = light_create();
	light->position->x = 5;
	light->position->y = 1;
	light->luminosity = 1;
	light->mask->green = 0;
	light->mask->red = 0;
	light_add(env, light);
	/*env->max_recur = 10;
	object = create_sphere();
	object->position->z = 50001;
	object->dimensions[0] = 50000;
	object->reflection = .9;
	object_add(env, object);
	object = create_sphere();
	object->position->x = 50001;
	object->dimensions[0] = 50000;
	object->reflection = .9;
	object_add(env, object);
	object = create_sphere();
	object->position->z = -50001;
	object->dimensions[0] = 50000;
	object->reflection = .9;
	object_add(env, object);
	object = create_sphere();
	object->position->x = -50001;
	object->dimensions[0] = 50000;
	object->reflection = .9;
	object_add(env, object);
	object = create_sphere();
	object->color = 0xFF0000;
	object->position->x = .5;
	object->position->z = .5;
	object->position->y = -.5;
	object->dimensions[0] = .25;
	object_add(env, object);
	light = light_create();
	light->position->x = .5;
	light->position->z = .5;
	light->position->y = .95;
	light->luminosity = .5;
	light_add(env, light);*/
	draw(env);
	ft_putstr(CONSOLE_GREEN);
	ft_putendl("Finished drawing");
	mlx_expose_hook(env->window->mlx_window, &expose_listener, env);
	mlx_key_hook(env->window->mlx_window, &key_listener, env);
	mlx_loop(env->window->mlx);
	return (0);
}
