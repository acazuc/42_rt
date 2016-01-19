/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 08:21:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/19 15:48:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "object_type.h"
# include "vector.h"

typedef struct		s_object
{
	t_object_type	type;
	t_vector		*position;
	t_vector		*rotation;
	double			dimensions[3];
	double			transparency;
	double			reflection;
	int				color;
}					t_object;

#endif
