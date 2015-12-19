/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 08:17:20 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/19 08:37:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int		key_listener(int key, void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (key == 53)
	{
		ft_putstr(CONSOLE_GREEN);
		ft_putendl("Exit successful");
		exit(1);
	}
	return (0);
}
