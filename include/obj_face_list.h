/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_face_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:29:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 13:56:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_FACE_LIST_H
# define OBJ_FACE_LIST_H

typedef struct s_obj_face_list	t_obj_face_list;

struct				s_obj_face_list
{
	int				v1;
	int				v2;
	int				v3;
	t_obj_face_list	*next;
};

#endif
