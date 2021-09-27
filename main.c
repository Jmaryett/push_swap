#include "push_swap.h"

static void init_moves(t_stack **a, t_stack **b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a)
	{
		tmp_a->moves = 0;
		tmp_a = tmp_a->next;
	}
	while (tmp_b)
	{
		tmp_b->moves = 0;
		tmp_b->best_to_move_to_a = 0;
		tmp_b = tmp_b->next;
	}
}

void sort_a(t_stack **stack_a, t_moves *mv)
{
	t_stack *tmp;
	int min;

	tmp = *stack_a;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	while ((*stack_a)->index != min)
	{
		rotate(stack_a);
		mv->count_moves++;
		write (1, "ra\n", 3);
	}
}

static void starting_to_push(t_stack **stack_a)
{
	t_stack *stack_b;
	t_count count;
	t_moves moves;

	stack_b = NULL;
	count.count_false = 0;
	moves.count_moves = 0;
	check_if_stack_is_sorted(stack_a);
	printf("all good\n");
	indexation(stack_a);
	markups(stack_a, &count); //first find best mark_head
	stack_b = from_a_to_b(stack_a, &stack_b, &count, &moves);
	//need to check if stack_b is empty, so then we will just sort stack_a using (sort_a) func
	if (!stack_b)
	{
		sort_a(stack_a, &moves);
		while (*stack_a)
		{
			printf("%d\n", (*stack_a)->number);
			*stack_a = (*stack_a)->next;
		}
		exit(0);
	}
	init_moves(stack_a, &stack_b);
	printf("All good after init_moves\n");
	sort_a(stack_a, &moves);
	from_b_to_a(&stack_b, stack_a, &moves);
	/* 	while (stack_b)
	{
		printf("number is %d\n", stack_b->number);
		stack_b = stack_b->next;
	} */
}

int main(int argc, char **argv)
{
	t_stack *begin_list_a;

	if (argc < 3)
		exit(0);
	check_input(argv);
	begin_list_a = NULL;
	filling_stack_a(argv, &begin_list_a);
	starting_to_push(&begin_list_a);
	free_memory_lst(begin_list_a);
	//printf("No sega\n");
	return (0);
}