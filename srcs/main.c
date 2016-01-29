/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:59:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/29 16:18:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		put_time(long start, long end, char *msg)
{
	ft_putstr(CONSOLE_GREEN);
	ft_putstr(msg);
	ft_putstr(" in ");
	ft_putnbr(end - start);
	ft_putendl("ms");
	ft_putstr(CONSOLE_WHITE);
}

int				main(int ac, char **av)
{
	long			start;
	long			end;
	t_env			*env;

	if (ac != 2)
		error_quit("You must specify the name the scene file");
	if (!(env = malloc(sizeof(*env))))
		error_quit("Failed to malloc env");
	env_init(env);
	start = epoch_millis();
	parse_scene(env, av[1]);
	end = epoch_millis();
	put_time(start, end, "Scene parsed");
	t_object *triangle;
	triangle = create_triangle();
	triangle->position->x = -5;
	triangle->position->y = -5;
	triangle->position->z = 10;
	triangle->rotation->x = 0;
	triangle->rotation->y = 5;
	triangle->rotation->z = 10;
	triangle->dimensions[0] = 5;
	triangle->dimensions[1] = -5;
	triangle->dimensions[2] = 10;
	triangle->color = RED;
	object_add(env, triangle);
	window_init(env);
	start = epoch_millis();
	draw(env);
	end = epoch_millis();
	put_time(start, end, "Finished drawing");
	free_objects(env);
	free_lights(env);
	mlx_expose_hook(env->window->mlx_window, &expose_listener, env);
	mlx_key_hook(env->window->mlx_window, &key_listener, env);
	mlx_loop(env->window->mlx);
	return (0);
}
