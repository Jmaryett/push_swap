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
	int	count_keep;
}				t_count;

typedef struct s_stack
{
	int number;
	int index;
	int markup_head;
	int keep;
	struct s_stack *next;
} t_stack;

t_stack *swap_a(t_stack **stack_a, t_count *count);
void rotate_a(t_stack **stack_a , t_count *count);
t_stack *push_b(t_stack **stack_a, t_stack *b);

int error_case(char *s);
void check_input(char **array);

void filling_stack_a(char **array, t_stack **begin_list_a);
void check_if_stack_is_sorted(t_stack **begin);
void indexation(t_stack **begin);

int lstsize(t_stack *begin);
void lstadd_back(t_stack **begin_list_a, t_stack *new);
void free_memory_lst(t_stack *new);

void init_keep_in_a(t_stack **stack_a, t_stack *m_h, t_count *count);
int check_if_sa_needed(t_stack *stack_a, t_count *count);
void init_markup_head(t_stack **begin);
t_stack *from_a_to_b(t_stack **stack_a, t_stack **stack_b, t_count *count);

t_stack *differ_stacks(t_stack **begin, t_count *count);
t_stack *keep_or_move(t_stack **begin, t_stack *m_h);

#endif