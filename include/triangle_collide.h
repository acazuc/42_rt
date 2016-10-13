/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_collide.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:38:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/29 16:47:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_COLLIDE_H
# define TRIANGLE_COLLIDE_H

typedef struct		s_triangle_collide
{
	t_vector		e1;
	t_vector		e2;
	t_vector		p;
	t_vector		q;
	t_vector		t;
	double			det;
	double			u;
	double			v;
}					t_triangle_collide;

#endif
