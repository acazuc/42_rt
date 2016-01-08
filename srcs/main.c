/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:59:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/08 13:16:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int ac, char **av)
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
	ft_putstr(CONSOLE_GREEN);
	ft_putstr("Scene parsed in ");
	ft_putnbr(end - start);
	ft_putendl("ms");
	window_init(env);
	start = epoch_millis();
	draw(env);
	end = epoch_millis();
	ft_putstr(CONSOLE_GREEN);
	ft_putstr("Finished drawing in ");
	ft_putnbr(end - start);
	ft_putendl("ms");
	mlx_expose_hook(env->window->mlx_window, &expose_listener, env);
	mlx_key_hook(env->window->mlx_window, &key_listener, env);
	mlx_loop(env->window->mlx);
	return (0);
}
