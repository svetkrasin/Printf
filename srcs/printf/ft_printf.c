/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:00:07 by svet              #+#    #+#             */
/*   Updated: 2020/08/18 15:58:45 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "unistd.h"

int	ft_printf(const char *restrict format, ...)
{
	va_list arg;
	int		done;
	char	*fstr;

	va_start(arg, format);
	done = ft_vasprintf(&fstr, format, arg);
	va_end(arg);
	if (done > -1)
	{
		write(STDOUT_FILENO, fstr, done);
		free(fstr);
		return (done);
	}
	return (-1);
}

// int						main(void)
// {
// 	ft_printf("test %3$0*1$.*2$s %4$-*1$.*2$d ends", 20, 7, "язь", 5);
// 	return (0);
// }
