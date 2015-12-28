/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:32:12 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 14:44:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	error_quit(char *error_message)
{
	ft_putstr_fd(CONSOLE_LIGHT_RED, 2);
	ft_putstr_fd("An error happened: ", 2);
	ft_putendl_fd(error_message, 2);
	ft_putstr_fd(CONSOLE_DEFAULT, 2);
	exit(-1);
}
