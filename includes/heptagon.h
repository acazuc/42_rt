/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heptagon.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:45:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:47:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEPTAGON_H
# define HEPTAGON_H

typedef struct		s_heptagon
{
	t_vector		*position;
	t_vector		*rotation;
	t_vector		*p1;
	t_vector		*p2;
	t_vector		*p3;
	t_vector		*p4;
	t_vector		*p5;
	t_vector		*p6;
	t_vector		*p7;
	double			reflection;
	double			transparency;
	double			brilliance;
	double			size;
	int				regular;
	int				color;
}					t_heptagon;

#endif
