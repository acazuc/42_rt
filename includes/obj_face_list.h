/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_face_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:29:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 13:33:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_FACE_LIST_H
# define OBJ_FACE_LIST_H

typedef struct s_obj_face_list	t_obj_face_list;

struct				s_obj_face_list
{
	t_vector		*v1;
	t_vector		*v2;
	t_vector		*v3;
};

#endif
