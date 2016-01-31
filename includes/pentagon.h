/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pentagon.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:54:59 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 14:50:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PENTAGON_H
# define PENTAGON_H

typedef struct	s_pentagon
{
	t_vector	*position;
	t_vector	*rotation;
	t_vector	*p1;
	t_vector	*p2;
	t_vector	*p3;
	t_vector	*p4;
	t_vector	*p5;
	double		brilliance;
	double		reflection;
	double		transparency;
	double		size;
	int			regular;
	int			color;
}				t_pentagon;

#endif
