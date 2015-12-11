/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 08:21:51 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/11 16:10:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJECT_H
# define FT_OBJECT_H

typedef struct		s_object
{
	t_object_type	type;
	t_vector		*position;
	t_vector		*rotation;
	double			dimensions[3];
	int				color;
}					t_object;

#endif
