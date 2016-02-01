/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_add_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:24:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 15:28:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	obj_add_rotate(t_obj_file *file, t_obj *obj)
{
	t_obj_vertex_list	*lst;
	
	lst = file->vertex;
	while (lst)
	{
		vector_rotate(lst, obj->rotation);
		lst = lst->next;
	}
}
