/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:05:07 by rmiah             #+#    #+#             */
/*   Updated: 2024/05/28 14:05:08 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexaupper(unsigned int nb)
{
	char	*str;
	int		compteur;

	compteur = 0;
	str = "0123456789ABCDEF";
	if (nb >= 16)
		compteur = compteur + ft_hexaupper(nb / 16);
	compteur = compteur + ft_putchar(str[nb % 16]);
	return (compteur);
}
