/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:49:52 by guortun-          #+#    #+#             */
/*   Updated: 2023/11/25 17:21:56 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (s1[c] != '\0' && s2[c] != '\0' && (s1[c] == s2[c]))
	{
		c++;
	}
	if ((s1[c] != s2[c]) && (c < n))
		return ((unsigned char)s1[c] - (unsigned char)s2[c]);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\v'
		|| c == '\t' || c == '\r' || c == '\n' || c == '\f')
		return (c);
	return (0);
}

int	checker(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (str_int_limits(argv[i]))
		{
			write(2, "Errur\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}
