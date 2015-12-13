/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:03:58 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/13 16:09:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

void	light_add(t_env *env, t_light *light)
{
	t_light_list	*list;
	t_light_list	*new_item;

	if (!(new_item = malloc(sizeof(*new_item))))
		error_quit("Failed to malloc new light list item");
	new_item->light = light;
	new_item->next = NULL;
	if (!(env->lights))
		env->lights = new_item;
	else
	{
		list = env->lights;
		while (list->next)
			list = list->next;
		list->next = new_item;
	}
}
