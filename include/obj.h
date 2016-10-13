/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:28:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 16:04:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "obj_vertex_list.h"

typedef struct			s_obj
{
	t_vector			*position;
	t_vector			*rotation;
	double				reflection;
	double				transparency;
	double				brilliance;
	double				size;
	char				*file;
	int					color;
}						t_obj;

#endif
