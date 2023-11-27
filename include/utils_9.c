/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:26:35 by guortun-          #+#    #+#             */
/*   Updated: 2023/11/27 10:49:27 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*skip_delimiters(char *str, const char *delim)
{
	int	ch;

	ch = *str;
	while (ch != '\0' && ft_strchr(delim, ch))
	{
		str++;
		ch = *str;
	}
	return (str);
}

char	*find_next_delimiter(char *str, const char *delim)
{
	int	ch;

	ch = *str;
	while (ch != '\0' && !ft_strchr(delim, ch))
	{
		str++;
		ch = *str;
	}
	return (str);
}
