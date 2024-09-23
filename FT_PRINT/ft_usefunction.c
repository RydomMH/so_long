/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usefunction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:51:53 by rmiah             #+#    #+#             */
/*   Updated: 2024/05/28 12:51:55 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_usefunction(va_list args, char c)
{
	int	compteur;

	compteur = 0;
	if (c == 's')
		compteur = ft_putstr(va_arg(args, char *));
	else if (c == 'd')
		compteur = ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		compteur = ft_putchar(va_arg(args, int));
	else if (c == '%')
		compteur = write(1, "%", 1);
	else if (c == 'u')
		compteur = ft_putnbr4u(va_arg(args, unsigned int));
	else if (c == 'x')
		compteur = ft_hexalower(va_arg(args, unsigned int));
	else if (c == 'X')
		compteur = ft_hexaupper(va_arg(args, unsigned int));
	else if (c == 'i')
		compteur = ft_putnbr(va_arg(args, int));
	return (compteur);
}
