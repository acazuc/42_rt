/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:59:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/08 09:47:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	 * ROTATIONS
	 */
	parse_scene(env, "scenes/hap.rt");
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
