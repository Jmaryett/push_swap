#include "push_swap.h"

static void	starting_to_push(t_stack **begin)
{
	t_stack	*stack_b;
	t_count	count;

	count.count_keep = 0;
	check_if_stack_is_sorted(begin);
	printf ("all good\n");
	indexation(begin);
	stack_b = differ_stacks(begin, &count);
	while (stack_b)
	{
		printf("number is %d\n", stack_b->number);
		stack_b = stack_b->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*begin_list_a;
	
	if (argc < 3)
		exit (0);
	check_input(argv);
	begin_list_a = NULL;
	filling_stack_a(argv, &begin_list_a);
	starting_to_push(&begin_list_a);
	free_memory_lst(begin_list_a);
	//printf("No sega\n");
	return (0);
}