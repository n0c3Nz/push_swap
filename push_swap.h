/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:46:26 by guortun-          #+#    #+#             */
/*   Updated: 2023/10/04 07:50:25 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_size
{
	int				size_a;
	int				size_b;
}	t_size;
int			ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isspace(char c);
int			*arrayzer(int size, char **argv);
long long	ft_atoi(const char *str);
int			get_min_pos(t_stack *stack);
int			get_max_pos(t_stack *stack);
void		ft_stackadd_node(t_stack **stack, t_stack *new);
bool		are_all_numbers(char **argv, int argc);
int			str_int_limits(char *str);
int			checker(char **argv);
t_stack		*create_stack_a(int size, int *arr, t_stack *stack);
t_stack		*ft_stacknew(int content);
int			ft_are_all_numbers(char *const argv[], int argc);
int			has_duplicates(int array[], int size);
int			peek(t_stack *stack);
int			is_empty(t_stack *stack);
int			pop(t_stack **stack);
void		ft_print_stack_horizontal(t_stack *stack_a, t_stack *stack_b);
void		moves(t_stack **stack_a, t_stack **stack_b, t_size *size);
int			is_sorted(t_stack *stack);
void		sort3(t_stack **stack_a, int size);
void		find_cases_3(int min, int max, t_stack **stack_a);
void		sort5(t_stack **stack_a, t_stack **stack_b, t_size *size);
void		find_cases_5(t_stack **stack_a, t_stack **stack_b, t_size *size);
void		radix(t_stack **stack_a, t_stack **stack_b, t_size *size);
int			max_bits(t_size *size);
void		sa(t_stack **stack_a, int ss);
void		sb(t_stack **stack_b, int ss);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b, t_size *size);
void		pb(t_stack **stack_a, t_stack **stack_b, t_size *size);
void		ra(t_stack **stack_a, int rr);
void		rb(t_stack **stack_b, int rr);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a, int rr);
void		rrb(t_stack **stack_b, int rr);
void		rrr(t_stack **stack_a, t_stack **stack_b);
#endif