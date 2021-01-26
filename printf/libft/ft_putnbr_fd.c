/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:15:15 by ldonita           #+#    #+#             */
/*   Updated: 2020/11/21 12:25:51 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putint_fd(int n, int fd)
{
	ft_putchar_fd(n + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	long pos;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		pos = (long)n * -1;
	}
	else
		pos = (long)n;
	if (pos >= 10)
	{
		ft_putnbr_fd(pos / 10, fd);
		ft_putnbr_fd(pos % 10, fd);
	}
	else
		ft_putint_fd((int)pos, fd);
}
