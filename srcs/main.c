/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:59:40 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/11 16:14:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

int		main(void)
{
	t_env		*env;

	if (!(env = malloc(sizeof(*env))))
		error_quit("Failed to malloc env");
	env_init(env);
	window_init(env);
	env->fov = 66;
	t_object *sphere;
	sphere = create_sphere();
	sphere->color = 0xFF0000;
	sphere->dimensions[0] = 1;
	sphere->position->z = 10;
	object_add(env, sphere);
	draw(env);
	ft_putstr(CONSOLE_GREEN);
	ft_putendl("Finished drawing");
	mlx_expose_hook(env->window->mlx_window, &expose_listener, env);
	mlx_key_hook(env->window->mlx_window, &key_listener, env);
	mlx_loop(env->window->mlx);
	error_quit("Bullshit");
}
