/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:59:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 10:54:06 by acazuc           ###   ########.fr       */
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
	window_init(env);
	start = epoch_millis();
	draw(env);
	end = epoch_millis();
	put_time(start, end, "Finished drawing");
	mlx_expose_hook(env->window->mlx_window, &expose_listener, env);
	mlx_key_hook(env->window->mlx_window, &key_listener, env);
	mlx_loop(env->window->mlx);
	return (0);
}
