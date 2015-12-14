/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:20:58 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/14 11:32:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

t_collision		*collision_create()
{
	t_collision		*collision;

	if (!(collision = malloc(sizeof(*collision))))
		error_quit("Failed to malloc new collision");
	collision->object = NULL;
	collision->vector = NULL;
	return (collision);
}