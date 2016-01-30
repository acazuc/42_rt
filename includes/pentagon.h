/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pentagon.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:54:59 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 14:27:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PENTAGON_H
# define PENTAGON_H

typedef struct	s_pentagon
{
	t_vector	*p1;
	t_vector	*p2;
	t_vector	*p3;
	t_vector	*p4;
	t_vector	*p5;
	double		brilliance;
	double		reflection;
	double		transparency;
	int			color;
}				t_pentagon;

#endif
