/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:46:26 by guortun-          #+#    #+#             */
/*   Updated: 2023/11/27 08:24:27 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>//(QUITAR)

# define MAX_INT 2147483647
# define MIN_INT -2147483648

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

void		error(void);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		process_token(char *str, char **lasts);
char		*ft_strchr(const char *s, int c);
char		*ft_strtok(char *str, const char *delim);
char		*skip_delimiters(char *str, const char *delim);
char		*find_next_delimiter(char *str, const char *delim);
void		*ft_realloc(void *ptr, size_t size);
void		reverse_numbers(int *numbers, int count);
int			*tokenize_numbers(char	*argument, t_size *size_a);
int			ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isspace(char c);
int			*arrayzer(int size, char **argv, t_size *size_a);
int			ft_atoi(const char *str);
int			get_min_pos(t_stack *stack);
int			get_max_pos(t_stack *stack);
int			get_max(t_stack *stack);
int			get_max_bits(t_stack **stack_a);
void		ft_stackadd_node(t_stack **stack, t_stack *new);
bool		are_all_numbers(char **argv, int argc);
int			str_int_limits(char *str);
int			checker(char **argv);
t_stack		*create_stack_a(int size, int *arr, t_stack *stack);
t_stack		*ft_stacknew(int content);
int			ft_are_all_numbers(char *const argv[], int argc);
bool		has_duplicates(int *array, int size);
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