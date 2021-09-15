#include "push_swap.h"

void	check_if_stack_is_sorted(t_stack_a *begin)
{
	t_stack_a	*prev;
	t_stack_a	*nex;

	prev = NULL;
	nex = NULL;
	prev = begin;
	nex = prev->next;
	while (nex)
	{
		if (nex->number > prev->number)
		{
			prev = prev->next;
			nex = prev->next;
		}
		else
		{
			//printf ("Stack is not sorted\n");
			return ;
		}
	}
	//printf ("Stack is sorted\n");
	exit (0);
}