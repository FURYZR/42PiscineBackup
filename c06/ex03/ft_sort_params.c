/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cponsson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:14:54 by cponsson          #+#    #+#             */
/*   Updated: 2023/08/17 17:43:07 by cponsson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_swap(char **p, char **p1)
{
	char	*tmp;

	tmp = *p;
	*p = *p1;
	*p1 = tmp;
}

int	ft_strcmp(char *s, char *s1)
{
	while (*s == *s1 && *s1 != '\0')
	{
		s++;
		s1++;
	}
	return (*s - *s1);
}

void	ft_sort_params(char *argv[], int args)
{
	int	j;
	int	k;
	int	len;

	len = args;
	while (len - 1)
	{
		j = 0;
		k = 1;
		while (k < len)
		{
			if (ft_strcmp(argv[j], argv[k]) > 0)
				ft_swap(&argv[j], &argv[k]);
			j++;
			k++;
		}
		len --;
	}
}

int	main(int argc, char *argv[])
{
	ft_sort_params(argv + 1, argc - 1);
	while (*(++argv))
		ft_putstr(*argv);
}
