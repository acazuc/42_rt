/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_file.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:26:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 13:31:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_FILE_H
# define OBJ_FILE_H

# include "obj_vertex_list.h"
# include "obj_face_list.h"

typedef struct	s_obj_file
{
	t_obj_vertex_list	*vertex;
	t_obj_face_list		*faces;
}				t_obj_file;

#endif
