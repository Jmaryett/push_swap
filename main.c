#include "push_swap.h"

static void	starting_to_push(t_stack_a **begin)
{
	check_if_stack_is_sorted(*begin);
	indexation(begin);
	markups(begin);
}

int	main(int argc, char **argv)
{
	t_stack_a *begin_list_a;
	
	if (argc < 3)
		exit (0);
	check_input(argv);
	begin_list_a = NULL;
	filling_stack_a(argv, &begin_list_a);
 /* 	while (begin_list_a) //check if stack is filled (remove later)
	{
		printf("%d\n", begin_list_a->number);
		begin_list_a = begin_list_a->next;
	} */
	starting_to_push(&begin_list_a);
/* 	while (begin_list_a)
	{
		printf("number = %d, it's index = %d\n", begin_list_a->number, begin_list_a->index);
		begin_list_a = begin_list_a->next;
	} */
	free_memory_lst(begin_list_a);
	printf("No sega\n");
	return (0);
}