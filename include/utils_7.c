/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:59:50 by guortun-          #+#    #+#             */
/*   Updated: 2023/11/27 08:30:12 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*tokenize_numbers(char *argument, t_size *size_a)
{
	int		*numbers;
	char	*token;
	int		count;
	int		number;

	count = 0;
	numbers = NULL;
	token = ft_strtok(argument, " ");
	while (token != NULL)
	{
		number = ft_atoi(token);
		numbers = ft_realloc(numbers, (count + 1) * sizeof(int));
		numbers[count] = number;
		count++;
		token = ft_strtok(NULL, " ");
	}
	reverse_numbers(numbers, count);
	size_a->size_a = count;
	return (numbers);
}

void	reverse_numbers(int *numbers, int count)
{
	int	start;
	int	end;
	int	temp;

	start = 0;
	end = count - 1;
	while (start < end)
	{
		temp = numbers[start];
		numbers[start] = numbers[end];
		numbers[end] = temp;
		start++;
		end--;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (!s[i])
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

void	process_token(char *str, char **lasts)
{
	*str++ = '\0';
	*lasts = str;
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*lasts;
	char		*token;

	if (str == NULL)
		str = lasts;
	if (str == NULL)
		return (NULL);
	str = skip_delimiters(str, delim);
	if (*str == '\0')
	{
		lasts = NULL;
		return (NULL);
	}
	token = str;
	str = find_next_delimiter(str, delim);
	if (*str == '\0')
		lasts = NULL;
	else
		process_token(str, &lasts);
	return (token);
}
