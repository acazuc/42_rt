/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:48:10 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 14:43:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	display(t_env *env)
{
	mlx_put_image_to_window(env->window->mlx, env->window->mlx_window
			, env->window->img, 0, 0);
}
