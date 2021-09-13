#include "push_swap.h"

static void	filling_stack_a(t_stacks *stack)
{
	int	i;

	i = -1;
	while(stack->stack_a[++i])
		stack->stack_a[i] = 0;
}

static void	starting_to_push(int argc, t_stacks *stack)
{
	sort_stack(argc, stack);
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 1)
	{
		write (1, "\n", 1);
		exit (0);
	}
	else if (argc < 4 && argc != 1)
		error_case("Error\nWrong input.\n");
	filling_stack_a(&stack);
	check_input(argv);
	adding_digits_to_stack(argv, &stack);
	starting_to_push(argc - 1, &stack);
	return (0);
}