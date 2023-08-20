/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cponsson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:32:06 by cponsson          #+#    #+#             */
/*   Updated: 2023/08/20 12:52:32 by cponsson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_err(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if(base[i] == '+' || base[i] == '-')
			return(0);
		if(base[i] < 32 || base[i] > 126)
			return(0);
		while (base[j])
		{
			if (base[j] == base[i])
			{
				return(0);
			}
		} 	j++;
	}	i++;
	return(1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int    len;
	int    error;
	long    nb;

	error = check_err(base);
	len = ft_strlen(base);
	nb = nbr;
	if (error == 1)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		if (nb < len)
			ft_putchar(base[nb]);
		if (nb >= len)
		{
			ft_putnbr_base(nb / len, base);
			ft_putnbr_base(nb % len, base);
		}
	}
}

int        main(void)
{
    ft_putnbr_base(-7, "01");
}
