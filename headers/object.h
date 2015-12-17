/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 08:21:51 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/17 09:36:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJECT_H
# define FT_OBJECT_H

# include "object_type.h"
# include "vector.h"

typedef struct		s_object
{
	t_object_type	type;
	t_vector		*position;
	t_vector		*rotation;
	double			dimensions[3];
	double			reflection;
	int				color;
}					t_object;

#endif
