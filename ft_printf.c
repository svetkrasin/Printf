/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:30:46 by svet              #+#    #+#             */
/*   Updated: 2020/06/26 12:05:49 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		ft_printf(const char *restrict format, ...)
{
	va_list arg;
	int		done;
	char	*fstr;

	va_start(arg, format);
	done = ft_vasprintf(&fstr, format, arg);
	va_end(arg);
	if (done > 0)
		write(STDOUT_FILENO, fstr, done);
	return (done);
}
