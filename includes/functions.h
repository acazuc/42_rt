/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:05:44 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 13:35:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# define ABS(x) ((x) < 0 ? -(x) : (x))
# define DTR(x) ((x) / 180. * M_PI)
# define RTD(x) ((x) * M_PI / 180.)
# define MIN(x, y) ((x) < (y) ? (x) : (y))
# define MAX(x, y) ((x) > (y) ? (x) : (y))

#endif
