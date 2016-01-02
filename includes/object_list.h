/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 08:20:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 13:36:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_LIST_H
# define OBJECT_LIST_H

# include "object.h"

typedef struct				s_object_list
{
	t_object				*object;
	struct s_object_list	*next;
}							t_object_list;

#endif
