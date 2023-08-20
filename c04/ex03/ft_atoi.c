/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cponsson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:46:53 by cponsson          #+#    #+#             */
/*   Updated: 2023/08/18 10:13:19 by cponsson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	nbr;
	int	par;

	par = 0;
	nbr = 0;
	while (*str >= 9 && *str <= 13 || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			par ++;
		++str;
	}
	while (*str >= 48 && *str <= 57)
	{
		nbr *= 10;
		nbr += *str - 48;
		++str;
	}
	if (par % 2)
		return (-nbr);
	return (nbr);
}
int	main()
{
	char *s = "      ---++--1234ab567";
	printf("%d", ft_atoi(s));
}
