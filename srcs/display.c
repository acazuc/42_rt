/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:48:10 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/11 08:01:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

void	display(t_env *env)
{
	mlx_put_image_to_window(env->window->mlx, env->window->mlx_window
			, env->window->img, 0, 0);
}
