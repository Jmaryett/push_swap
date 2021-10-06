#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "./libft/libft.h"

# include <limits.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

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
	int				number;
	int				index;
	int				markup_head;
	int				keep;
	int				best_to_move_to_a;
	int				moves;
	struct s_stack	*next;
}				t_stack;

//struct for finding best_elem

typedef struct s_best_elem
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*elem_mv;
	int		min;
}				t_best;

//commands

void	swap(t_stack **stack);
void	rotate(t_stack **stack);
t_stack	*push(t_stack **stack_1, t_stack **stack_2);
void	reverse_rotate(t_stack **stack);

//validating

int		error_case(char *s);
t_stack	*parse_and_validate_input(int ac, char **av);
int	add_arguments_to_stack(t_stack **data_stack, char **arguments);
int	validate_arguments(char **arguments);

void	indexation(t_stack **begin);

//additional functions

void	free_array_of_strings(char **t);
int		lstsize(t_stack *begin);
void	lstadd_back(t_stack **begin_list_a, t_stack *new);
t_stack	*get_lst_new_elem(int n);
void	free_memory_lst(t_stack *new);

//finding markup_head

void	init_m_h(t_stack **stack);
void	init_keep_true_false(t_stack **stack_a);
void	markups(t_stack **stack_a, t_count *c);
int		init_keep_in_a(t_stack **stack_a, t_stack *m_h, t_count *count);

//putting from stack_a to stack_b

t_stack	*from_a_to_b(t_stack **stack_a, t_stack **stack_b, t_count *count);
void	sort_a(t_stack **stack_a);
void	init_moves(t_stack **a, t_stack **b);

//below im starting to push from b to a
//if there are smaller index for elems in b

void	from_b_to_a(t_stack **stack_b, t_stack **stack_a);
int		init_first_best_elem(t_best *best, t_stack **b, t_stack **a);
t_stack	*needed_elem_in_a(t_stack **a, t_stack **b);

void	init_mv_in_a(t_stack **st);
void	init_mv_in_b(t_stack **st);
void	even_init_mv_in_b(t_stack **st);
void	even_init_mv_in_a(t_stack **st);

t_stack	*best_elem_in_b(t_stack *tmp_b, t_stack *tmp_a, t_stack **a, int min);

void	rotating_b_and_a_with_small_ind(t_stack **b, t_stack **a, t_best *best);

int	where_is_b(int len, t_stack **b, t_best *best);
int	where_is_a(int len, t_stack **a, t_best *best);

void	push_b_up(t_stack **b/* , t_stack **a */);
void	push_b_down(t_stack **b/* , t_stack **a */);
void	a_up_b_down_small(t_stack **a, t_stack **b, t_best *best);
void	a_down_b_up_small(t_stack **a, t_stack **b, t_best *best);

void	push_b_to_a(t_stack **a, t_stack **b);

void	do_rrr_small(t_stack **a, t_stack **b, t_best *best);
void	do_rr_small(t_stack **a, t_stack **b, t_best *best);

//if only big index left

void	only_big_index_left(t_stack **a, t_stack **b, t_best *best);

void	reinit_mv_in_a(t_stack **st);

int		best_bigger_index_to_move(t_stack **a, t_stack **b, t_best *best);
int		init_first_best_bigger_ind_to_move(t_best *best, t_stack **b, t_stack **a);
t_stack	*smaller_index_for_b(t_stack **a, t_stack **b);

void	do_rrr(t_stack **a, t_stack **b, t_best *best);
void	do_rr(t_stack **a, t_stack **b, t_best *best);
void	a_to_down_b_up(t_stack **a, t_stack **b, t_best *best);
void	a_to_up_b_down(t_stack **a, t_stack **b, t_best *best);

#	endif