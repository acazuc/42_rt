/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:26:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 15:31:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector		*get_vertex(t_obj_file *file, int i)
{
	t_obj_vertex_list	*lst;
	int					j;

	lst = file->vertex;
	j = 1;
	while (j < i)
		if (!(lst = lst->next))
			return (NULL);
	return (lst->vertex);
}

static void		set_triangle(t_object *triangle
		, t_vector *v1, t_vector *v2, t_vector *v3)
{
	if (!v1 || !v2 || !v3)
		error_quit("Invalid obj file (vertex id)");
	set_triangle_vectors(triangle, v1, v2, v3);
}

void	obj_add(t_env *env, t_obj *obj)
{
	t_obj_file			*file;
	t_obj_face_list		*lst;
	t_object			*t;

	if (!obj->file)
		return ;
	file = obj_parse_file(obj->file);
	obj_add_rotate(obj, file);
	obj_add_moves(obj, file);
	lst = file->faces;
	while (lst)
	{
		t = create_triangle();
		set_triangle(t, get_vertex(file, lst->v1), get_vertex(file, lst->v2)
				, get_vertex(file, lst->v3));
		object_add(env, t);
		lst = lst->next;
	}
}
