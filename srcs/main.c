/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:59:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/04 11:23:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
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

void	a(int **m, int a, int v1, int v2, int c)
{
	m[a] = malloc(sizeof(**m) * 3);
	m[a][0] = v1;
	m[a][1] = v2;
	m[a][2] = c;
}

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
	env->fov = 90;
	/*env->rotation->x = -45;
	env->rotation->y = 0;
	env->position->x = 0;
	env->position->y = 200;
	env->position->z = -200;
	*///add_objects(env);
	/*object = create_sphere();
	object->color = 0xFFFFFF;
	object->position->y = -1000002;
	object->dimensions[0] = 1000000;
	object_add(env, object);
	*//*double mdr = 50;
	double z = -mdr;
	while (z <= mdr)
	{
		double x = -mdr;
		while (x <= mdr)
		{
			object = create_sphere();
			object->color = WHITE;
			object->dimensions[0] = 3;
			object->position->y = 1;
			object->position->z = z;
			object->position->x = x;
			object->reflection = 0;
			object_add(env, object);
			x += 10;
		}
		z += 10;
	}*/



	/*double haha = 177;
	int **m;
	m = malloc(sizeof(*m) * haha);
	a(m, 0 , 5 , 0, BLACK);
	a(m, 1 , 6 , 0, BLACK);
	a(m, 2 , 7 , 0, BLACK);
	a(m, 3 , 8 , 0, BLACK);
	a(m, 4 , 9 , 0, BLACK);

	a(m, 5 , 3 , 1, BLACK);
	a(m, 6 , 4 , 1, BLACK);
	a(m, 7 , 5 , 1, YELLOW);
	a(m, 8 , 6 , 1, YELLOW);
	a(m, 9 , 7 , 1, YELLOW);
	a(m, 10, 8 , 1, YELLOW);
	a(m, 11, 9 , 1, YELLOW);
	a(m, 12, 10, 1, BLACK);
	a(m, 13, 11, 1, BLACK);

	a(m, 14, 2 , 2, BLACK);
	a(m, 15, 3 , 2, YELLOW);
	a(m, 16, 4 , 2, YELLOW);
	a(m, 17, 5 , 2, YELLOW);
	a(m, 18, 6 , 2, YELLOW);
	a(m, 19, 7 , 2, YELLOW);
	a(m, 20, 8 , 2, YELLOW);
	a(m, 21, 9 , 2, YELLOW);
	a(m, 22, 10, 2, YELLOW);
	a(m, 23, 11, 2, YELLOW);
	a(m, 24, 12, 2, BLACK);

	a(m, 25, 1 , 3, BLACK);
	a(m, 26, 2 , 3, YELLOW);
	a(m, 27, 3 , 3, YELLOW);
	a(m, 28, 4 , 3, BLACK);
	a(m, 29, 5 , 3, BLACK);
	a(m, 30, 6 , 3, YELLOW);
	a(m, 31, 7 , 3, YELLOW);
	a(m, 32, 8 , 3, YELLOW);
	a(m, 33, 9 , 3, BLACK);
	a(m, 34, 10, 3, BLACK);
	a(m, 35, 11, 3, YELLOW);
	a(m, 36, 12, 3, YELLOW);
	a(m, 37, 13, 3, BLACK);

	a(m, 38, 1 , 4, BLACK);
	a(m, 39, 2 , 4, YELLOW);
	a(m, 40, 3 , 4, BLACK);
	a(m, 41, 4 , 4, YELLOW);
	a(m, 42, 5 , 4, YELLOW);
	a(m, 43, 6 , 4, YELLOW);
	a(m, 44, 7 , 4, YELLOW);
	a(m, 45, 8 , 4, YELLOW);
	a(m, 46, 9 , 4, YELLOW);
	a(m, 47, 10, 4, YELLOW);
	a(m, 48, 11, 4, BLACK);
	a(m, 49, 12, 4, YELLOW);
	a(m, 50, 13, 4, BLACK);

	a(m, 51, 0 , 5, BLACK);
	a(m, 52, 1 , 5, YELLOW);
	a(m, 53, 2 , 5, BLACK);
	a(m, 54, 3 , 5, YELLOW);
	a(m, 55, 4 , 5, BLACK);
	a(m, 56, 5 , 5, BLACK);
	a(m, 57, 6 , 5, YELLOW);
	a(m, 58, 7 , 5, YELLOW);
	a(m, 59, 8 , 5, YELLOW);
	a(m, 60, 9 , 5, BLACK);
	a(m, 61, 10, 5, BLACK);
	a(m, 62, 11, 5, YELLOW);
	a(m, 63, 12, 5, BLACK);
	a(m, 64, 13, 5, YELLOW);
	a(m, 65, 14, 5, BLACK);

	a(m, 66, 0 , 6, BLACK);
	a(m, 67, 1 , 6, YELLOW);
	a(m, 68, 2 , 6, BLACK);
	a(m, 69, 3 , 6, YELLOW);
	a(m, 70, 4 , 6, BLACK);
	a(m, 71, 5 , 6, BLACK);
	a(m, 72, 6 , 6, YELLOW);
	a(m, 73, 7 , 6, YELLOW);
	a(m, 74, 8 , 6, YELLOW);
	a(m, 75, 9 , 6, BLACK);
	a(m, 76, 10, 6, BLACK);
	a(m, 77, 11, 6, YELLOW);
	a(m, 78, 12, 6, BLACK);
	a(m, 79, 13, 6, YELLOW);
	a(m, 80, 14, 6, BLACK);

	a(m, 81, 0 , 7, BLACK);
	a(m, 82, 1 , 7, YELLOW);
	a(m, 83, 2 , 7, YELLOW);
	a(m, 84, 3 , 7, YELLOW);
	a(m, 85, 4 , 7, YELLOW);
	a(m, 86, 5 , 7, YELLOW);
	a(m, 87, 6 , 7, YELLOW);
	a(m, 88, 7 , 7, YELLOW);
	a(m, 89, 8 , 7, YELLOW);
	a(m, 90, 9 , 7, YELLOW);
	a(m, 91, 10, 7, YELLOW);
	a(m, 92, 11, 7, YELLOW);
	a(m, 93, 12, 7, YELLOW);
	a(m, 94, 13, 7, YELLOW);
	a(m, 95, 14, 7, BLACK);

	a(m, 96 , 0 , 8, BLACK);
	a(m, 97 , 1 , 8, YELLOW);
	a(m, 98 , 2 , 8, YELLOW);
	a(m, 99 , 3 , 8, YELLOW);
	a(m, 100, 4 , 8, YELLOW);
	a(m, 101, 5 , 8, YELLOW);
	a(m, 102, 6 , 8, YELLOW);
	a(m, 103, 7 , 8, YELLOW);
	a(m, 104, 8 , 8, YELLOW);
	a(m, 105, 9 , 8, YELLOW);
	a(m, 106, 10, 8, YELLOW);
	a(m, 107, 11, 8, YELLOW);
	a(m, 108, 12, 8, YELLOW);
	a(m, 109, 13, 8, YELLOW);
	a(m, 110, 14, 8, BLACK);

	a(m, 111, 0 , 9, BLACK);
	a(m, 112, 1 , 9, YELLOW);
	a(m, 113, 2 , 9, YELLOW);
	a(m, 114, 3 , 9, YELLOW);
	a(m, 115, 4 , 9, YELLOW);
	a(m, 116, 5 , 9, BLACK);
	a(m, 117, 6 , 9, YELLOW);
	a(m, 118, 7 , 9, YELLOW);
	a(m, 119, 8 , 9, YELLOW);
	a(m, 120, 9 , 9, BLACK);
	a(m, 121, 10, 9, YELLOW);
	a(m, 122, 11, 9, YELLOW);
	a(m, 123, 12, 9, YELLOW);
	a(m, 124, 13, 9, YELLOW);
	a(m, 125, 14, 9, BLACK);

	a(m, 126, 1 , 10, BLACK);
	a(m, 127, 2 , 10, YELLOW);
	a(m, 128, 3 , 10, YELLOW);
	a(m, 129, 4 , 10, YELLOW);
	a(m, 130, 5 , 10, YELLOW);
	a(m, 131, 6 , 10, BLACK);
	a(m, 132, 7 , 10, BLACK);
	a(m, 133, 8 , 10, BLACK);
	a(m, 134, 9 , 10, YELLOW);
	a(m, 135, 10, 10, YELLOW);
	a(m, 136, 11, 10, YELLOW);
	a(m, 137, 12, 10, YELLOW);
	a(m, 138, 13, 10, BLACK);

	a(m, 139, 1 , 11, BLACK);
	a(m, 140, 2 , 11, YELLOW);
	a(m, 141, 3 , 11, YELLOW);
	a(m, 142, 4 , 11, YELLOW);
	a(m, 143, 5 , 11, YELLOW);
	a(m, 144, 6 , 11, YELLOW);
	a(m, 145, 7 , 11, YELLOW);
	a(m, 146, 8 , 11, YELLOW);
	a(m, 147, 9 , 11, YELLOW);
	a(m, 148, 10, 11, YELLOW);
	a(m, 149, 11, 11, YELLOW);
	a(m, 150, 12, 11, YELLOW);
	a(m, 151, 13, 11, BLACK);

	a(m, 152, 2 , 12, BLACK);
	a(m, 153, 3 , 12, YELLOW);
	a(m, 154, 4 , 12, YELLOW);
	a(m, 155, 5 , 12, YELLOW);
	a(m, 156, 6 , 12, YELLOW);
	a(m, 157, 7 , 12, YELLOW);
	a(m, 158, 8 , 12, YELLOW);
	a(m, 159, 9 , 12, YELLOW);
	a(m, 160, 10, 12, YELLOW);
	a(m, 161, 11, 12, YELLOW);
	a(m, 162, 12, 12, BLACK);

	a(m, 163, 3 , 13, BLACK);
	a(m, 164, 4 , 13, BLACK);
	a(m, 165, 5 , 13, YELLOW);
	a(m, 166, 6 , 13, YELLOW);
	a(m, 167, 7 , 13, YELLOW);
	a(m, 168, 8 , 13, YELLOW);
	a(m, 169, 9 , 13, YELLOW);
	a(m, 170, 10, 13, BLACK);
	a(m, 171, 11, 13, BLACK);

	a(m, 172, 5 , 14, BLACK);
	a(m, 173, 6 , 14, BLACK);
	a(m, 174, 7 , 14, BLACK);
	a(m, 175, 8 , 14, BLACK);
	a(m, 176, 9 , 14, BLACK);

	int eumdeureuh = 0;
	while (eumdeureuh < haha)
	{
		object = create_sphere();
		object->color = m[eumdeureuh][2];
		object->dimensions[0] = 3;
		object->position->y = 1;
		object->position->x = -6.5 + m[eumdeureuh][0];
		object->position->z = 7 - m[eumdeureuh][1];
		object_add(env, object);
		eumdeureuh++;
	}
	light = light_create();
	light->position->x = 0;
	light->position->y = 8;
	light->position->z = 0;
	light->luminosity = 1;
	light_add(env, light);
*/
	
	
	/**
	 * Such Wow
	 */
	/*env->position->y = 10;
	env->position->z = -10;
	env->rotation->x = -45;
	object = create_sphere();
	object->color = WHITE;
	object->position->y = -10000.4;
	object->dimensions[0] = -10000;
	object_add(env, object);
	double mdr = 5;
	double x = -mdr;
	while (x <= mdr)
	{
		double z = -mdr;
		while (z <= mdr)
		{
			object = create_sphere();
			object->color = WHITE;
			object->position->y = 0;
			object->position->x = x;
			object->position->z = z;
			object->dimensions[0] = .4;
			object_add(env, object);
			z++;
		}
		x++;
	}
	double mdrd = 10;
	double xd = -mdrd;
	while (xd <= mdrd)
	{
		double yd = -mdrd;
		while (yd <= mdrd)
		{
			light = light_create();
			light->luminosity = .075;
			light->position->x = xd;
			light->position->y = 2;
			light->position->z = yd;
			light->mask->red = (xd + mdrd) / (mdrd * 2.);
			light->mask->blue = (xd + mdrd) / (mdrd * 2.);
			light_add(env, light);
			yd += 5;
		}
		xd += 5;
	}*/
	
	/*
	 * START MDLOUL
	 *//*
	env->position->y = 100;
env->ambient_light = .5;
	env->position->z = -100;
	env->rotation->x = 45;
	object = create_sphere();
	object->position->y = -10002;
	object->dimensions[0] = 10000;
	object_add(env, object);
	double haha = 60;
	int **m;
	int c = WHITE;
	m = malloc(sizeof(*m) * haha);
	a(m, 0 , 0 , 0, c);
	a(m, 1 , 0 , 1, c);
	a(m, 2 , 0 , 2, c);
	a(m, 3 , 0 , 3, c);
	a(m, 4 , 0 , 4, c);
	a(m, 5 , 1 , 1, c);
	a(m, 6 , 2 , 2, c);
	a(m, 7 , 3 , 1, c);
	a(m, 8 , 4 , 0, c);
	a(m, 9 , 4 , 1, c);
	a(m, 10, 4 , 2, c);
	a(m, 11, 4 , 3, c);
	a(m, 12, 4 , 4, c);
	a(m, 13, 6 , 0, c);
	a(m, 14, 6 , 1, c);
	a(m, 15, 6 , 2, c);
	a(m, 16, 6 , 3, c);
	a(m, 17, 6 , 4, c);
	a(m, 18, 7 , 0, c);
	a(m, 19, 7 , 4, c);
	a(m, 20, 8 , 1, c);
	a(m, 21, 8 , 2, c);
	a(m, 22, 8 , 3, c);
	a(m, 23, 10, 0, c);
	a(m, 24, 10, 1, c);
	a(m, 25, 10, 2, c);
	a(m, 26, 10, 3, c);
	a(m, 27, 10, 4, c);
	a(m, 28, 11, 4, c);
	a(m, 29, 12, 4, c);
	a(m, 30, 14, 0, c);
	a(m, 31, 14, 1, c);
	a(m, 32, 14, 2, c);
	a(m, 33, 14, 3, c);
	a(m, 34, 14, 4, c);
	a(m, 35, 15, 0, c);
	a(m, 36, 15, 4, c);
	a(m, 37, 16, 0, c);
	a(m, 38, 16, 1, c);
	a(m, 39, 16, 2, c);
	a(m, 40, 16, 3, c);
	a(m, 41, 16, 4, c);
	a(m, 42, 18, 0, c);
	a(m, 43, 18, 1, c);
	a(m, 44, 18, 2, c);
	a(m, 45, 18, 3, c);
	a(m, 46, 18, 4, c);
	a(m, 47, 19, 4, c);
	a(m, 48, 20, 0, c);
	a(m, 49, 20, 1, c);
	a(m, 50, 20, 2, c);
	a(m, 51, 20, 3, c);
	a(m, 52, 20, 4, c);
	a(m, 53, 22, 0, c);
	a(m, 54, 22, 1, c);
	a(m, 55, 22, 2, c);
	a(m, 56, 22, 3, c);
	a(m, 57, 22, 4, c);
	a(m, 58, 23, 4, c);
	a(m, 59, 24, 4, c);
	int eumdeureuh = 0;
	while (eumdeureuh < haha)
	{
		object = create_sphere();
		object->color = WHITE;
		object->dimensions[0] = .4;
		object->position->y = -1.6;
		object->position->x = -12.5 + m[eumdeureuh][0];
		object->position->z = 3 - m[eumdeureuh][1];
		object->reflection = 1;
		object_add(env, object);
		eumdeureuh++;
	}
	double loul = 20;
	double xd = -loul;
	while (xd <= loul)
	{
		double zd = -loul;
		while (zd <= loul)
		{
			light = light_create();
			light->position->x = xd;
			light->position->y = -1;
			light->position->z = zd;
			light->mask->green = (xd + loul) / (loul * 2.);
			light->mask->blue = (zd + loul) / (loul * 2.);
			//light->mask->blue = (xd + zd + loul + loul) / (loul * 4.);
			light->luminosity = 1;
			light_add(env, light);
			zd += 10;
		}
		xd += 10;
	}*/
	/*
	 * END MDLOUL
	 */

	/*object = create_sphere();
	object->color = WHITE;
	object->position->y = 40;
	object->position->z = 50;
	object->dimensions[0] = 20;
	object->reflection = 1;
	object_add(env, object);
	light = light_create();
	light->position->x = -30;
	light->position->y = 5;
	light->luminosity = 5;
	light->mask->blue = 0;
	light->mask->green = 0;
	light_add(env, light);
	light = light_create();
	light->position->x = 0;
	light->position->y = 5;
	light->luminosity = 5;
	light->mask->red = 0;
	light->mask->blue = 0;
	light_add(env, light);
	light = light_create();
	light->position->x = 30;
	light->position->y = 5;
	light->luminosity = 5;
	light->mask->green = 0;
	light->mask->red = 0;
	light_add(env, light);*/
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
	light_add(env, light);
	*/

	/**
	 * ROTATIONS
	 */
	light = light_create();
	light->position->x = 0;
	light->position->z = 18;
	light->position->y = 0;
	light->luminosity = 1;
	light_add(env, light);
	object = create_cylinder();
	object->color = 0xFFFFFF;
	object->position->z = 20;
	object->position->y = 2;
	object->position->x = 100;
	object->rotation->z = 90;
	object->reflection = 1;
	object->dimensions[0] = 1;
	object_add(env, object);
	object = create_sphere();
	object->position->y = -100002;
	object->color = WHITE;
	object->dimensions[0] = 100000;
	object_add(env, object);
	ft_putstr(CONSOLE_GREEN);
	ft_putendl("Started drawing");
	env->ambient_light = 0;
	draw(env);
	ft_putstr(CONSOLE_GREEN);
	ft_putendl("Finished drawing");
	mlx_expose_hook(env->window->mlx_window, &expose_listener, env);
	mlx_key_hook(env->window->mlx_window, &key_listener, env);
	mlx_loop(env->window->mlx);
	return (0);
}
