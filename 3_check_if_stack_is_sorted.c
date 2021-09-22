#include "push_swap.h"

void	check_if_stack_is_sorted(t_stack **begin)
{
	t_stack	*prev;
	t_stack	*nex;

	prev = *begin;
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