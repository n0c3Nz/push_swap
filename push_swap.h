#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct s_stack{
	int content;
	struct s_stack *next;
}t_stack;

typedef struct s_size{
	int size_a;
	int size_b;
}t_size;
/*Array Funcs*/
int *arrayzer(int size, char **argv);
int *extract_numbers(t_stack **stack_a);
/*Stack Funcs*/
t_stack    *create_stack_a(int size, int *arr, t_stack *stack);
void	ft_stackadd_node(t_stack **stack, t_stack *new);
t_stack	*ft_stacknew(int content);
int	pop(t_stack **stack);
void	ft_print_stack(t_stack *stack);
void    ft_print_stack_horizontal(t_stack *stack_a, t_stack *stack_b);
int	is_sorted(t_stack *stack);
void	sort_3_items(t_stack **stack_a);
void	sort3(t_stack **stack_a);
void	moves(t_stack **stack_a, t_stack **stack_b, t_size *size);
/*Movimientos de pila*/
void	sa(t_stack **stack_a, int ss);
void	sb(t_stack **stack_b, int ss);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b, t_size *size);
void	pb(t_stack **stack_a, t_stack **stack_b, t_size *size);
void	ra(t_stack **stack_a, int rr);
void	rb(t_stack **stack_b, int rr);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a, int rr);
void	rrb(t_stack **stack_b, int rr);
void	rrr(t_stack **stack_a, t_stack **stack_b);
#endif