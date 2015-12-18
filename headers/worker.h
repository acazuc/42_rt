/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 10:56:19 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/18 10:57:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WORKER_H
# define FT_WORKER_H

# include "env.h"

typedef struct	s_worker
{
	t_env		*env;
	int			start;
	int			end;
}				t_worker;

#endif
