/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 09:31:09 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 10:22:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECTANGLE_H
# define RECTANGLE_H

typedef struct		s_rectangle
{
	t_vector		*p1;
	t_vector		*p2;
	t_vector		*p3;
	t_vector		*p4;
	double			reflection;
	double			transparency;
	double			brilliance;
	int				color;
}					t_rectangle;

#endif
