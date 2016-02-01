/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_vertex_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:34:02 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 14:08:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_VERTEX_LIST_H
# define OBJ_VERTEX_LIST_H

typedef struct s_obj_vertex_list	t_obj_vertex_list;

struct					s_obj_vertex_list
{
	t_vector			*vertex;
	t_obj_vertex_list	*next;
};

#endif
