#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*begin_list_a;
	char	**array;
	int		i;

	i = 1;
	begin_list_a = NULL;
	if (argc == 1)
		exit(0);
	while (argv[i])
	{
		array = parsing_one_str(argv[1]);
		check_input(array);
		begin_list_a = filling_stack_a(array, &begin_list_a);
		i++;
	}	
	starting_to_push(&begin_list_a);
	free_memory_lst(begin_list_a);
	exit (0);
	/* for (int j = 0; array[j]; j++)
    	printf("%s\n", array[j]); */
}