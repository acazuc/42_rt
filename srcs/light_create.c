/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 15:40:01 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/13 16:09:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

t_light		*light_create(void)
{
	t_light		*light;

	if (!(light = malloc(sizeof(*light))))
		error_quit("Failed to malloc new light");
	light->position = vector_create();
	light->luminosity = 0;
	return (light);
}
