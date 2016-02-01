/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_add_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:26:44 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 15:32:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	obj_add_moves(t_obj *obj, t_obj_file *file)
{
	t_obj_vertex_list	*lst;

	lst = file->vertex;
	while (lst)
	{
		lst->vertex->x += obj->position->x;
		lst->vertex->y += obj->position->y;
		lst->vertex->z += obj->position->z;
		lst = lst->next;
	}
}
