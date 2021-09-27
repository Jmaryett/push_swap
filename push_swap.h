#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H

#include "./libft/libft.h"

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

#ifndef INT_MIN
#define INT_MIN -2147483648
#endif

//count elems that should be in stack_b
typedef struct s_count_keep
{
	int	count_false;
	int	index_of_best_m_h;
	int	best_result;
}				t_count;

typedef struct s_count_moves
{
	int	count_moves;
}				t_moves;


typedef struct s_stack
{
	int number;
	int index;
	int markup_head;
	int keep;
	int	best_to_move_to_a;
	int	moves;
	struct s_stack *next;
} t_stack;

//commands
void swap(t_stack **stack);
void rotate(t_stack **stack);
t_stack	*push(t_stack **stack_1, t_stack **stack_2);
void reverse_rotate(t_stack **stack);
//validating
int error_case(char *s);
void check_input(char **array);

void filling_stack_a(char **array, t_stack **begin_list_a);
void check_if_stack_is_sorted(t_stack **begin);
void indexation(t_stack **begin);
//additional functions
int lstsize(t_stack *begin);
void lstadd_back(t_stack **begin_list_a, t_stack *new);
void free_memory_lst(t_stack *new);


//finding markup_head
void	init_m_h(t_stack **stack);
void	init_keep_true_false(t_stack **stack_a);
void	markups(t_stack **stack_a, t_count *c);
int	init_keep_in_a(t_stack **stack_a, t_stack *m_h, t_count *count);
//putting from stack_a to stack_b
t_stack *from_a_to_b(t_stack **stack_a, t_stack **stack_b, t_count *count, t_moves *mv);
void	sort_a(t_stack **stack_a, t_moves *mv);
//below im starting to push from b to a
void from_b_to_a(t_stack **stack_b, t_stack **stack_a, t_moves *mv);
t_stack *needed_elem_in_a(t_stack **a, t_stack **b);

void	rotating_b_and_a(t_stack **b, t_moves *mv, t_stack **a);
void	rotating_a(t_stack **a, t_moves *mv, t_stack *b);

#endif