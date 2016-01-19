/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:20:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/19 15:33:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_collision		*collision_create(void)
{
	t_collision		*collision;

	//BUGING (THX MALLOC)
	//ft_putchar('a');
	if (!(collision = (t_collision *)malloc(sizeof(t_collision))))
	{
		//ft_putchar('c');
		error_quit("Failed to malloc new collision");
	}
	//ft_putchar('b');
	collision->object = NULL;
	collision->vector = NULL;
	collision->normal = NULL;
	return (collision);
}
