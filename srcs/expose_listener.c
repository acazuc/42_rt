/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_listener.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:14:21 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/11 09:41:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

int		expose_listener(void *param)
{
	t_env *env;

	env = (t_env*)param;
	display(env);
	return (0);
}
