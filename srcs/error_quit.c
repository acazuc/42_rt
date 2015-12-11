/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:32:12 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/10 14:28:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

void	error_quit(char *error_message)
{
	ft_putstr(CONSOLE_LIGHT_RED);
	ft_putstr("An error happened: ");
	ft_putendl(error_message);
	ft_putstr(CONSOLE_DEFAULT);
	exit(-1);
}
