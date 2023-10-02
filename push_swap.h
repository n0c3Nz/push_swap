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
int	*arrayzer(int size, char **argv);

/*Stack Funcs*/
int	get_min_pos(t_stack *stack);
int	get_max_pos(t_stack *stack);
t_stack    *create_stack_a(int size, int *arr, t_stack *stack);
void	ft_stackadd_node(t_stack **stack, t_stack *new);
t_stack	*ft_stacknew(int content);
int peek(t_stack *stack);
int isEmpty(t_stack *stack);
int	pop(t_stack **stack);

/*FUNCIONES DE DEBUG*/
void	ft_print_stack(t_stack *stack);
void    ft_print_stack_horizontal(t_stack *stack_a, t_stack *stack_b);
/*------------------Genericas de ordenamiento---------------------*/
void	moves(t_stack **stack_a, t_stack **stack_b, t_size *size);
int	is_sorted(t_stack *stack);//Sirve para todas
/*Ordenar 3 números*/
void	sort3(t_stack **stack_a, int size);
void find_cases_3(int min, int max, t_stack **stack_a);
/*Ordenar 5 números*/
void	sort5(t_stack **stack_a, t_stack **stack_b, t_size *size);
void find_cases_5(t_stack **stack_a, t_stack **stack_b, t_size *size);
/*Ordenar 100 números*/
//void	sort100(t_stack **stack_a, t_stack **stack_b, t_size *size);
void	radix(t_stack **stack_a, t_stack **stack_b, t_size *size);
int    max_bits(t_size *size);
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