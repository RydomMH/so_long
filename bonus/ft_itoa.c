/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:22:21 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/19 01:55:18 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_b.h"

void	inivalue_itoa(int *len, int *flag)
{
	*len = 0;
	*flag = 1;
}

void	ininegvalue(int *len, int *flag, int *n)
{
	int	negn;

	negn = *n * -1;
	*len = 1;
	*flag = -1;
	*n = negn;
}

int	ft_intlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		flag;
	int		taille_finale;
	char	*tab;

	inivalue_itoa(&len, &flag);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		ininegvalue(&len, &flag, &n);
	taille_finale = ft_intlen(n) + len;
	tab = malloc(sizeof(char) * (taille_finale + 1));
	if (tab == NULL)
		return (NULL);
	tab[taille_finale] = '\0';
	if (flag == -1)
		tab[0] = '-';
	while (taille_finale - len > 0)
	{
		tab[taille_finale - 1] = n % 10 + '0';
		n /= 10;
		taille_finale--;
	}
	return (tab);
}
