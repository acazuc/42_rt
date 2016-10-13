/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:54:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/21 14:15:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		light_free(t_light *light)
{
	free(light->position);
	free(light->mask);
	free(light);
}

void			free_lights(t_env *env)
{
	t_light_list	*lst;
	t_light_list	*nxt;

	lst = env->lights;
	while (lst)
	{
		light_free(lst->light);
		nxt = lst->next;
		free(lst);
		lst = nxt;
	}
	env->lights = NULL;
}
