/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:59:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/08 11:46:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int ac, char **av)
{
	struct timeval	start;
	struct timeval	end;
	t_env			*env;
	
	if (ac != 2)
		error_quit("You must specify the name the scene file");
	if (!(env = malloc(sizeof(*env))))
		error_quit("Failed to malloc env");
	env_init(env);
	gettimeofday(&start, NULL);
	parse_scene(env, av[1]);
	gettimeofday(&end, NULL);
	ft_putstr(CONSOLE_GREEN);
	ft_putstr("Scene parsed in ");
	ft_putnbr((end.tv_usec - start.tv_usec) / 10);
	ft_putendl("ms");
	window_init(env);
	gettimeofday(&end, NULL);
	draw(env);
	gettimeofday(&end, NULL);
	ft_putstr(CONSOLE_GREEN);
	ft_putstr("Finished drawing in ");
	ft_putnbr((int)(end.tv_usec - start.tv_usec) / 10);
	ft_putendl("ms");
	mlx_expose_hook(env->window->mlx_window, &expose_listener, env);
	mlx_key_hook(env->window->mlx_window, &key_listener, env);
	mlx_loop(env->window->mlx);
	return (0);
}
