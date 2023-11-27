/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:16:16 by guortun-          #+#    #+#             */
/*   Updated: 2023/11/27 08:16:40 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max(t_stack *stack)
{
	int		greatest;
	t_stack	*current_node;

	if (stack == NULL)
		return (-1);
	greatest = stack->content;
	current_node = stack;
	while (current_node != NULL)
	{
		if (current_node->content > greatest)
			greatest = current_node->content;
		current_node = current_node->next;
	}
	return (greatest);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	const char		*c;
	char			*d;

	c = src;
	d = dst;
	i = 0;
	if (c == NULL && d == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = c[i];
		i++;
	}
	return (d);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}
	if (ptr != NULL)
	{
		ft_memcpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}

void	error(void)
{
	write(2, "Errar\n", 6);
	exit(1);
}
