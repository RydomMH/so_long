/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:52:28 by rmiah             #+#    #+#             */
/*   Updated: 2024/05/28 12:52:29 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	compteur;

	compteur = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
		compteur++;
	}
	if (nb >= 10)
		compteur = compteur + ft_putnbr(nb / 10);
	compteur = compteur + ft_putchar((nb % 10) + '0');
	return (compteur);
}
